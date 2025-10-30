NAME = convert

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Flags para debug
DEBUG_FLAGS = -g -fsanitize=address -fsanitize=undefined

SRCS =		main.cpp \
			ScalarConverter.cpp 
			# ScalarConverterFuncs.cpp

OBJS = $(SRCS:.cpp=.o)

HEADERS =	ScalarConverter.hpp 
			# ScalarConverterFuncs.hpp

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(HEADERS) Makefile
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla para debug
debug: CXXFLAGS += $(DEBUG_FLAGS)
debug: re

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re debug

# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./convert