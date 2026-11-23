*This project has been created as part of the 42 curriculum by `<glicciar>`.*

# ft_printf

> A recoded version of `printf`, built on C variadic functions.

## Description

ft_printf is a static library (`libftprintf.a`) containing `ft_printf()`, which mimics the behaviour of the original `printf()` for a defined set of conversions. The goal is to learn how variadic functions work and to write well-structured, extensible code.

**Prototype**
```c
int ft_printf(const char *, ...);
```

**Supported conversions**

| Conversion | Prints |
|---|---|
| `%c` | a single character |
| `%s` | a string |
| `%p` | a pointer in hexadecimal |
| `%d` / `%i` | a signed decimal integer |
| `%u` | an unsigned decimal integer |
| `%x` / `%X` | hexadecimal, lowercase / uppercase |
| `%%` | a percent sign |

The function does not implement the buffer management of the real `printf()`, and returns the number of characters printed.

## Instructions

**Requirements:** `cc` and `make`.

```bash
make          # builds libftprintf.a
make clean
make fclean
make re
```

**Example**
```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s, you are %d years old (0x%x)\n", "world", 42, 255);
    return (0);
}
```
```bash
cc main.c -L. -lftprintf
```

## Resources
- `man 3 printf`, `man 3 stdarg`
- [GNU C Library: variadic functions](https://www.gnu.org/software/libc/manual/html_node/Variadic-Functions.html)

**Use of AI**
- Code assistence and debugging
