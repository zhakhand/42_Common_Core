#!/bin/bash
# install-wordpress.sh

set -e

# Function to wait for MariaDB
wait_for_db() {
    echo "Waiting for MariaDB to be available..."
    while ! mysqladmin ping -h mariadb -u${DB_USER} -p${DB_USERPW} --silent; do
        echo "MariaDB is not ready yet..."
        sleep 5
    done
    echo "MariaDB is ready!"
}

# Check if WordPress is already installed
if [ ! -f /var/www/html/wp-config.php ]; then
    echo "WordPress not found. Installing..."
    
    # Wait for database to be ready
    wait_for_db
    
    # Download WordPress
    cd /var/www/html
    wp core download --allow-root
    
    # Create wp-config.php
    wp config create \
        --dbname=${DB_NAME} \
        --dbuser=${DB_USER} \
        --dbpass=${DB_USERPW} \
        --dbhost=mariadb \
        --allow-root
    
    # Install WordPress
    wp core install \
        --url=https://localhost \
        --title="WordPress Site" \
        --admin_user=${WP_ROOT} \
        --admin_password=${WP_ROOTPWD} \
        --admin_email="${WP_ROOT}@example.com" \
        --skip-email \
        --allow-root
    
    # Create additional user
    wp user create \
        ${WP_USER} \
        "${WP_USER}@example.com" \
        --user_pass=${WP_USERPASS} \
        --role=author \
        --allow-root
    
    # Set proper permissions
    chown -R www-data:www-data /var/www/html
    find /var/www/html -type d -exec chmod 755 {} \;
    find /var/www/html -type f -exec chmod 644 {} \;
    
    echo "WordPress installation complete!"
else
    echo "WordPress is already installed."
fi

# Execute the CMD
exec "$@"

Powerful, large model for complex challenges Learn more
Artifacts

Content
No content added yet
Add images, PDFs, docs, spreadsheets, and more to summarize, analyze, and query content with Claude.