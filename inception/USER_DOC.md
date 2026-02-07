# User Documentation — Inception

This document is intended for **end users** and **administrators**. Its purpose is to explain, in clear and simple terms, how to use and verify the correct operation of the **Inception** project.

---

## 🧩 Services provided by the stack

The Inception project deploys a complete web infrastructure based on Docker containers. The stack includes the following services:

* **NGINX**
  Web server that acts as the entry point to the application. It handles HTTPS connections using TLS/SSL and routes traffic to the appropriate service.

* **WordPress**
  Web application that provides the main website. It runs with PHP-FPM and relies on the database to store content and configuration.

* **MariaDB**
  Relational database management system used by WordPress to store users, posts, and settings.

Each service runs in its own container and communicates with the others through a private Docker network.

---

## ▶️ Starting and stopping the project

### Starting the project

From the root of the repository, run:

```bash
make
```

This command:

* Creates the required directories for persistent data.
* Builds the Docker images.
* Starts all services.

### Stopping the project

To stop the services without deleting data:

```bash
make down
```

To stop the services and remove Docker volumes:

```bash
make clean
```

---

## 🌐 Accessing the website and administration panel

### Accessing the website

Once the project is running, the website can be accessed from a browser at:

```text
https://<configured-domain>
```

The domain name is defined in the `.env` file.

### Accessing the WordPress administration panel

The administration panel is available at:

```text
https://<configured-domain>/wp-admin
```

From this panel, an administrator can:

* Manage content (pages, posts, media).
* Manage users and roles.
* Configure the website.

---

## 🔐 Credentials management and location

Project credentials are not hardcoded inside the containers.

All sensitive information is defined indirectly in the following file:

```text
srcs/.env
```

This file **does not store passwords directly**. Instead, it defines the **paths to files located in the `secrets/` directory**.

Each of these files contains a specific credential (for example, database passwords or the WordPress administrator password). The containers read these files at runtime in order to retrieve the required credentials.

This approach allows:

* Separation of configuration and secrets.
* Avoiding exposure of passwords in environment variables or Dockerfiles.
* Easier credential rotation without rebuilding images.

⚠️ **Note:** both the `.env` file and the `secrets/` directory must be kept private and must not be pushed to public repositories.

---

## ✅ Checking that services are running correctly

An administrator can verify that services are running properly in several ways.

### Viewing running containers

```bash
docker ps
```

This command should display containers for:

* NGINX
* WordPress
* MariaDB

### Checking service logs

```bash
docker logs <container-name>
```

Logs help identify startup errors or configuration issues.

### Browser-based verification

* Accessing the domain confirms that **NGINX** and **WordPress** are running correctly.
* Accessing the `/wp-admin` panel confirms proper communication with **MariaDB**.

---

## 🧠 Final notes

* All services start automatically when the project is launched.
* Data persists across restarts thanks to Docker volumes.
* In case of issues, checking container logs is recommended.

---

This document provides all the necessary information to use and administer the Inception project without requiring deep Docker knowledge.
