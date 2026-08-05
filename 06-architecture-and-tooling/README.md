# 06 — Architecture and Tooling

What your C actually becomes, and how to inspect it when it misbehaves. Dip into
this module continuously rather than doing it in one block.

## Folders

| Folder | What goes in it |
| --- | --- |
| `assembly/` | x86-64 basics, registers, the stack, calling conventions, reading `gcc -S` output |
| `compilation-and-linking/` | Preprocess → compile → assemble → link, object files, symbols, static vs shared libraries |
| `debugging-gdb/` | Breakpoints, stepping, inspecting memory, reading a core dump, backtraces |
| `profiling-and-valgrind/` | Memory leaks, invalid reads/writes, `perf`, timing your code |

## Commands worth memorising

```bash
gcc -S file.c              # emit assembly
gcc -c file.c              # object file only
objdump -d a.out           # disassemble
nm a.out                   # list symbols
readelf -h a.out           # ELF header
ldd a.out                  # shared library dependencies

gdb ./a.out                # break main / run / bt / info locals / x/16xb ptr
valgrind --leak-check=full ./a.out
```
