#!/bin/bash

set -e

DB_USER_PASS=$(cat $WP_DB_USER_PASS)

if [ ! -f /var/www/html/wp-config.php ]; then
    echo "Configuring WordPress...\n"

    cp /var/www/html/wp-config-sample.php /var/www/html/wp-config.php

    sed -i "s/database_name_here/${WP_DB}/" /var/www/html/wp-config.php
    sed -i "s/username_here/${WP_DB_USER}/" /var/www/html/wp-config.php
    sed -i "s/password_here/${DB_USER_PASS}/" /var/www/html/wp-config.php
    sed -i "s/localhost/${WP_DB_HOST}/" /var/www/html/wp-config.php
fi

exec php-fpm8.2 -F
