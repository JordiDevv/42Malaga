# Developer Documentation — Inception

This document is intended for **developers** and describes how to set up, build, and manage the **Inception** project from scratch.

---

## 🧰 Setting up the environment from scratch

### Prerequisites

Before starting, make sure you have installed:

* Docker
* Docker Compose
* Make
* A Linux virtual machine (as required by the subject)

### Configuration files

* `.env`
  Located in `srcs/.env`, this file defines environment variables and paths to secrets.

* `docker-compose.yml`
  Located in `srcs/docker-compose.yml`, this file defines services, networks, and volumes.

* `secrets/`
  Directory containing files with passwords and other credentials used by the containers.

⚠️ It's important to keep both `.env` and `secrets/` private.

---

## 🚀 Building and launching the project

### Using the Makefile (recommended)

From the root of the repository:

```bash
make
```

This command:

* Creates directories for data volumes.
* Builds Docker images.
* Starts all services.

To stop the services:

```bash
make down
```

To stop the services and remove volumes:

```bash
make clean
```

To clean everything (volumes + images):

```bash
make fclean
```

### Using Docker Compose directly

1. Create directories for volumes:

```bash
mkdir -p /home/$USER/data/mariadb
mkdir -p /home/$USER/data/wordpress
```

2. Build and start the containers:

```bash
docker compose -f srcs/docker-compose.yml --env-file srcs/.env up --build
```

3. Stop the containers:

```bash
docker compose -f srcs/docker-compose.yml down
```

4. Stop and remove volumes:

```bash
docker compose -f srcs/docker-compose.yml down -v
```

---

## 🛠️ Relevant commands for management

* View running containers:

```bash
docker ps
```

* View logs of a container:

```bash
docker logs <container-name>
```

* Remove a specific container:

```bash
docker rm -f <container-name>
```

* Remove a specific volume:

```bash
docker volume rm <volume-name>
```

* Rebuild containers without deleting volumes:

```bash
docker compose -f srcs/docker-compose.yml --env-file srcs/.env up --build
```

---

## 💾 Data storage and persistence

Project data is primarily stored in **Docker volumes**:

* WordPress: `/home/$USER/data/wordpress`
* MariaDB: `/home/$USER/data/mariadb`

This setup allows:

* Data to persist across container restarts.
* Containers to be rebuilt without losing information.
* Services to remain isolated from each other and from the host.

---

This document provides the necessary information for a developer to set up, build, and manage the Inception project from scratch.
