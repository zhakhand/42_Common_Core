FROM debian:bullseye

RUN apt-get update && \
    apt-get install -y php php-fpm php-mysql wget tar less && \
    rm -rf /var/lib/apt/lists/*

RUN mkdir -p /var/www/html /run/php && \
    chown -R www-data:www-data /var/www/html && \
    chmod -R 755 /var/www/html
    
WORKDIR /var/www/html

RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
    chmod +x wp-cli.phar && \
    mv wp-cli.phar /usr/local/bin/wp

RUN cd /var/www/html && \
    wget https://wordpress.org/latest.tar.gz && \
    tar -xzf latest.tar.gz --strip-components=1 && \
    rm latest.tar.gz && \
    chown -R www-data:www-data /var/www/html

COPY conf/www.conf /etc/php/7.4/fpm/pool.d/
COPY tools/setup.sh /setup.sh
RUN chmod +x /setup.sh

EXPOSE 9000

ENTRYPOINT ["/setup.sh"]