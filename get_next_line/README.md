*This project has been created as part of the 42 curriculum by `<glicciar>`.*

# get_next_line

> A function that reads a file descriptor one line at a time.

## Description

`get_next_line()` returns the next line read from a file descriptor each time it is called, so a loop can read a whole file, or standard input, line by line. It introduces static variables and careful buffer and memory management.

**Prototype**
```c
char *get_next_line(int fd);
```

**Behaviour**
- Returns the line read, including the final `\n` (except at the end of a file that does not end with one)
- Returns `NULL` when there is nothing left to read or an error occurs
- Works on files and on standard input
- The read size is set at compile time with `BUFFER_SIZE`
- **Bonus (implemented):** handles several file descriptors at the same time, without losing the reading state of each one

## Instructions

**Requirements:** `cc`.

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
```
For the bonus version, use the `_bonus` files instead.

**Example**
```c
int fd = open("file.txt", O_RDONLY);
char *line;

while ((line = get_next_line(fd)) != NULL)
{
    printf("%s", line);
    free(line);
}
close(fd);
```

## Resources
- `man 2 read`, `man 3 free`
- Articles and documentation on static variables in C

**Use of AI**
- Code assistence and debugging
