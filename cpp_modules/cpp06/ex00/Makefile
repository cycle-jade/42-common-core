NAME    = convert
CXX     = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS    = main.cpp ScalarConverter.cpp
OBJS    = $(SRCS:.cpp=.o)

all: $(NAME)

# Link object files into the final binary
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

# Compile each .cpp into a .o (the % is a pattern rule)
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Remove compiled objects
clean:
	rm -f $(OBJS)

# Remove everything including the binary
fclean: clean
	rm -f $(NAME)

# Rebuild from scratch
re: fclean all

# Tell make these are not real files
.PHONY: all clean fclean re