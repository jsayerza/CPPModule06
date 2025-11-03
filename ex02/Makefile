NAME = identify

# Compiler
CXX = c++
# Flags per a compiler
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
# Flags per a debug
DEBUG_FLAGS = -g -fsanitize=address -fsanitize=undefined

INC_PATH =	./includes/
INC =		-I $(INC_PATH)
HEADERS =	$(INC_PATH)Base.hpp \
			$(INC_PATH)A.hpp \
			$(INC_PATH)B.hpp \
			$(INC_PATH)C.hpp 

SRC_PATH =	./sources/
SRC =		$(SRC_PATH)main.cpp \
			$(SRC_PATH)Base.cpp 

OBJ_PATH =	./objects/
OBJ =		$(SRC:$(SRC_PATH)%.cpp=$(OBJ_PATH)%.o)


# Regla per a build
all: $(OBJ_PATH) $(NAME)

# Regla per a build objects
$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp $(HEADERS) Makefile
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(INC)

# Regla per a build program
$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

# Regla per a debug
debug: CXXFLAGS += $(DEBUG_FLAGS)
debug: re

clean:
	rm -f $(OBJ_PATH)*.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re debug

# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./identify