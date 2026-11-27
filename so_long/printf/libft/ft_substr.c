#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*string;
	size_t	g;

	if (s == NULL)
		return (NULL);
	if (start + len <= ft_strlen(s))
		string = (char *)malloc((len + 1) * sizeof(char));
	else
	{
		if (start > ft_strlen(s))
			start = ft_strlen(s);
		string = (char *)malloc((ft_strlen(s) - start + 1) * sizeof(char));
	}
	if (!string)
		return (NULL);
	g = 0;
	while (g < len && s[start] != '\0')
	{
		string[g] = s[start];
		g++;
		start++;
	}
	string[g] = '\0';
	return (string);
}
