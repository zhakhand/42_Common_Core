FROM debian:bullseye

# Install PHP and required extensions for WordPress
RUN apt-get update && apt-get install -y \
    php7.4 \
    php7.4-fpm \
    php7.4-mysql \
    php7.4-curl \
    php7.4-gd \
    php7.4-mbstring \
    php7.4-xml \
    php7.4-xmlrpc \
    php7.4-soap \
    php7.4-intl \
    php7.4-zip \
    php7.4-imagick \
    mariadb-client \
    wget \
    curl \
    && rm -rf /var/lib/apt/lists/*

# Install WP-CLI
RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
    && chmod +x wp-cli.phar \
    && mv wp-cli.phar /usr/local/bin/wp

# Create PHP-FPM run directory
RUN mkdir -p /run/php

# Copy PHP-FPM configuration
COPY conf/www.conf /etc/php/7.4/fpm/pool.d/www.conf

# Create web directory
RUN mkdir -p /var/www/html && \
    chown -R www-data:www-data /var/www/html

# Copy WordPress installation script
COPY scripts/install-wordpress.sh /usr/local/bin/install-wordpress.sh
RUN chmod +x /usr/local/bin/install-wordpress.sh

# Set working directory
WORKDIR /var/www/html

# Expose PHP-FPM port
EXPOSE 9000

# Run installation script and start PHP-FPM
ENTRYPOINT ["/usr/local/bin/install-wordpress.sh"]
CMD ["php-fpm7.4", "-F"]