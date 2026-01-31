# The Linux version we use as a base for creating the image
FROM debian:bookworm

# Update the package manager
# Install Nginx & OpenSSL
# Clean cache
RUN apt-get update && \
    apt-get install -y nginx openssl && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

# Create directoy for the certificates
# Generate certificate and key, autosigned and passing the subject information for no interaction
RUN mkdir -p /etc/nginx/ssl && \
    openssl req -x509 -nodes -days 365 \
        -subj "/C=ES/ST=Malaga/L=Malaga/O=42/OU=Inception/CN=jsanz-bo.42.fr" \
        -newkey rsa:2048 \
        -keyout /etc/nginx/ssl/nginx.key \
        -out /etc/nginx/ssl/nginx.crt

# We copy the conf files into the container
COPY conf/nginx.conf /etc/nginx/nginx.conf
COPY conf/wp_server.conf /etc/nginx/conf.d/wp_server.conf

# We run the container with the nginx process in PID 1
ENTRYPOINT ["nginx", "-g", "daemon off;"]

