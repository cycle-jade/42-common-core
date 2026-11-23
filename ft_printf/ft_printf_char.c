#include "ft_printf.h"

char	c_args_reception(va_list args)
{
	char	chr;

	chr = va_arg(args, int);
	return (chr);
}
