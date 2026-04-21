# minishell

`minishell` is a small Unix shell written in **C**, built as part of the 42 common core to explore **process execution, parsing, pipes, redirections, environment handling, and signals**.

The goal is not to clone Bash completely, but to implement a credible shell runtime with the core mechanics that make command-line execution work.

## What it implements

This project includes:

- command parsing
- environment-variable expansion
- support for single and double quotes
- builtins such as `cd`, `pwd`, `env`, `export`, `unset`, `echo`, and `exit`
- input and output redirections
- pipelines across multiple commands
- path resolution for external binaries
- signal-aware interactive execution

From the source layout, the implementation is split across parsing, execution, expansion, redirection, pipes, and builtin handling.

## Project structure

```text
minishell/
├── includes/              # shared types and function declarations
├── src/
│   ├── built_ins/         # builtin commands and helpers
│   ├── parse_command*.c   # parsing and quote handling
│   ├── executor.c         # execution flow
│   ├── redir.c            # redirections
│   ├── pipes.c            # pipeline orchestration
│   └── expand_env_vars*.c # environment expansion
├── get_next_line/
└── printf/
```

## Build

This project uses `readline`, `ncurses`, and a local `ft_printf` dependency.

```bash
make
```

## Run

```bash
./minishell
```

Once launched, you can test commands such as:

```bash
echo $HOME
pwd
ls -la | grep src
cat < infile | wc -l > outfile
```

## Why it is technically relevant

`minishell` is one of the clearest 42 projects for understanding how a Unix-like command runner is actually built:

- parsing must preserve quoting rules while still splitting commands correctly
- execution must distinguish builtins from external programs
- pipes and redirections must be wired with `fork`, `dup2`, and file descriptors
- signals and exit codes matter for interactive behavior

It is a strong systems-programming project because it forces you to connect **parser logic, process control, and shell semantics** into one coherent runtime.
