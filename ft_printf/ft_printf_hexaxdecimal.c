#include "ft_printf.h"

char	*decimal_to_hexadecimal_up(unsigned int decimal_num)
{
	char			*hex_str;
	unsigned int	digit;
	int				size;
	int				j;

	j = 0;
	if (decimal_num == 0)
		return ("0");
	size = count_hexadecimal_digits(decimal_num);
	hex_str = malloc((size + 1) * sizeof(char));
	j = size - 1;
	while (j >= 0)
	{
		digit = decimal_num % 16;
		if (digit < 10)
			hex_str[j--] = '0' + digit;
		else
			hex_str[j--] = 'A' + digit - 10;
		decimal_num /= 16;
	}
	hex_str[size] = '\0';
	return (hex_str);
}

void	ft_printf_hex_up(unsigned int d, int *count)
{
	unsigned int	converted;
	char			*hex_str;

	converted = convert_tounsigned(d);
	hex_str = decimal_to_hexadecimal_up(converted);
	ft_putstr_fd(hex_str, 1);
	*count = *count + ft_strlen(hex_str);
	if (d != 0)
		free(hex_str);
}
