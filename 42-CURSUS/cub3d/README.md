# cub3d

`cub3d` is a **raycasting 3D engine** written in **C** using **MiniLibX**, inspired by early Wolfenstein-style rendering. The project focuses on **graphics programming, parsing, event handling, and real-time movement** under low-level constraints.

## What it includes

From the repository structure, the project implements:

- parsing of `.cub` scene files
- texture and color validation
- map construction and validation
- player initialization and orientation
- real-time movement and rotation
- raycasting-based wall rendering
- texture sampling
- image-buffer drawing
- minimap rendering in bonus mode

The code is organized into parsing, rendering, and movement layers, which keeps the engine easier to reason about than a single-file prototype.

## Project structure

```text
cub3d/
├── includes/              # shared engine structures and declarations
├── maps/                  # example .cub maps
├── src/
│   ├── movement/          # player movement and rotation
│   ├── render/            # raycasting, textures, image drawing, minimap
│   └── parsing*.c         # map and texture parsing / validation
├── textures/              # texture assets
├── get_next_line/
├── printf/
└── mmllxx/                # MiniLibX
```

## Build

The current Makefile targets Linux/X11 and builds MiniLibX locally.

```bash
make
```

Bonus mode is enabled through:

```bash
make bonus
```

## Run

```bash
./cub3d maps/asandova.cub
```

You can also try other maps from `maps/` or `maps3/`.

## Why it is technically relevant

`cub3d` is valuable because it forces you to build a small real-time engine from first principles:

- parse and validate custom input formats
- convert a 2D map into a navigable 3D projection
- cast one ray per screen column
- compute wall distance, side hits, and texture coordinates
- update movement and rendering continuously inside an event loop

It is a strong low-level graphics project and a good demonstration of how much can be built with **C, math, and direct pixel-buffer manipulation**.
