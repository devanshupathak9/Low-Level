# Projects

Bigger builds that pull several modules together. Modules 01–07 are exercises;
this folder is where you make something that actually works end to end.

Each project gets its own folder containing the source, a `Makefile`, and a
`README.md` explaining what it does and what you learned building it.

## Built

| Project | What it is | Modules used |
| --- | --- | --- |
| [`mycp/`](mycp/) | A minimal `cp` written with raw POSIX syscalls | 01, 03 |

## Ideas to build next

| Project | What you'll learn |
| --- | --- |
| `mycat` / `myls` / `mywc` | Reading files and directories via syscalls |
| `myshell` | `fork` + `exec` + `wait`, pipes, redirection, signals |
| `mymalloc` | `sbrk`/`mmap`, free lists, memory alignment |
| `http-server` | Sockets, request parsing, serving files, concurrency |
| `chat-server` | Multi-client sockets with `select`/`epoll` |
| `hexdump` | Binary file handling and formatted output |
| `led-blink` (hardware) | Registers, clocks, GPIO on a real microcontroller |

## Project README template

```markdown
# <name>
## What it does
## Usage
## How it works
## Syscalls / APIs used
## What I learned
## Known limitations
```
