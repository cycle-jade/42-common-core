#include "get_next_line.h"

#include <stddef.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (!*s)
			return (NULL);
		s++;
	}
	return ((char *)s);
}

size_t	ft_strlen(const char *s)
{
	int	n;

	n = 0;
	while (s[n] != '\0')
	{
		n++;
	}
	return (n);
}

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

char	*ft_strdup(char *s1)
{
	char			*dest;
	unsigned int	i;

	dest = (char *) malloc(ft_strlen(s1) + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

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
