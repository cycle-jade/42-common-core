#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 15
# endif
# ifndef MAX_FD
#  define MAX_FD 10240
# endif

char	*ft_strchr_bonus(const char *s, int c);
char	*ft_strjoin_bonus(char const *s1, char const *s2);
char	*ft_strdup_bonus(char *s1);
size_t	ft_strlen_b(const char *s);
char	*ft_substr_bonus(const char *s, unsigned int start, size_t len);
char	*get_next_line(int fd);

#endif