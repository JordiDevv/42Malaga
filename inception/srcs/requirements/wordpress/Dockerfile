# The Linux version we use as a base for creating the image
FROM debian:bookworm

# Install php interpreter and all the utilities we need, then we clean cache
RUN apt-get update && apt-get install -y \
    php8.2 \
    php8.2-fpm \
    php8.2-mysql \
    php8.2-curl \
    php8.2-gd \
    php8.2-intl \
    php8.2-mbstring \
    php8.2-xml \
    php8.2-zip \
    curl \
    ca-certificates \
    netcat-openbsd \
    && apt-get clean

# Configure PHP-FPM to listen on TCP port 9000 instead of Unix socket
RUN sed -i 's|^listen =.*|listen = 0.0.0.0:9000|' /etc/php/8.2/fpm/pool.d/www.conf

# Create root directory for Wordpress
RUN mkdir -p /var/www/html

# Download last wordpress version
# Unzip Wordpress into the src system user directory,
#  for copying it later into our WordPress root directory
# Remove the downloaded zip
RUN curl -o /tmp/wordpress.tar.gz https://wordpress.org/latest.tar.gz && \
    tar -xzf /tmp/wordpress.tar.gz -C /usr/src && \
    rm /tmp/wordpress.tar.gz

# Install WP-CLI
# Give permissions
# Move it to bin directory to be able to use it globally
RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
    chmod +x wp-cli.phar && \
    mv wp-cli.phar /usr/local/bin/wp

# Give ownership to www-data user
RUN chown -R www-data:www-data /var/www/html

# We copy the init file into the container and give executing permissions
COPY tools/init.sh /init.sh
RUN chmod +x /init.sh

# We initialize the container with the init file
ENTRYPOINT [ "/init.sh" ]
