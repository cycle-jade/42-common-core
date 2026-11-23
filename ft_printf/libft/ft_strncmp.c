#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				j;
	const unsigned char	*us1;
	const unsigned char	*us2;

	us1 = (const unsigned char *)s1;
	us2 = (const unsigned char *)s2;
	j = 0;
	if (n == 0)
		return (0);
	while ((j < n) && (us1[j] || us2[j]))
	{
		if (us1[j] != us2[j])
			return (us1[j] - us2[j]);
		j++;
	}
	return (0);
}
