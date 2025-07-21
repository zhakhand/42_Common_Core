FROM debian:bullseye

RUN apt-get update && apt-get install -y \
    php7.4-fpm php7.4-mysql wget && \
    rm -rf /var/lib/apt/lists*

COPY /conf/www.conf /etc/php/7.4/fpm/pool.d
COPY tools/install-wordpress.sh /install-wordpress.sh
RUN chmod +x /install-wordpress.sh

WORKDIR /var/www/html

EXPOSE 9000

ENTRYPOINT ["/install-wordpress.sh"]