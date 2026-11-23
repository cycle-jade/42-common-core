#include <string.h>
#include <stddef.h>

char	*find_str(const char *big, const char *little, size_t len, size_t h)
{
	size_t	k;
	size_t	j;
	size_t	s;

	k = 0;
	j = 0;
	s = 0;
	if (little[k] == big[h])
	{
		j = h;
		s = h;
		while (big[s] == little[k] && s < len)
		{
			s++;
			k++;
			if (little[k] == '\0')
				return ((char *)(big + j));
		}
	}
	return (NULL);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	h;
	char	*found;

	if (big == NULL && len == 0)
		return (NULL);
	h = 0;
	if (little[0] == '\0' || little == big || (*little == '\0' && len == 0))
		return ((char *)big);
	while (big[h] && h < len)
	{
		found = find_str(big, little, len, h);
		if (found != NULL)
			return (found);
		h++;
	}
	return (NULL);
}
