NAME = push_swap
CC = gcc
FLAGS = -Wall -Wextra -Werror
SRCS = push_swap.c push.c rotates.c reverse-rotate.c swap.c push_swap_utils.c push_swap_utils_2.c \
		push_swap_utils_3.c push_swap_utils_4.c push_swap_utils_5.c algorithm.c initialization.c init_2.c


all: $(NAME)

ft_printf:
	$(MAKE) -C ./printf


$(NAME): ft_printf $(SRCS)
	$(CC) $(FLAGS) $(SRCS) -L./printf -lftprintf  -o $(NAME)

clean:
	$(MAKE) -C ./printf fclean

fclean: clean
	rm -f push_swap

re: fclean all

all: $(NAME)