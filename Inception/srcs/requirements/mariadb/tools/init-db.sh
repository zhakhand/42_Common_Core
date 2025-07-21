#!/bin/bash
# init-db.sh

set -e

# Function to wait for MariaDB to be ready
wait_for_mysql() {
    echo "Waiting for MariaDB to be ready..."
    while ! mysqladmin ping -h localhost --silent; do
        sleep 1
    done
    echo "MariaDB is ready!"
}

# Initialize database if not already initialized
if [ ! -d "/var/lib/mysql/mysql" ]; then
    echo "Initializing MariaDB data directory..."
    mysql_install_db --user=mysql --datadir=/var/lib/mysql
    
    # Start MariaDB in background
    mysqld --user=mysql --console &
    MYSQL_PID=$!
    
    # Wait for MariaDB to start
    wait_for_mysql
    
    # Set root password
    mysql -u root <<EOF
ALTER USER 'root'@'localhost' IDENTIFIED BY '${DB_ROOT_PW}';
CREATE DATABASE IF NOT EXISTS ${DB_NAME};
CREATE USER IF NOT EXISTS '${DB_USER}'@'%' IDENTIFIED BY '${DB_USERPW}';
GRANT ALL PRIVILEGES ON ${DB_NAME}.* TO '${DB_USER}'@'%';
FLUSH PRIVILEGES;
EOF
    
    # Stop temporary MariaDB instance
    kill $MYSQL_PID
    wait $MYSQL_PID
    
    echo "MariaDB initialization complete!"
else
    echo "MariaDB data directory already exists, skipping initialization."
fi

# Execute the CMD
exec "$@"