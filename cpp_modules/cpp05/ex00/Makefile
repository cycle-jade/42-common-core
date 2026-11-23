NAME := bureaucrat

CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

# Build the executable from the exercise sources.
SRCS := main.cpp Bureaucrat.cpp
OBJS := $(SRCS:.cpp=.o)

all: $(NAME)

# Link the object files into the final executable.
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

# Compile each source file into an object file.
%.o: %.cpp Bureaucrat.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Remove intermediate object files.
clean:
	rm -f $(OBJS)

# Remove both the objects and the final binary.
fclean: clean
	rm -f $(NAME)

# Rebuild everything from scratch.
re: fclean all

.PHONY: all clean fclean re
