# C Networking — Sockets, HTTP & Event Loop

A quick reference for the C networking examples: TCP client/server, HTTP server, and asynchronous event loops.

---

## 1. TCP Client ↔ Server Flow

```text
SERVER                              CLIENT

socket()                            socket()
   ↓                                   ↓
bind()                             connect()
   ↓                                   ↓
listen()                              ↓
   ↓                                  ↓
accept() ←──────────────────── connection
   ↓                                  ↓
read()        ←───────────────      write()
   ↓
write()       ───────────────→      read()
   ↓                                  ↓
close()                            close()
```

### Server

```c
socket()
   ↓
bind()
   ↓
listen()
   ↓
accept()
   ↓
read()
   ↓
write()
   ↓
close()
```

### Client

```c
socket()
   ↓
connect()
   ↓
write()
   ↓
read()
   ↓
close()
```

---

# 2. `socket()`

Creates a socket.

```c
socket(AF_INET, SOCK_STREAM, 0);
```

### Arguments

#### `AF_INET`

Address family.

```c
AF_INET
```

Means:

> Use IPv4 addresses.

Example:

```text
127.0.0.1
192.168.1.10
```

---

#### `SOCK_STREAM`

Socket type.

```c
SOCK_STREAM
```

Means:

> Create a TCP-style stream socket.

TCP provides a reliable connection between client and server.

---

#### `0`

Protocol.

```c
0
```

Means:

> Let the operating system choose the appropriate protocol for this socket type.

For:

```c
AF_INET + SOCK_STREAM
```

this normally means TCP.

---

### Return value

```c
int sock = socket(...);
```

Returns:

```text
>= 0  → socket file descriptor
< 0   → error
```

A socket is represented by a **file descriptor**.

---

# 3. `struct sockaddr_in`

Used to describe an IPv4 network address.

```c
struct sockaddr_in address;
```

Important fields:

```c
address.sin_family = AF_INET;
address.sin_addr.s_addr = INADDR_ANY;
address.sin_port = htons(8080);
```

### `sin_family`

```c
address.sin_family = AF_INET;
```

Specifies IPv4.

---

### `sin_addr`

```c
address.sin_addr.s_addr = INADDR_ANY;
```

Specifies the IP address.

`INADDR_ANY` means:

> Listen on all available network interfaces.

---

### `sin_port`

```c
address.sin_port = htons(8080);
```

Specifies the port.

Here:

```text
8080
```

---

# 4. `htons()`

```c
htons(8080);
```

Means:

> Host To Network Short.

Converts a port number from the computer's byte order to **network byte order**.

Use it for ports:

```c
htons(8080);
```

---

# 5. `bind()`

Connects a socket to a local IP address and port.

```c
bind(
    server_fd,
    (struct sockaddr *)&address,
    sizeof(address)
);
```

### Arguments

```text
server_fd
```

The socket created by `socket()`.

```text
(struct sockaddr *)&address
```

The address information.

```text
sizeof(address)
```

Size of the address structure.

### Concept

```text
socket
   ↓
bind
   ↓
IP + PORT
```

Example:

```text
0.0.0.0:8080
```

---

# 6. `listen()`

Makes a TCP socket wait for incoming connections.

```c
listen(server_fd, 5);
```

### Arguments

```text
server_fd
```

The socket to listen on.

```text
5
```

Backlog — roughly the number of pending connections that can wait to be accepted.

Flow:

```text
socket()
   ↓
bind()
   ↓
listen()
   ↓
waiting for clients
```

---

# 7. `accept()`

Accepts an incoming client connection.

```c
client_fd = accept(server_fd, NULL, NULL);
```

Important:

`accept()` returns a **new socket**.

```text
server_fd
    │
    │ listens
    ↓
accept()
    │
    └──→ client_fd
```

### Important distinction

```text
server_fd
```

Keeps listening for new clients.

```text
client_fd
```

Communicates with the connected client.

---

# 8. `connect()`

Used by the client to connect to a server.

```c
connect(
    sock,
    (struct sockaddr *)&server,
    sizeof(server)
);
```

### Arguments

```text
sock
```

Client socket.

```text
(struct sockaddr *)&server
```

Server's IP address and port.

```text
sizeof(server)
```

Size of the address structure.

Flow:

```text
Client

socket()
   ↓
connect()
   ↓
Server
```

---

# 9. `read()`

Reads data from a file descriptor.

Sockets are file descriptors, so:

```c
read(client_fd, buffer, sizeof(buffer));
```

works with sockets.

### Arguments

```text
client_fd
```

Where to read from.

```text
buffer
```

Where to store the received data.

```text
sizeof(buffer)
```

Maximum number of bytes to read.

Example:

```c
char buffer[1024];

int bytes = read(
    client_fd,
    buffer,
    sizeof(buffer)
);
```

Return value:

```text
> 0  → number of bytes received
  0  → connection closed
< 0  → error
```

---

# 10. `write()`

Sends/writes data to a file descriptor.

```c
write(
    client_fd,
    message,
    strlen(message)
);
```

### Arguments

```text
client_fd
```

Where to write.

```text
message
```

Data to send.

```text
strlen(message)
```

Number of bytes to send.

---

# 11. `close()`

Closes a file descriptor.

```c
close(client_fd);
```

For a client/server:

```text
close(client_fd);
close(server_fd);
```

After `close()`, that socket is no longer usable.

---

# 12. `inet_pton()`

Converts an IP address from text to binary form.

```c
inet_pton(
    AF_INET,
    "127.0.0.1",
    &server.sin_addr
);
```

### Arguments

```text
AF_INET
```

IPv4.

```text
"127.0.0.1"
```

IP address as text.

```text
&server.sin_addr
```

Where the converted address is stored.

---

# 13. TCP Example

### Server

```text
socket()
   ↓
bind()
   ↓
listen()
   ↓
accept()
   ↓
read()
   ↓
write()
   ↓
close()
```

### Client

```text
socket()
   ↓
connect()
   ↓
write()
   ↓
read()
   ↓
close()
```

---

# 14. HTTP Server Flow

HTTP runs **on top of TCP**.

```text
Browser
   │
   │ HTTP request
   ↓
TCP connection
   ↓
C socket
   ↓
read()
   ↓
HTTP request
   ↓
process request
   ↓
write()
   ↓
HTTP response
   ↓
Browser
```

Example request:

```text
GET / HTTP/1.1
Host: localhost:8080
```

Example response:

```text
HTTP/1.1 200 OK
Content-Type: text/html

<h1>Hello from C!</h1>
```

The C server is simply reading bytes from the TCP socket and writing HTTP bytes back.

---

# 15. HTTP Response

Basic structure:

```text
HTTP/1.1 200 OK
Header: value

Body
```

Example:

```c
char response[] =
    "HTTP/1.1 200 OK\r\n"
    "Content-Type: text/html\r\n"
    "\r\n"
    "<h1>Hello from C!</h1>";
```

`\r\n` means a line ending used by HTTP.

The empty line separates:

```text
Headers
   ↓
Body
```

---

# 16. Event Loop

A normal server can block while waiting for I/O.

An event loop instead asks:

> Which sockets are ready?

Concept:

```text
             Event Loop
                 │
        ┌────────┼────────┐
        ↓        ↓        ↓
     socket1  socket2  socket3
      ready    ready     idle
        │        │
       read     read
        │        │
       write   write
        │        │
        └────┬───┘
             ↓
        Event Loop
             ↓
          repeat
```

---

# 17. `poll()`

`poll()` waits until one or more file descriptors are ready.

```c
poll(fds, count, timeout);
```

### Arguments

```text
fds
```

Array of `struct pollfd`.

```text
count
```

Number of file descriptors.

```text
timeout
```

How long to wait in milliseconds.

Examples:

```c
-1
```

Wait forever.

```c
0
```

Don't wait.

```c
1000
```

Wait up to 1 second.

---

# 18. `struct pollfd`

Example:

```c
struct pollfd fd;

fd.fd = STDIN_FILENO;
fd.events = POLLIN;
```

### `fd`

The file descriptor to monitor.

Could be:

```text
stdin
socket
client socket
```

### `events`

What we are interested in.

```c
POLLIN
```

Means:

> Data is available to read.

---

# 19. Event Loop Flow

```c
while (1) {

    poll(...);

    if (something_is_ready) {

        read();

        process();

        write();
    }
}
```

Conceptually:

```text
        ┌──────────────┐
        │    poll()    │
        └──────┬───────┘
               ↓
        Something ready?
          /          \
        NO            YES
        │              │
        └──→ poll()    ↓
                     read()
                       ↓
                    process()
                       ↓
                     write()
                       ↓
                     poll()
```

---

# 20. Important Terms

| Term            | Meaning                                        |
| --------------- | ---------------------------------------------- |
| Socket          | Endpoint for network communication             |
| File descriptor | Integer representing an open resource          |
| TCP             | Reliable connection-oriented protocol          |
| IPv4            | Internet addressing system                     |
| IP address      | Identifies a network interface                 |
| Port            | Identifies a service/application               |
| `bind()`        | Assign socket to local IP/port                 |
| `listen()`      | Wait for incoming TCP connections              |
| `accept()`      | Accept a client connection                     |
| `connect()`     | Client connects to server                      |
| `read()`        | Receive/read bytes                             |
| `write()`       | Send/write bytes                               |
| `close()`       | Close socket                                   |
| HTTP            | Protocol built on top of TCP                   |
| Event loop      | Waits for I/O events and handles ready sockets |
| `poll()`        | Waits for file descriptors to become ready     |

---

# 21. The Big Picture

```text
                APPLICATION
                     │
                  HTTP
                     │
                   TCP
                     │
                  SOCKET
                     │
              FILE DESCRIPTOR
                     │
                 OS / KERNEL
                     │
                  NETWORK
```

The main progression to understand is:

```text
socket()
   ↓
file descriptor
   ↓
bind() / connect()
   ↓
TCP connection
   ↓
read() / write()
   ↓
HTTP
   ↓
poll()
   ↓
event-driven server
```

This is the foundation for moving from **C programming → Linux systems programming → network programming → high-performance/event-driven servers**.
