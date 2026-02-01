#!/bin/bash

# If any process returns a non-zero value, the script stops
set -e

# Some vars for the content in secrets
ROOT_PASS=$(cat $WP_DB_ROOT_PASS)
DB_USER_PASS=$(cat $WP_DB_USER_PASS)

# We wait 'til MariaDB is ready
until mariadb -h "$WP_DB_HOST" -u root -p"$ROOT_PASS" -e "select 1;" &>/dev/null; do
    echo "Waiting MariaDB for being prepared..."
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

# -------------------------------------------------------------------------------------------

fi

# Run the php interpeter in PID 1
exec php-fpm8.2 -F
