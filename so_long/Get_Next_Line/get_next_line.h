#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 15
# endif

char	*ft_strchr_get(const char *s, int c);
char	*ft_strjoin_get(char const *s1, char const *s2);
char	*ft_strdup_get(char *s1);
size_t	ft_strlen_get(const char *s);
char	*ft_substr_get(const char *s, unsigned int start, size_t len);
char	*get_next_line(int fd);
void	end_it(int fd);

#endif