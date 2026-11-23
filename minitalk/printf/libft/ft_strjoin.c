#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*string;
	size_t	g;
	size_t	f;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	string = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!string)
		return (NULL);
	g = 0;
	f = 0;
	while (s1[g] != '\0')
	{
		string[g] = s1[g];
		g++;
	}
	while (g < (ft_strlen(s1) + ft_strlen(s2)))
	{
		string[g] = s2[f];
		g++;
		f++;
	}
	string[g] = '\0';
	return (string);
}
