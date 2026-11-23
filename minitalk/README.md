*This project has been created as part of the 42 curriculum by `<glicciar>`.*

# minitalk

> A client and a server that exchange messages using only UNIX signals.

## Description

minitalk is a small communication program made of a `server` and a `client`. The client sends a string to the server, and the two sides talk using only the signals `SIGUSR1` and `SIGUSR2`. The goal is to understand UNIX signals and how to encode data bit by bit.

**How it works**
- The server starts first and prints its PID
- The client takes the server PID and a string, and sends the string one bit at a time
- The server rebuilds the characters and prints the string without delay
- The server can receive messages from several clients in a row, without restarting

**Bonus (implemented):** the server acknowledges each received message with a signal back to the client, and Unicode characters are supported.

## Instructions

**Requirements:** `cc` and `make`.

```bash
make
./server
# prints: PID: 12345
./client 12345 "Hello, world!"
```

## Resources
- `man 2 sigaction`, `man 2 kill`, `man 7 signal`
- [GNU C Library: signal handling](https://www.gnu.org/software/libc/manual/html_node/Signal-Handling.html)

**Use of AI**
- Code assistence and debugging
