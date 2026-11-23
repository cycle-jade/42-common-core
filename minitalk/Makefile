NAME = libminitalk.a
NAME_BONUS = libminitalk_bonus.a
CC = gcc
FLAGS = -Wall -Werror -Wextra
PRINTF_DIR = $(CURDIR)/printf
SRCS = client.c \
       server.c

SRCS_BONUS = client_bonus.c \
             server_bonus.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

bonus: $(NAME_BONUS)

printf:
	@$(MAKE) -C $(PRINTF_DIR)

.c.o:
	@$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS) printf
	@cp $(PRINTF_DIR)/libftprintf.a $(NAME)
	@ar rcs $(NAME) $(OBJS)
	@$(CC) server.o -L. -lminitalk -o server
	@$(CC) client.o -L. -lminitalk -o client

$(NAME_BONUS): $(OBJS_BONUS) printf
	@cp $(PRINTF_DIR)/libftprintf.a $(NAME_BONUS)
	@ar rcs $(NAME_BONUS) $(OBJS_BONUS)
	@$(CC) server_bonus.o -L. -lminitalk_bonus -o server_bonus
	@$(CC) client_bonus.o -L. -lminitalk_bonus -o client_bonus

clean:
	@$(MAKE) -C $(PRINTF_DIR) fclean
	@rm -f $(PRINTF_DIR)/libftprintf.a
	@rm -f $(OBJS)
	@rm -f server
	@rm -f client
	@rm -f $(OBJS_BONUS)
	@rm -f server_bonus
	@rm -f client_bonus

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re printf bonus
