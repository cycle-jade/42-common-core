#include "ft_printf.h"

void	ft_printf_decimal(int d, int *count)
{
	char	*yup;

	yup = ft_itoa(d);
	ft_putnbr_fd(d, 1);
	*count = *count + ft_strlen(yup);
	free(yup);
}

int	d_args_reception(va_list args)
{
	int	counter;

	counter = va_arg(args, int);
	return (counter);
}
