# inception

`inception` is a **containerized infrastructure project** built around **Docker Compose**, with the objective of assembling a small but realistic multi-service web stack from scratch.

In its current form, the project composes:

- **NGINX** as the public-facing reverse proxy
- **WordPress** as the application layer
- **MariaDB** as the database backend
- TLS-enabled traffic on port `443`
- persistent bind-mounted storage for both database and website files

## Architecture

The Docker Compose setup in [`srcs/docker-compose.yml`](./srcs/docker-compose.yml) defines three isolated services:

- `nginx`
- `wordpress`
- `mariadb`

It also separates network concerns into:

- a `frontend` network
- a `backend` network

Persistent data is stored through bind-mounted volumes rooted at:

- `/home/asandova/data/db`
- `/home/asandova/data/website-files`

## Repository structure

```text
inception/
├── srcs/
│   ├── docker-compose.yml
│   ├── .env
│   ├── host_config/
│   └── requirements/
│       ├── mariadb/
│       ├── nginx/
│       └── wordpress/
└── Makefile
```

## Build and run

The Makefile creates the required host directories and brings the stack up.

```bash
make
```

Useful commands:

```bash
make clean
make fclean
make re
make exec_nginx
make exec_wordpress
make exec_mariadb
```

## Configuration notes

- Environment values are loaded from `srcs/.env`.
- The compose file maps `443:443`, so HTTPS traffic is terminated by NGINX.
- Extra host mapping is used so `$DOMAIN_NAME` resolves locally to `127.0.0.1`.

## Why it is technically relevant

`inception` is less about application logic and more about understanding **deployment plumbing**:

- service boundaries
- startup dependencies
- persistent volumes
- environment-driven configuration
- reverse proxying
- TLS termination

It is a good infrastructure-oriented project because it moves beyond writing code and into **packaging, composing, and operating a small web stack**.
