#include "libft.h"
#include <stddef.h>
#include <string.h>
#include <string.h>
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	size_t	size;
	char	*string;

	size = ft_strlen(s);
	string = (char *)malloc((size + 1) * sizeof(char));
	if (string == NULL)
		return (0);
	ft_memcpy(string, s, size);
	string[size] = '\0';
	return (string);
}
