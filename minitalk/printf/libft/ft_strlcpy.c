#include <stddef.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	g;
	int		count;

	count = 0;
	g = 0;
	if (size != '\0')
	{
		while ((src[g] != '\0') && (g < size - 1))
		{
			dst[g] = src[g];
			g++;
		}
		dst[g] = '\0';
	}
	while (src[count] != '\0')
		count++;
	return (count);
}
