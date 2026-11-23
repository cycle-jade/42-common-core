#include "get_next_line_bonus.h"

#include <stddef.h>

char	*ft_strchr_bonus(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (!*s)
			return (NULL);
		s++;
	}
	return ((char *)s);
}

size_t	ft_strlen_b(const char *s)
{
	int	n;

	n = 0;
	while (s[n] != '\0')
	{
		n++;
	}
	return (n);
}

char	*ft_strjoin_bonus(char const *s1, char const *s2)
{
	char	*s;
	size_t	g;
	size_t	f;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s = (char *)malloc((ft_strlen_b(s1) + ft_strlen_b(s2) + 1) * sizeof(char));
	if (!s)
		return (NULL);
	g = 0;
	f = 0;
	while (s1[g] != '\0')
	{
		s[g] = s1[g];
		g++;
	}
	while (g < (ft_strlen_b(s1) + ft_strlen_b(s2)))
	{
		s[g] = s2[f];
		g++;
		f++;
	}
	s[g] = '\0';
	return (s);
}

char	*ft_strdup_bonus(char *s1)
{
	char			*dest;
	unsigned int	i;

	dest = (char *) malloc(ft_strlen_b(s1) + 1);
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

char	*ft_substr_bonus(const char *s, unsigned int start, size_t len)
{
	char	*string;
	size_t	g;

	if (s == NULL)
		return (NULL);
	if (start + len <= ft_strlen_b(s))
		string = (char *)malloc((len + 1) * sizeof(char));
	else
	{
		if (start > ft_strlen_b(s))
			start = ft_strlen_b(s);
		string = (char *)malloc((ft_strlen_b(s) - start + 1) * sizeof(char));
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
