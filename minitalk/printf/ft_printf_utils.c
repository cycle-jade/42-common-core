// char	*ft_strnstr(const char *big, const char *little, size_t len)

#include "ft_printf.h"

void	calling(va_list args, char box, int *count)
{
	if (box == 'c')
	{
		ft_putchar_fd(c_args_reception(args), 1);
		*count = *count + 1;
	}
	else if (box == 's')
		ft_printf_string(s_args_reception(args), count);
	else if (box == 'd' || box == 'i')
		ft_printf_decimal(d_args_reception(args), count);
	else if (box == 'u')
		ft_printf_unsigned(u_args_reception(args), count);
	else if (box == 'p')
		ft_printf_pointer(p_args_reception(args), count);
	else if (box == 'x')
		ft_printf_hex(u_args_reception(args), count);
	else if (box == 'X')
		ft_printf_hex_up(u_args_reception(args), count);
}

void	ft_printing(va_list args, char *string, int *count)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (string[i] == '%' && string[i + 1] != '%')
		{
			calling(args, string[i++ + 1], count);
		}
		else if (string[i] != '%')
		{
			ft_putchar_fd(string[i], 1);
			*count = *count + 1;
		}
		else if (string[i] == '%' && string[i + 1] == '%')
		{
			ft_putchar_fd('%', 1);
			*count = *count + 1;
			i++;
		}
		i++;
	}
}

int	count_decimal_digits(unsigned int n)
{
	int	count;

	count = 0;
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}
