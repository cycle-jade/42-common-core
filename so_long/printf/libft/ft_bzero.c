#include <stdio.h>
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*f;
	size_t	g;

	f = (char *)s;
	g = 0;
	while ((g < n))
	{
		f[g] = '\0';
		g++;
	}
}
