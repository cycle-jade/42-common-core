#include "get_next_line.h"

static char	*full_buffer(int fd, char *stash, char *full)
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
			full = ft_strdup_get("");
		tmp = full;
		full = ft_strjoin_get(tmp, stash);
		free(tmp);
		tmp = (NULL);
		if (ft_strchr_get(stash, '\n'))
			break ;
	}
	return (full);
}

static char	*cut_that(char *full)
{
	int		i;
	char	*left_block;

	i = 0;
	while (full[i] != '\n' && full[i] != '\0')
		i++;
	if (full[i] == '\0')
		return (NULL);
	left_block = ft_substr_get(full, i + 1, ft_strlen_get(full) - i);
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
	static char	*left_block;
	char		*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!stash)
		return (NULL);
	full = full_buffer(fd, stash, left_block);
	free(stash);
	stash = (NULL);
	if (!full)
		return (NULL);
	left_block = cut_that(full);
	return (full);
}

void	end_it(int fd)
{
	char	*end;

	end = "";
	while (end != NULL)
	{
		end = get_next_line(fd);
		free(end);
	}
}
/*
**  int main()
**  {
**      int fd;
**      char *str;
**      int i = 0;
**
**      fd = open("keef.txt", O_RDONLY);
**      while (i++ < 20)
**      {
**          str = get_next_line(fd);
**
**          printf("%s", str);
**      }
**
**      free(str);
**      return (0);
**  }
**
*/
