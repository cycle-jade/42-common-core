NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = $(CURDIR)/libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I$(LIBFT_DIR)
LIBRARIES = -L$(LIBFT_DIR) -lft

# Source files
SRCS = ft_printf.c \
       ft_printf_char.c \
       ft_printf_string.c \
       ft_printf_pointer.c \
       ft_printf_decimal.c \
       ft_printf_unsigned.c \
       ft_printf_hexadecimal.c \
       ft_printf_utils.c \
	   ft_printf_hexaxdecimal.c

#-I./libft -L./libft -lft

# Rule to compile C source files into object files
OBJS = $(SRCS:.c=.o)

# Target
all: $(NAME)

libft:
	@$(MAKE) -C $(LIBFT_DIR)
.c .o:
	@ $(CC) $(CFLAGS) -g -c $< -o $(<: .c= .o)
	
$(NAME): $(OBJS) libft
	cp $(LIBFT_DIR)/libft.a $(NAME)
	@ ar rcs $(NAME) $(OBJS)

# Rule to remove object files
clean:
	@ $(MAKE) -C $(LIBFT_DIR) clean
	@ rm -f $(LIBFT)
	@ rm -f $(OBJS)

# Rule to remove object files and the library
fclean: clean
	@ rm -f $(NAME)

# Rule to rebuild everything from scratch
re: fclean all

# Phony targets
.PHONY: all clean fclean re libft
