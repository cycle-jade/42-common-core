#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	char	*string;
	int		count;

	string = (char *)format;
	count = 0;
	va_start(args, format);
	ft_printing(args, string, &count);
	va_end(args);
	return (count);
}
