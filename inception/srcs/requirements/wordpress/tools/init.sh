#!/bin/bash

# If any process returns a non-zero value, the script stops
set -e

# Some vars for the content in secrets
DB_USER_PASS=$(cat $WP_DB_USER_PASS)
WP_ADMIN_PASS=$(cat $WP_ADMIN_PASS)

# We wait 'til MariaDB is ready
until nc -z "$WP_DB_HOST" 3306; do
    echo "Waiting MariaDB..."
    sleep 1
done

# We check if Wordpress has been already configurated
if [ ! -f /var/www/html/wp-config.php ]; then

# ---------------------- SET THE CONFIG FILE FOR OUR WORDPRESS -----------------------------

    echo "Configuring WordPress..."

    cp -r /usr/src/wordpress/* /var/www/html/
    cp /var/www/html/wp-config-sample.php /var/www/html/wp-config.php

    sed -i "s/database_name_here/${WP_DB}/" /var/www/html/wp-config.php
    sed -i "s/username_here/${WP_DB_USER}/" /var/www/html/wp-config.php
    sed -i "s/password_here/${DB_USER_PASS}/" /var/www/html/wp-config.php
    sed -i "s/localhost/${WP_DB_HOST}/" /var/www/html/wp-config.php

    echo " Configuration successful..."

# -------------------------------------------------------------------------------------------

# ------------------------------- INSTALL WORDPRESS -----------------------------------------

    echo "Installing WordPress..."
    wp core install \
        --url="https://jsanz-bo.42.fr" \
        --title="Inception" \
        --admin_user="${WP_ADMIN}" \
        --admin_password="${WP_ADMIN_PASS}" \
        --admin_email="${WP_ADMIN_EMAIL}" \
        --path=/var/www/html \
        --allow-root

# -------------------------------------------------------------------------------------

fi

echo "Running WordPress in PID 1..."
# Run the php interpeter in PID 1
exec php-fpm8.2 -F
