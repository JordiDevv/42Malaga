#!/bin/bash

# If any process returns a non-zero value, the script stops
set -e

# Read the password hidden in the secret file
DB_USER_PASS=$(cat $WP_DB_USER_PASS)

# We check if Wordpress has been already configurated
if [ ! -f /var/www/html/wp-config.php ]; then

# ---------------------- SET THE CONFIG FILE FOR OUR WORDPRESS -----------------------------

    echo "Configuring WordPress..."

    cp /var/www/html/wp-config-sample.php /var/www/html/wp-config.php

    sed -i "s/database_name_here/${WP_DB}/" /var/www/html/wp-config.php
    sed -i "s/username_here/${WP_DB_USER}/" /var/www/html/wp-config.php
    sed -i "s/password_here/${DB_USER_PASS}/" /var/www/html/wp-config.php
    sed -i "s/localhost/${WP_DB_HOST}/" /var/www/html/wp-config.php

# -------------------------------------------------------------------------------------------

fi

# Run the php interpeter in PID 1
exec php-fpm8.2 -F
