#!/bin/bash
while ! mysqladmin ping -h mariadb -u${DB_USER} -p${DB_USERPW} --silent; do
    sleep 2
done

if [ ! -f wp-config.php ]; then
    wp core download --allow-root
    wp config create \
        --dbname=${DB_NAME} \
        --dbuser=${DB_USER} \
        --dbpass=${DB_USERPW} \
        --dbhost=mariadb \
        --allow-root

    wp core install \
        --url=https://dzhakhan.42.fr \
        --title="Inception" \
        --admin_user=${WP_ROOT} \
        --admin_password=${WP_ROOTPWD} \
        --admin_email="${WP_ROOT}@student.42vienna.com" \
        --skip-email \
        --allow-root

    wp user create \
        ${WP_USER} \
        "${WP_USER}@42.fr" \
        --user_pass=${WP_USERPASS} \
        --role=author \
        --allow-root

    chown -R www-data:www-data /var/www/html
fi

mkdir -p /run/php
exec php-fpm7.4 -F