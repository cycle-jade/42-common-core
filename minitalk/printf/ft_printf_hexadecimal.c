#include <stdlib.h>
#include "ft_printf.h"

int	count_hexadecimal_digits(unsigned int n)
{
	int	count;

	count = 0;
	while (n > 0)
	{
		n /= 16;
		count++;
	}
	return (count);
}

char	*decimal_to_hexadecimal(unsigned int decimal_num)
{
	char			*hex_str;
	unsigned int	digit;
	int				size;
	int				j;

	if (decimal_num == 0)
		return ("0");
	j = 0;
	size = count_hexadecimal_digits(decimal_num);
	hex_str = malloc((size + 1) * sizeof(char));
	j = size - 1;
	while (j >= 0)
	{
		digit = decimal_num % 16;
		if (digit < 10)
			hex_str[j--] = '0' + digit;
		else
			hex_str[j--] = 'a' + digit - 10;
		decimal_num /= 16;
	}
	hex_str[size] = '\0';
	return (hex_str);
}

void	ft_printf_hex(unsigned int d, int *count)
{
	unsigned int	converted;
	char			*hex_str;

	converted = convert_tounsigned(d);
	hex_str = decimal_to_hexadecimal(converted);
	ft_putstr_fd(hex_str, 1);
	*count = *count + ft_strlen(hex_str);
	if (d != 0)
		free(hex_str);
}
