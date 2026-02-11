# mycp — A Minimal File Copy Utility in C

`mycp` is a minimal reimplementation of the Unix `cp` command, written in C using
low-level **POSIX system calls**.

This project is intentionally small and focused.  
The goal is **learning how files, memory, and the OS interact**, not building a full-featured tool.

---

## 1. What this program does

The program copies the contents of one file to another.

Usage:
```bash
./mycp <source_file> <destination_file>
