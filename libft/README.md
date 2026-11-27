*This project has been created as part of the 42 curriculum by `<glicciar>`.*

# libft

> My first C library: recoded standard functions and utilities reused across the curriculum.

## Description

Libft is a static library (`libft.a`) rebuilt from scratch in C. It reimplements part of the C standard library under the `ft_` prefix, adds extra utility functions, and provides a linked list toolkit. Writing it taught me how these functions really behave, down to edge cases and memory handling.

**What it contains**
- **Libc functions:** reimplementations with the same behaviour as the originals (for example `ft_strlen`, `ft_memcpy`, `ft_atoi`, `ft_strchr`)
- **Additional functions:** `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_itoa`, `ft_strmapi`, `ft_striteri`, and the `ft_put*_fd` output functions


Built with `-Wall -Wextra -Werror`, no global variables, and the library is created with `ar`.

## Instructions

**Requirements:** `cc` and `make`.

```bash
make          # builds libft.a
make clean    # remove object files
make fclean   # remove objects and libft.a
make re       # rebuild
```

**Use it in your own code**
```c
#include "libft.h"
```
```bash
cc main.c -L. -lft
```

## Resources
- `man` pages for each libc function (`man 3 strlen`, and so on)
- [GNU C Library manual](https://www.gnu.org/software/libc/manual/)

**Use of AI**
- Code assistence and debugging
