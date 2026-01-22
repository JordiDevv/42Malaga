# The Linux version we use as a base for creating the image
FROM debian:bookworm

# Update the package manager
# Install OpenSSL
# Clean cache
RUN apt-get update && \
    apt-get install -y openssl && \
    apt-get clean

# Create directoy for the certificates
# Generate certificate and key, autosigned and passing the subject information for no interaction
RUN mkdir -p /etc/nginx/certs && \
    openssl req -x509 -nodes -days 365 \
        -subj "/C=ES/ST=Malaga/L=Malaga/O=42/OU=Inception/CN=jsanz-bo.42.fr" \
        -newkey rsa:2048 \
        -keyout /etc/nginx/certs/nginx.key \
        -out /etc/nginx/certs/nginx.crt

# We copy the conf file into the container
COPY conf/nginx.conf /etc/nginx/nginx.conf

# We run the container with the nginx process in PID 1
CMD [ "nginx", "-g", "daemon off;"]
