#!/bin/bash
set -e

ROOT_PASS=$(cat $MYSQL_ROOT_PASSWORD_FILE)
DB_USER_PASS=$(cat $MYSQL_DB_USER_PASS_FILE)

mysqld_safe --skip-networking & pid="$!"

until mysqladmin ping >/dev/null 2>&1; do
    sleep 1
done

mysql -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '$ROOT_PASS'; FLUSH PRIVILEGES;"

mysql -e "CREATE DATABASE IF NOT EXISTS $WP_DB;"

mysql -e "CREATE USER IF NOT EXISTS '$WP_DB_USER'@'%' IDENTIFIED BY '$DB_USER_PASS';"
mysql -e "GRANT ALL PRIVILEGES ON $WP_DB.* TO '$WP_DB_USER'@'%';"

mysql -e "FLUSH PRIVILEGES;"

mysqladmin shutdown

exec mysqld_safe
