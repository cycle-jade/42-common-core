NAME = libsolong.a
CC = gcc
FLAGS = -Wall -Werror -Wextra
PRINTF_DIR = $(CURDIR)/printf
GET_NEXT_LINE_DIR = $(CURDIR)/Get_Next_Line
SRCS = main.c init.c map.c checks.c key.c render_layer1.c render_layer2.c game_loop.c outro.c free.c animations.c
MLX_PATH = ./minilibx-linux

OBJS = $(SRCS:.c=.o)

all: mlx $(NAME)

printf:
	$(MAKE) -C $(PRINTF_DIR)

mlx:
	wget https://cdn.intra.42.fr/document/document/24017/minilibx-linux.tgz
	tar -xzvf minilibx-linux.tgz
	rm -f minilibx-linux.tgz
	$(MAKE) -C $(MLX_PATH)

get_next_line:

	$(MAKE) -C $(GET_NEXT_LINE_DIR)

%.o: %.c
	$(CC) $(FLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@
 
#.c.o:
#	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS) printf get_next_line
	cp $(PRINTF_DIR)/libftprintf.a $(NAME)
	ar rcs $(NAME) $(OBJS) 

	$(CC) $(OBJS) -L./minilibx-linux -lmlx_Linux -L/usr/lib -Iminilibx-linux -lXext -lX11 -lm -lz -L. -lsolong -L./Get_Next_Line -lget_next_line -o so_long

clean:

	$(MAKE) -C $(PRINTF_DIR) fclean
	$(MAKE) -C $(GET_NEXT_LINE_DIR) fclean
	rm -f $(GET_NEXT_LINE_DIR)/libget_next_line.a
	rm -f $(PRINTF_DIR)/libftprintf.a
	rm -f $(OBJS)
	rm -f so_long
	rm -rf minilibx-linux

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re printf
