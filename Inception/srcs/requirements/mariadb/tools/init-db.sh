#!/bin/bash
set -e

if [ ! -d "/var/lib/mysql/mysql" ]; then
    mysql_install_db --user=mysql --datadir=/var/lib/mysql --skip-test-db
fi

if [ ! -d "/var/lib/mysql/${DB_NAME}" ]; then
    echo "Creating database initialization file"
    cat > /init.sql <<-EOSQL
    CREATE DATABASE IF NOT EXISTS \`${DB_NAME}\`;
    CREATE USER IF NOT EXISTS '${DB_USER}'@'%' IDENTIFIED BY '${DB_USERPWD}';
    GRANT ALL PRIVILEGES ON \`${DB_NAME}\`.* TO '${DB_USER}'@'%';
    ALTER USER 'root'@'localhost' IDENTIFIED BY '${DB_ROOTPWD}';
    FLUSH PRIVILEGES;
EOSQL
    exec mysqld --user=mysql --datadir=/var/lib/mysql --init-file=/init.sql
else
    exec mysqld --user=mysql --datadir=/var/lib/mysql
fi