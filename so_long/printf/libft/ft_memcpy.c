#include <stdio.h>
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	g;
	char	*f;
	char	*l;

	f = (char *)src;
	l = (char *)dest;
	if (!dest && !src)
		return (NULL);
	g = 0;
	while ((g < n))
	{
		l[g] = f[g];
		g++;
	}
	return (dest);
}
