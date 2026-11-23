# Variables
NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
# Source files

SRCS  = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c  \
		ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c  \
		ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
		ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\

# Rule to compile C source files into object files

OBJS = $(SRCS:.c=.o)

# Target

all: $(NAME)

#Dependencies and rules:

# Rule to build the library using ar
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# Rule to compile each .c file into a corresponding .o object file
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to remove object files
clean:
	rm -f $(OBJS)

# Rule to remove object files and the library
fclean: clean
	rm -f $(NAME)

# Rule to rebuild everything from scratch
re: fclean all
# Phony targets
# Targets that are not actual files
.PHONY: all clean fclean re
