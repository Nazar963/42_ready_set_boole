CC = c++ -Wall -Wextra -Werror
CFILES = Boolean_evaluation.cpp main.cpp
NAME = ex03

all: Makefile $(NAME)

$(NAME): 
	$(CC) -g $(CFILES) -o $(NAME)

clean:
	rm $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re