#include "libft.h"
#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	const char	*ptr;

	ptr = NULL;
	while (*s)
	{
		if (*s == (char)c)
			ptr = s;
		s++;
	}
	if (*s == '\0' && ptr == NULL && c == '\0')
		return ((char *)s);
	return ((char *)ptr);
}
