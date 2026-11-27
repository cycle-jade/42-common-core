#include <stdio.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	j;
	size_t	g;
	char	*f;
	char	*l;

	f = (char *)src;
	j = 1;
	l = (char *)dest;
	if (!dest && !src)
		return (NULL);
	g = 0;
	if (dest > src)
	{
		j = -1;
		l += n - 1;
		f += n - 1;
	}
	while ((g++ < n))
	{
		*l = *f;
		l += j;
		f += j;
	}
	return (dest);
}
