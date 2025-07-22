#!/bin/bash
set -e

if [ ! -f /var/www/html/wp-config-sample.php ]; then
    echo "Wordpress is not installed..."
    wget https://wordpress.org/latest.tar.gz
    tar -xzf latest.tar.gz --strip-components=1
    rm latest.tar.gz
    chown -R www-data:www-data /var/www/html
    chmod -R 755 /var/www/html
fi

if [ ! -f wp-config.php ]; then
    echo "trying to log in"
    wp core config --dbname="${DB_NAME}" \
        --dbuser="${DB_USER}" \
        --dbpass="${DB_USERPWD}" \
        --dbhost="mariadb" \
        --path="/var/www/html" \
        --allow-root
fi

if wp core is-installed --path="/var/www/html" --allow-root; then
    echo "Wordpress is here"
else
    echo "I am here"
    wp core install --url="https://dzhakhan.42.fr" \
        --title="INCEPTION" \
        --admin_user="${WP_ROOT}" \
        --admin_password="${WP_ROOTPWD}" \
        --admin_email="${WP_ROOT}@42.fr" \
        --skip-email \
        --path="/var/www/html" \
        --allow-root
fi

mkdir -p /run/php

exec php-fpm7.4 -F