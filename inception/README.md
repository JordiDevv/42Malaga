*This project has been created as part of the 42 curriculum by jsanz-bo.*

# Inception

## 📌 Description

**Inception** is a project from the **42 cursus** whose goal is to gain a deep understanding of **Docker** and **service containerization**, learning how to design, build, and orchestrate a complete infrastructure without relying on preconfigured solutions.

The project uses **Docker** to isolate each service inside its own container and **Docker Compose** as the orchestration tool. Each Docker image is built from a minimal base image (such as Alpine or Debian, as allowed by the subject) using **custom Dockerfiles**, ensuring full control over the environment, dependencies, and security.

### 🧩 Included services

The infrastructure is composed of the following services:

* **NGINX**: web server acting as the entry point, configured with **TLS/SSL**.
* **WordPress**: web application running with **PHP-FPM**.
* **MariaDB**: relational database used by WordPress.

Each service runs in its own container and communicates with the others through a **private Docker network**, following the single-responsibility principle.

### 🏗️ Main design choices

* Use of **custom Dockerfiles** for each service, avoiding images that already include complete services.
* Strict separation of services into independent containers.
* Data persistence handled through **Docker volumes**.
* Centralized configuration via environment variables defined in a `.env` file.
* Dedicated Docker network for internal service communication.

### 🔍 Key comparisons

#### 🖥️ Virtual Machines vs Docker

* **Virtual Machines**: virtualize an entire operating system, resulting in higher resource consumption, longer boot times, and heavier management.
* **Docker**: virtualizes only the application and its dependencies while sharing the host kernel. This makes it lighter, faster, and more efficient, especially for microservice-based architectures.

➡️ *Docker is used in this project for its efficiency, fast deployment, and ease of orchestration.*

---

#### 🔐 Secrets vs Environment Variables

* **Environment Variables**: a simple and common way to configure applications, but less secure if credentials are exposed in files or logs.
* **Docker Secrets**: a more secure mechanism for handling sensitive information, as data is not directly exposed inside the container environment.

➡️ *This project uses environment variables as permitted by the subject, ensuring that credentials are never hardcoded inside Dockerfiles.*

---

#### 🌐 Docker Network vs Host Network

* **Host Network**: containers share the host’s network stack, reducing isolation and increasing security risks.
* **Docker Network**: provides an isolated virtual network where containers communicate using service names.

➡️ *A dedicated Docker network is used to improve isolation, security, and clarity in service communication.*

---

#### 💾 Docker Volumes vs Bind Mounts

* **Bind Mounts**: directly link host directories to containers, which can cause portability and permission issues.
* **Docker Volumes**: managed by Docker, more secure, portable, and recommended for persistent data.

➡️ *Docker volumes are used to ensure data persistence and portability.*

---

## ⚙️ Instructions

### 📋 Prerequisites

Make sure you have installed:

* Docker
* Docker Compose
* Make
* A Linux virtual machine (as required by the subject)

---

### 🧭 Installation and usage guide

#### Option 1️⃣ — Using Make (recommended)

1. Clone the repository:

   ```bash
   git clone <repository-url>
   cd inception
   ```

2. Configure environment variables:

   The project uses a `.env` file located at `srcs/.env` to define sensitive parameters (users, passwords, database names, domain, etc.).

3. Launch the project:

   ```bash
   make
   ```

   This command creates the required volumes, builds the images, and starts all services.

---

#### Option 2️⃣ — Without Make (Docker Compose)

1. Clone the repository:

   ```bash
   git clone <repository-url>
   cd inception
   ```

2. Configure environment variables:

   Ensure that the `srcs/.env` file exists and contains all required variables.

3. Manually create directories for volumes:

   ```bash
   mkdir -p /home/$USER/data/mariadb
   mkdir -p /home/$USER/data/wordpress
   ```

4. Build and start the containers:

   ```bash
   docker compose -f srcs/docker-compose.yml --env-file srcs/.env up --build
   ```

---

### 🚀 Makefile usage

The project includes a **Makefile** that simplifies full Docker environment management. Below are all available commands and their behavior.

> 📁 Persistent data is stored in:
>
> ```text
> /home/$USER/data
> ```

---

#### 🟢 `make` or `make all`

* Creates the required directories for volumes.
* Builds Docker images.
* Starts all services defined in `docker-compose.yml`.

This is the main command to start the project for the first time.

---

#### 📦 `make volumes`

* Creates local directories used for data persistence:

  * `mariadb`
  * `wordpress`

---

#### 🚀 `make up`

* Builds Docker images if needed.
* Starts all containers using Docker Compose.

Equivalent to:

```bash
docker compose up --build
```

---

#### 🛑 `make down`

* Stops all running containers.
* Keeps volumes and persistent data intact.

---

#### 🧹 `make clean`

* Stops all containers.
* Removes Docker volumes associated with the project.
* Persistent data will be deleted.

---

#### 🔥 `make fclean`

* Stops all containers.
* Removes Docker volumes.
* Deletes all Docker images built for the project.

This command leaves the Docker environment completely clean.

---

#### 💣 `make delete`

* Manually deletes all persistent data from the host system:

  * `/home/$USER/data/mariadb`
  * `/home/$USER/data/wordpress`

> ⚠️ This command uses `sudo` and irreversibly deletes data.

---

#### 🔁 `make re`

* Runs `fclean` followed by `all`.
* Fully rebuilds the project from scratch.

---

### 🌐 Access

Once started, the project is available at:

```text
https://<your-domain>
```

---

## 📚 Resources

Below are some classic and useful references related to the technologies used in this project:

* **Docker Documentation**
  Official Docker documentation. Essential for understanding images, containers, volumes, and networks.
  [https://docs.docker.com/](https://docs.docker.com/)

* **Docker Compose Documentation**
  Official guide for defining and managing multi-container applications.
  [https://docs.docker.com/compose/](https://docs.docker.com/compose/)

* **NGINX Documentation**
  Complete reference for NGINX configuration, virtual hosts, and TLS.
  [https://nginx.org/en/docs/](https://nginx.org/en/docs/)

* **MariaDB Knowledge Base**
  Official MariaDB documentation, including users, permissions, and basic configuration.
  [https://mariadb.com/kb/en/](https://mariadb.com/kb/en/)

* **WordPress Documentation**
  Information about WordPress installation, configuration, and internals.
  [https://wordpress.org/support/](https://wordpress.org/support/)

* **Docker Best Practices**
  Guidelines and articles about building secure and efficient Docker images.
  [https://docs.docker.com/develop/dev-best-practices/](https://docs.docker.com/develop/dev-best-practices/)

---

## 🧠 Notes

* No prebuilt images containing full services are used.
* Each container runs a single service.
* Credentials are never hardcoded inside Dockerfiles.
* The project complies with the rules and constraints defined in the 42 subject.

---
