FROM debian:bullseye

# Install nginx and openssl
RUN apt-get update && apt-get install -y \
    nginx \
    openssl \
    && rm -rf /var/lib/apt/lists/*

# Create directory for SSL certificates
RUN mkdir -p /etc/nginx/ssl

# Generate self-signed SSL certificate
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
    -keyout /etc/nginx/ssl/nginx.key \
    -out /etc/nginx/ssl/nginx.crt \
    -subj "/C=AT/ST=Vienna/L=Vienna/O=42Vienna/CN=dzhakhan.42.fr"

# Remove default nginx configuration
RUN rm -f /etc/nginx/sites-enabled/default

# Copy custom nginx configuration
COPY conf/nginx.conf /etc/nginx/nginx.conf
COPY conf/wordpress.conf /etc/nginx/sites-available/wordpress.conf

# Enable the wordpress site
RUN ln -s /etc/nginx/sites-available/wordpress.conf /etc/nginx/sites-enabled/

# Create directory for WordPress files
RUN mkdir -p /var/www/html

# Set proper permissions
RUN chown -R www-data:www-data /var/www/html

# Expose port 443 for HTTPS
EXPOSE 443

# Start nginx in foreground
CMD ["nginx", "-g", "daemon off;"]