#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	f;

	i = 0;
	j = 0;
	f = 0;
	if (size == 0)
		return (ft_strlen(src));
	while ((dst[i] != '\0' && i < size))
		i++;
	while ((src[j] != '\0'))
		j++;
	if (!dst && size == 0)
		return (j);
	if (size <= i)
		return (size + j);
	while ((i + f < size - 1) && (src[f] != '\0'))
	{
		dst[i + f] = src[f];
		f++;
	}
	dst[i + f] = '\0';
	return (i + j);
}
