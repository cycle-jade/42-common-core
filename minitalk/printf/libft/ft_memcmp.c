#include <string.h>
#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			j;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	j = 0;
	if (n == 0)
		return (0);
	while ((j < n))
	{
		if (ptr1[j] != ptr2[j])
			return ((int)(ptr1[j]) - (int)(ptr2[j]));
		j++;
	}
	return (0);
}
