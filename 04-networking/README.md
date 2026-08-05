# 04 — Networking with Sockets

Sockets are just file descriptors you can read from and write to, which is why
this module comes after module 03.

## Folders

| Folder | What goes in it |
| --- | --- |
| `tcp-sockets/` | `socket`/`bind`/`listen`/`accept`/`connect`, echo server, multi-client server |
| `udp-sockets/` | `sendto`/`recvfrom`, connectionless messaging |
| `http-basics/` | Parsing a raw HTTP request, serving a static file, a tiny web server |

## Concepts to cover along the way

- Byte order: `htons`, `htonl`, `ntohs`, `ntohl`
- Blocking vs non-blocking sockets
- Handling many clients: `fork` per client, threads, then `select`/`poll`/`epoll`
- Partial reads and writes — `read()` returning fewer bytes than you asked for is
  normal, not an error

## Testing your servers

```bash
nc localhost 8080          # talk to your server by hand
curl -v localhost 8080     # for the HTTP work
```

## Build

```bash
make FILE=04-networking/tcp-sockets/echo_server.c run
```
