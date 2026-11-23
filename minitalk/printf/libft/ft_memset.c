#include <stdio.h>
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	g;
	char	*f;

	f = (char *)s;
	g = 0;
	while ((g < n))
	{
		f[g] = c;
		g++;
	}
	return (s);
}
