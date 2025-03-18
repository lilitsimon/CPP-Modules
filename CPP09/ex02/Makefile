NAME = PmergeMe
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

SOURCES = 	main.cpp \
			PmergeMe.cpp\
	
			
OBJECTS = $(SOURCES:.cpp=.o)

NO_COLOR = \033[0;39m
GREEN = \033[1;32m
MAGENTA = \033[0;96m

all:		$(NAME)

$(NAME):	$(OBJECTS)
		$(CC) $(FLAGS) $(OBJECTS) -o $(NAME)
		@echo "$(GREEN)source files compiled$(NO_COLOR)"

%.o: %.cpp
		$(CC) $(FLAGS) -c $< -o $@

clean:
		rm -f $(OBJECTS)
		@echo "$(MAGENTA)object files cleaned$(NO_COLOR)"

fclean: 	clean
		rm -f $(NAME)
		@echo "$(MAGENTA)executable file cleaned$(NO_COLOR)"

re: 	fclean all

.PHONY: all clean fclean re
