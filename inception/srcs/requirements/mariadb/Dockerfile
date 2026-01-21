# The Linux version we use as a base for creating the image
FROM debian:bookworm

# Update the package manager
# Install mariadb server and client (with non-interactive options)
# Clean cache
RUN apt-get update && \
    DEBIAN_FRONTEND=noninteractive apt-get install -y mariadb-server mariadb-client && \
    apt-get clean && rm -rf /var/lib/apt/lists/*

# We copy the init file into the container and give executing permissions
COPY tools/init.sh /init.sh
RUN chmod +x /init.sh

# We initialize the container with the init file
ENTRYPOINT ["/init.sh"]
