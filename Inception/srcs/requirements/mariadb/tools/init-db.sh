#!/bin/bash
set -e

if [ ! -d "/var/lib/mysql/mysql" ]; then
    mysql_install_db --user=mysql --datadir=/var/lib/mysql --skip-test-db
fi

if [ ! -d "/var/lib/mysql/${DB_NAME}" ]; then
    cat > /init.sql <<-EOF
    ALTER USER 'root'@'localhost' IDENTIFIED BY '${DB_ROOTPWD}';
    CREATE DATABASE IF NOT EXISTS \`${DB_NAME}\`;
    CREATE USER IF NOT EXISTS '${DB_USER}'@'%' IDENTIFIED BY '${DB_USERPWD}';
    GRANT ALL PRIVILEGES ON \`${DB_NAME}\`.* TO '${DB_USER}'@'%';
    FLUSH PRIVILEGES;
EOF
    exec mysqld --user=mysql --datadir=/var/lib/mysql --init-file=/init.sql
else
    exec mysqld --user=mysql --datadir=/var/lib/mysql
fi