#include "get_next_line_bonus.h"

static char	*full_buffer_bonus(int fd, char *stash, char *full)
{
	char	*tmp;
	int		ready;

	ready = 1;
	while (ready > 0)
	{
		ready = read(fd, stash, BUFFER_SIZE);
		if (ready == -1)
			return (NULL);
		else if (ready == 0)
			break ;
		stash[ready] = '\0';
		if (!full)
			full = ft_strdup_bonus("");
		tmp = full;
		full = ft_strjoin_bonus(tmp, stash);
		free(tmp);
		tmp = (NULL);
		if (ft_strchr_bonus(stash, '\n'))
			break ;
	}
	return (full);
}

static char	*cut_that_bonus(char *full)
{
	int		i;
	char	*left_block;

	i = 0;
	while (full[i] != '\n' && full[i] != '\0')
		i++;
	if (full[i] == '\0')
		return (NULL);
	left_block = ft_substr_bonus(full, i + 1, ft_strlen_bonus(full) - i);
	if (*left_block == '\0')
	{
		free(left_block);
		return (NULL);
	}
	full[i + 1] = '\0';
	return (left_block);
}

char	*get_next_line(int fd)
{
	char		*full;
	static char	*left_block[MAX_FD];
	char		*stash;

	stash = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!stash)
		return (NULL);
	full = full_buffer_bonus(fd, stash, left_block[fd]);
	free(stash);
	stash = (NULL);
	if (!full)
		return (NULL);
	left_block[fd] = cut_that_bonus(full);
	return (full);
}
