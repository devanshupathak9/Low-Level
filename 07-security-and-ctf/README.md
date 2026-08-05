# 07 — Security and CTF

Low-level security is mostly the consequence of everything in modules 01–03:
memory has no built-in bounds, so mistakes become exploitable.

Everything here is for **your own deliberately vulnerable programs and CTF
challenges you are allowed to play**. Nothing in this folder is aimed at systems
you do not own.

## Folders

| Folder | What goes in it |
| --- | --- |
| `buffer-overflow/` | Stack layout, overwriting locals, return addresses, why `gets`/`strcpy` are unsafe |
| `format-string/` | `printf(user_input)` bugs, `%x`/`%n`, reading the stack |
| `reverse-engineering/` | Reading binaries with `objdump`/`ghidra`/`radare2`, patching, crackmes |
| `writeups/` | Your notes on solved challenges — one markdown file per challenge |

## Compiling vulnerable test programs

Modern compilers defend against these by default, so turn the protections off
while you are learning what they protect against:

```bash
gcc -fno-stack-protector -z execstack -no-pie -g vuln.c -o vuln
```

Also disable ASLR for a local session only:

```bash
setarch $(uname -m) -R ./vuln
```

## Writeup template

```markdown
# <challenge name>  (<platform> — <category>, <points>)
## Recon
## Vulnerability
## Exploit
## Flag
## What I learned
```
