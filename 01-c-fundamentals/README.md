# 01 — C Fundamentals

The language itself. Everything later in this repo assumes you are comfortable
with what lives here, so don't rush past it.

Theory notes: [`notes/c-basics.md`](../notes/c-basics.md),
[`notes/memory-layout.md`](../notes/memory-layout.md)

## Folders

| Folder | What goes in it |
| --- | --- |
| `basics/` | Hello world, variables, types, control flow, functions |
| `pointers/` | Address-of, dereference, pointer arithmetic, pointer-to-pointer, function pointers |
| `arrays-and-strings/` | Arrays vs pointers, `char*` vs `char[]`, `string.h`, writing your own `strlen`/`strcpy` |
| `structs-and-unions/` | `struct`, `union`, `enum`, `typedef`, padding and alignment |
| `memory-and-allocation/` | Stack vs heap, `malloc`/`calloc`/`realloc`/`free`, leaks, dangling pointers |
| `file-io/` | `fopen`/`fread`/`fwrite`/`fseek` — the C standard library layer (the raw syscall layer is module 03) |
| `preprocessor-and-build/` | `#define`, macros, header guards, multi-file programs, your first Makefile |

## Order to work through it

1. `basics/`
2. `pointers/` — the single most important folder in this module
3. `arrays-and-strings/`
4. `structs-and-unions/`
5. `memory-and-allocation/`
6. `file-io/`
7. `preprocessor-and-build/`

## Build

```bash
make FILE=01-c-fundamentals/pointers/pointers.c run
```
