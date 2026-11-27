#include "libft.h"
#include <stdlib.h>

long	ft_atoi(const char *nptr)
{
	long				c;
	unsigned long int	atoi;
	long				sign;

	c = 0;
	atoi = 0;
	sign = 1;
	while (nptr[c] == 32 || (nptr[c] >= 9 && nptr[c] <= 13))
		c++;
	if (nptr[c] == '-')
	{
		sign = -1;
		c++;
	}
	else if (nptr[c] == '+')
		c++;
	while ((ft_isdigit(nptr[c])))
	{
		atoi *= 10;
		atoi += nptr[c] - '0';
		c++;
	}
	return (atoi * sign);
}
