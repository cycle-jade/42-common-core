#include <stdlib.h>
#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	count;

	count = 0;
	if (s == NULL)
		return (0);
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (count);
}

static const char	*find_word_end(const char *s, char c)
{
	while (*s && *s != c)
		s++;
	return (s);
}

char	**ft_split(char const *s, char c)
{
	int			num_words;
	char		**array;
	int			i;
	const char	*start;
	const char	*end;

	num_words = count_words(s, c);
	array = (char **)malloc((num_words + 1) * sizeof(char *));
	if (!array || s == NULL)
		return (NULL);
	i = 0;
	start = s;
	while (*start)
	{
		if (*start != c)
		{
			end = find_word_end(start, c);
			array[i++] = ft_substr(start, 0, end - start);
			start = end;
		}
		else
			start++;
	}
	array[i] = NULL;
	return (array);
}
