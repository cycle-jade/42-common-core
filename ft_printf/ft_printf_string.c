#include "ft_printf.h"

void	ft_printf_string(char *s, int *count)
{
	ft_putstr_fd(s, 1);
	if (s != NULL)
		*count = *count + ft_strlen(s);
	else
	{
		ft_putstr_fd("(null)", 1);
		*count = *count + 6;
	}
}

char	*s_args_reception(va_list args)
{
	char	*s_args;

	s_args = va_arg(args, char *);
	return (s_args);
}
