# 42 Madrid Common Core

This repository collects the main projects I completed during the **42 Madrid Fundación Telefónica** common core: a project-based engineering track focused on **C, Unix systems, debugging, concurrency, networking, graphics, and containerized infrastructure**.

Rather than representing a single application, this repo shows a progression:

- from low-level C fundamentals and custom libraries
- to process and pipe orchestration
- to graphical rendering and event loops
- to multi-client socket servers
- to Docker-based service composition

## Highlighted projects

### [minishell](./minishell)

A small Unix shell written in C with:

- command parsing
- environment expansion
- builtins
- pipes
- redirections
- heredoc handling
- signal-aware execution

### [cub3d](./cub3d)

A Wolfenstein-style raycasting engine in C using MiniLibX, including:

- `.cub` map parsing
- texture loading
- real-time rendering
- player movement and rotation
- minimap support in bonus mode

### [ft_irc](./ft_irc)

A multi-client IRC server in **C++98** built around:

- sockets
- `poll()`
- channel management
- authentication
- core IRC commands such as `PASS`, `NICK`, `USER`, `JOIN`, `PRIVMSG`, `TOPIC`, `MODE`, `KICK`, and `INVITE`

### [inception](./inception)

A Docker-based infrastructure project assembling:

- NGINX
- WordPress
- MariaDB
- TLS termination
- persistent bind-mounted data volumes

### [ft_transcendence](https://github.com/jaimeol/ft_transcendence)

A full-stack 42 final project developed as a team build, combining:

- Fastify backend services
- TypeScript frontend
- SQLite persistence
- sessions, WebSockets, and real-time chat
- Pong, Tic-Tac-Toe, friends, and tournament flows

## Broader repository map

Beyond the highlighted projects, the repository also includes work such as:

- [`Libft`](./Libft)
- [`get_next_line`](./get_next_line)
- [`printf`](./printf)
- [`pipex`](./pipex)
- [`push_swap`](./push_swap)
- [`so_long`](./so_long)
- [`philosophers`](./philosophers)
- [`CPP`](./CPP)

## Why this repo matters

The value of the common core is not any one deliverable in isolation. It is the accumulated engineering formation:

- building under strict constraints
- debugging deeply instead of relying on frameworks
- learning how processes, memory, files, sockets, and containers actually behave
- shipping progressively more complex systems with limited abstractions

This repository is best read as a **long-horizon systems engineering track**, with each project documenting a different layer of that progression.
