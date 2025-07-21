#!/bin/bash
# setup.sh - With debugging

set -e

echo "Starting WordPress setup..."

# Check if wp-cli is available
if ! command -v wp &> /dev/null; then
    echo "ERROR: wp-cli is not installed!"
    echo "Installing wp-cli..."
    wget -O /usr/local/bin/wp https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
    chmod +x /usr/local/bin/wp
fi

# Test wp-cli
echo "Testing wp-cli..."
wp --info --allow-root

# Wait for database
echo "Waiting for MariaDB..."
until mysqladmin ping -h mariadb -u${DB_USER} -p${DB_USERPW} --silent; do
    echo "MariaDB is not ready yet..."
    sleep 2
done
echo "MariaDB is ready!"

cd /var/www/html

if [ ! -f wp-config.php ]; then
    echo "Installing WordPress..."
    
    # Download WordPress
    wp core download --allow-root
    
    # Create config
    wp config create \
        --dbname=${DB_NAME} \
        --dbuser=${DB_USER} \
        --dbpass=${DB_USERPW} \
        --dbhost=mariadb \
        --allow-root
    
    # Install WordPress
    wp core install \
        --url=https://dzhakhan.42.fr \
        --title="Inception" \
        --admin_user=${WP_ROOT} \
        --admin_password=${WP_ROOTPWD} \
        --admin_email="${WP_ROOT}@42.fr" \
        --skip-email \
        --allow-root
    
    # Create additional user
    wp user create \
        ${WP_USER} \
        "${WP_USER}@42.fr" \
        --user_pass=${WP_USERPASS} \
        --role=author \
        --allow-root
    
    # Set permissions
    chown -R www-data:www-data /var/www/html
    echo "WordPress installation complete!"
else
    echo "WordPress already installed."
fi

# Create PHP-FPM socket directory
mkdir -p /run/php

echo "Starting PHP-FPM..."
exec php-fpm7.4 -F