#include "ft_printf.h"
#include <limits.h>

unsigned int	convert_tounsigned(int n)
{
	if (n >= 0)
		return ((unsigned int)n);
	else
		return ((unsigned int)(4294967296 + n));
}

char	*calculation(unsigned int converted, int num_digits)
{
	char	*str;
	int		i;
	int		digit;

	str = (char *)malloc((num_digits + 1) * sizeof(char));
	i = num_digits - 1;
	while (converted > 0)
	{
		digit = converted % 10;
		str[i--] = digit + '0';
		converted /= 10;
	}
	str[num_digits] = '\0';
	return (str);
}

void	ft_printf_unsigned(unsigned int d, int *count)
{
	unsigned int	converted;
	char			*str;
	int				num_digits;

	if (d != 0)
	{
		converted = convert_tounsigned(d);
		num_digits = count_decimal_digits(converted);
		str = calculation(converted, num_digits);
		ft_putstr_fd(str, 1);
		*count = *count + num_digits;
		free(str);
	}
	else
	{
		ft_putnbr_fd(0, 1);
		*count = *count + 1;
	}
}

unsigned int	u_args_reception(va_list args)
{
	unsigned int	unsign;

	unsign = va_arg(args, unsigned int);
	return (unsign);
}
