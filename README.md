# low-level

My learning repo for **C, systems programming and embedded C** — theory notes,
practice code, and small projects, worked through in order.

The goal is to understand what actually happens beneath the code I write: how
memory is laid out, how a program talks to the kernel, and how C runs on
hardware with no operating system at all.

## Structure

```
low-level/
├── 01-c-fundamentals/          The language: pointers, memory, structs, file I/O
├── 02-data-structures/         Lists, stacks, trees, hash tables — built by hand
├── 03-systems-programming/     Syscalls, processes, signals, threads, IPC (Linux/POSIX)
├── 04-networking/              TCP/UDP sockets, a tiny HTTP server
├── 05-embedded-c/              Bit manipulation, registers, interrupts, UART/SPI/I2C, RTOS
├── 06-architecture-and-tooling/ Assembly, linking, gdb, valgrind
├── 07-security-and-ctf/        Memory-safety bugs, reverse engineering, CTF writeups
├── projects/                   Bigger builds that combine the modules
└── notes/                      The theory — one markdown file per topic
```


## Building and running

A single root `Makefile` compiles any file in the repo:

```bash
make FILE=01-c-fundamentals/pointers/pointers.c        # build to build/pointers
make FILE=01-c-fundamentals/pointers/pointers.c run    # build and run
make FILE=... debug                                    # build and open in gdb
make FILE=... valgrind                                 # build and run under valgrind
make clean                                             # remove build/
```

Compiled with `-Wall -Wextra -std=c11 -g`. Warnings are information — read them.

Projects with several source files carry their own `Makefile` inside their
folder.

## Requirements

```bash
sudo apt install build-essential gdb valgrind strace ltrace binutils
```
