#include "ft_printf.h"

void	calculate_hex_digits(unsigned long int tmp, char *str, int *length)
{
	int	i;
	int	flag;
	int	digit;

	flag = 1;
	i = sizeof(void *) * 2 - 1;
	while (i >= 0)
	{
		digit = (tmp >> (i * 4)) & 0xf;
		if (digit != 0 || !flag)
		{
			if (digit < 10)
				str[(*length)++] = '0' + digit;
			else
				str[(*length)++] = 'a' + digit - 10;
			flag = 0;
		}
		i--;
	}
	if (*length == 0)
		str[(*length)++] = '0';
}

void	ft_printf_pointer(void *ptr, int *count)
{
	unsigned long int	tmp;
	int					length;
	char				str[20];

	length = 0;
	if (ptr == NULL)
	{
		ft_putstr_fd("(nil)", 1);
		*count = *count + 5;
	}
	else
	{
		tmp = (unsigned long int)ptr;
		calculate_hex_digits(tmp, str, &length);
		*count = *count + 2;
		write(STDOUT_FILENO, "0x", 2);
		write(STDOUT_FILENO, str, length);
		*count = *count + length;
	}
}

void	*p_args_reception(va_list args)
{
	void	*pointer;

	pointer = va_arg(args, void *);
	return (pointer);
}
