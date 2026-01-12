#!/bin/bash

# We ensure ownership for the mysql user and the temporary directory for mysql daemon
chown -R mysql:mysql /var/lib/mysql
mkdir -p /run/mysqld
chown -R mysql:mysql /run/mysqld

# Some vars for the content in secrets
ROOT_PASS=$(cat $WP_DB_ROOT_PASS)
DB_USER_PASS=$(cat $WP_DB_USER_PASS)

# We check if MariaDB was initialized before
if [ ! -f "/var/lib/mysql/.initialized" ]; then

# ------------- INITIALIZE THE TEMPORARY SERVER AND WAIT FOR THE SOCKET --------------------

    touch /var/lib/mysql/.initialized
    mariadb-install-db --user=mysql --datadir=/var/lib/mysql

    /usr/sbin/mariadbd --user=mysql --datadir=/var/lib/mysql --skip-networking &
    pid="$!"

    echo -e "Initializing MariaDB server with PID $pid...\n"
    i=0
    while ! [ -S /run/mysqld/mysqld.sock ]; do
        sleep 1
        ((i++))
        if [ "$i" -gt 30 ]; then
            echo -e "Error initializing the MariaDB server. Aborting...\n"
            exit 1
        fi
    done

# -------------------------------------------------------------------------------------------

# -------------- CREATE DB, CONFIGURE USERS AND SHUT DOWN THE TEMPORARY SERVER --------------

    echo -e "Running initial configuration for the wp db...\n"
    mariadb -u root <<-EOF
        ALTER USER 'root'@'localhost' IDENTIFIED BY '${ROOT_PASS}';
        CREATE DATABASE IF NOT EXISTS ${WP_DB};
        CREATE USER IF NOT EXISTS '${WP_DB_USER}'@'%' IDENTIFIED BY '${DB_USER_PASS}';
        GRANT ALL PRIVILEGES ON ${WP_DB}.* TO '${WP_DB_USER}'@'%';
	EOF

    echo -e "Shutting down the temporary server...\n"
    mariadb-admin -u root -p"${ROOT_PASS}" shutdown

    wait "$pid"

# -------------------------------------------------------------------------------------------

fi

echo -e "Starting MariaDB server in PID 1...\n"
# Now we execute the server as the main process, in PID 1
exec /usr/sbin/mariadbd --user=mysql --datadir=/var/lib/mysql --bind-address=0.0.0.0
