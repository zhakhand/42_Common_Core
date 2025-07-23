#!/bin/bash

if [ ! -f wp-config.php ]; then
    wp core config --dbname="${DB_NAME}" \
        --dbuser="${DB_USER}" \
        --dbpass="${DB_USERPWD}" \
        --dbhost="mariadb" \
        --path="/var/www/html" \
        --allow-root
fi

if wp core is-installed --path="/var/www/html" --allow-root; then
    echo "Wordpress is installed"
else
    echo "Setting up Wordpress"
    wp core install --url="https://dzhakhan.42.fr" \
        --title="INCEPTION" \
        --admin_user="${WP_ROOT}" \
        --admin_password="${WP_ROOTPWD}" \
        --admin_email="${WP_ROOT}@42.fr" \
        --skip-email \
        --path="/var/www/html" \
        --allow-root
    wp user create "${WP_USER}" "${WP_USER}@42.fr" \
        --role=author \
        --user_pass="${WP_USERPASS}" \
        --path="/var/www/html" \
        --allow-root
fi

exec php-fpm7.4 -F