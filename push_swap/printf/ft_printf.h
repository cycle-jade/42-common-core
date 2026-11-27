#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stddef.h>
# include <string.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <stdarg.h>

int				ft_printf(const char *format, ...);
void			ft_printing(va_list args, char *string, int *count);
char			*s_args_reception(va_list args);
void			ft_printf_string(char *s, int *count);
char			c_args_reception(va_list args);
int				d_args_reception(va_list args);
void			ft_printf_decimal(int d, int *count);
void			ft_printf_unsigned(unsigned int d, int *count);
unsigned int	u_args_reception(va_list args);
void			*p_args_reception(va_list args);
void			ft_printf_pointer(void *ptr, int *count);
int				count_decimal_digits(unsigned int n);
void			ft_printf_hex(unsigned int d, int *count);
void			ft_printf_hex_up(unsigned int d, int *count);
unsigned int	convert_tounsigned(int n);
int				count_hexadecimal_digits(unsigned int n);

#endif