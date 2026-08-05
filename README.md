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

Every module folder has its own `README.md` explaining what belongs in it and
the order to work through it.

## Learning path

| # | Module | Focus | Depends on |
| --- | --- | --- | --- |
| 01 | [C Fundamentals](01-c-fundamentals/) | Pointers and memory until they are boring | — |
| 02 | [Data Structures](02-data-structures/) | Pointer practice with a purpose | 01 |
| 03 | [Systems Programming](03-systems-programming/) | Talking to the kernel directly | 01 |
| 04 | [Networking](04-networking/) | Sockets are just file descriptors | 03 |
| 05 | [Embedded C](05-embedded-c/) | C with no OS underneath it | 01 |
| 06 | [Architecture & Tooling](06-architecture-and-tooling/) | What the compiler produced, and why it broke | 01 |
| 07 | [Security & CTF](07-security-and-ctf/) | Why memory bugs are exploitable | 01, 03 |

Modules 01 → 03 are the spine; do them in order. After 03, module 04, 05 and 07
can be taken in whatever order interests you. Module 06 is best used
continuously, whenever something needs inspecting.

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

## How I work through this

1. Read or write the note in `notes/`.
2. Write the code in the matching module folder — by hand, not copied.
3. Break it deliberately, then use `gdb`, `strace` or `valgrind` to see why.
4. Record anything that surprised me back in the note.

## Requirements

```bash
sudo apt install build-essential gdb valgrind strace ltrace binutils
```

Embedded work on real hardware additionally needs a cross toolchain such as
`gcc-arm-none-eabi`.
