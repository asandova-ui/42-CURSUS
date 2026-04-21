# ft_irc

`ft_irc` is a lightweight **IRC server** written in **C++98**, built to understand **socket programming, event-driven I/O, connection lifecycle management, and protocol-oriented server design**.

The project is centered on a poll-based multi-client server rather than a single-user networking exercise.

## What it implements

From the current source tree and server handlers, the implementation includes:

- TCP server bootstrap and connection acceptance
- multi-client handling with `poll()`
- password-gated authentication flow
- nickname and user registration
- channel creation and channel membership management
- private messaging
- topic handling
- invite and kick flows
- mode handling
- disconnect and quit handling

The main entities are split into:

- `Server`
- `Client`
- `Channel`
- utility helpers for parsing and server-side flow control

## Project structure

```text
ft_irc/
├── include/
│   ├── Server.hpp
│   ├── Client.hpp
│   ├── Channel.hpp
│   └── Utils.hpp
├── src/
│   ├── Server.cpp
│   ├── Client.cpp
│   ├── Channel.cpp
│   ├── Utils.cpp
│   └── main.cpp
└── Makefile
```

## Build

```bash
make
```

## Run

```bash
./ircserv <port> <password>
```

Example:

```bash
./ircserv 6667 supersecret
```

You can then connect with an IRC client and test flows such as:

- `PASS`
- `NICK`
- `USER`
- `JOIN`
- `PRIVMSG`
- `TOPIC`
- `MODE`
- `KICK`
- `INVITE`

## Why it is technically relevant

`ft_irc` is a strong networking project because it sits at the intersection of:

- socket lifecycle management
- event-loop design
- stateful client sessions
- channel-level coordination
- protocol parsing under real-time constraints

It is a good demonstration of how to structure a **non-trivial, multi-client server** in C++98 without relying on heavy frameworks.
