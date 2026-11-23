#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	h;

	h = 0;
	while (h < n)
	{
		if (((unsigned char *)s)[h] == (unsigned char)c)
			return ((void *)((char *)s + h));
		h++;
	}
	return (NULL);
}
