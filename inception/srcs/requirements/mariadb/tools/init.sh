#!/bin/bash
set -e

ROOT_PASS=$(cat $WP_DB_ROOT_PASS)
DB_USER_PASS=$(cat $WP_DB_USER_PASS)

mysqld_safe --skip-networking & pid="$!"

until mysqladmin ping >/dev/null 2>&1; do
    sleep 1
done

mysql <<EOF 
ALTER USER 'root'@'localhost' IDENTIFIED WITH mysql_native_password BY '$ROOT_PASS'; FLUSH PRIVILEGES;
CREATE DATABASE IF NOT EXISTS $WP_DB;
CREATE USER IF NOT EXISTS '$WP_DB_USER'@'%' IDENTIFIED BY '$DB_USER_PASS';
GRANT ALL PRIVILEGES ON $WP_DB.* TO '$WP_DB_USER'@'%';
FLUSH PRIVILEGES;
EOF

mysqladmin shutdown

wait "$pid"

exec mysqld_safe
