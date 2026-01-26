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
    && apt-get clean

# Create root directory for Wordpress
RUN mkdir -p /var/www/html

# Download last wordpress version
# Unzip Wordpress into our Wordpress root directory (directly, by deleting wordpress/ subdirectory)
# Remove the downloaded zip
RUN curl -o /tmp/wordpress.tar.gz https://wordpress.org/latest.tar.gz && \
    tar -xzf /tmp/wordpress.tar.gz -C /var/www/html --strip-components=1 && \
    rm /tmp/wordpress.tar.gz

# Give ownership to www-data user
RUN chown -R www-data:www-data /var/www/html

# Run php interpreter in PID 1
CMD ["php-fpm8.2", "-F"]
