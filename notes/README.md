# Notes

The theory side of this repo. Code lives in the numbered module folders; the
explanations live here.

## Current notes

| Note | Covers | Related module |
| --- | --- | --- |
| [`c-basics.md`](c-basics.md) | Headers, pointers, `typedef`, structs, the core language | 01 |
| [`memory-layout.md`](memory-layout.md) | Text, data, BSS, heap and stack segments | 01, 03 |
| [`syscalls.md`](syscalls.md) | Kernel vs user mode, file descriptors, how `open`/`read`/`write` work | 03 |

## Notes worth writing as you go

- `compilation-pipeline.md` — preprocess → compile → assemble → link
- `stack-frames.md` — how a function call is laid out in memory
- `undefined-behaviour.md` — the traps that bite silently
- `processes-and-signals.md`
- `sockets.md`
- `embedded-vs-hosted-c.md` — what changes when there is no OS

## How to write these

Write the note after you have run the code, not before. A note is worth keeping
if it contains something that surprised you — a diagram, a gotcha, output you
did not expect. Link back to the file that demonstrates it, for example
`../03-systems-programming/file-descriptors/open_read_write.c`.
