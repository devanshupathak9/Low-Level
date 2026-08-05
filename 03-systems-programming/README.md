# 03 — Systems Programming (Linux / POSIX)

Where you stop using the C standard library and start talking to the kernel
directly. This is the module that turns "I know C" into "I know how a computer
actually runs a program".

Theory notes: [`notes/syscalls.md`](../notes/syscalls.md)

## Folders

| Folder | What goes in it |
| --- | --- |
| `syscalls/` | What a syscall is, user mode vs kernel mode, `strace` experiments |
| `file-descriptors/` | `open`/`read`/`write`/`close`/`lseek`, `dup`/`dup2`, stdin/stdout/stderr |
| `processes/` | `fork`, `exec*`, `wait`/`waitpid`, exit codes, zombies and orphans |
| `signals/` | `signal`/`sigaction`, `kill`, `SIGINT`/`SIGCHLD`, handlers |
| `threads/` | `pthread_create`/`join`, mutexes, condition variables, race conditions |
| `ipc/` | Pipes, named pipes (FIFOs), shared memory, message queues |
| `virtual-memory/` | `mmap`, page faults, `brk`/`sbrk`, writing a toy allocator |

## Order to work through it

`syscalls` → `file-descriptors` → `processes` → `signals` → `ipc` → `threads` → `virtual-memory`

## Tools you should be using here

```bash
strace ./program      # every syscall the program makes
ltrace ./program      # library calls
man 2 open            # section 2 of man = syscalls
man 3 printf          # section 3 = library functions
```

## Build

```bash
make FILE=03-systems-programming/processes/fork_demo.c run
```
