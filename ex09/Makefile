CC = c++ -Wall -Wextra -Werror
CFILES = set_evaluation.cpp main.cpp
NAME = ex09

all: Makefile $(NAME)

$(NAME): 
	$(CC) -g $(CFILES) -o $(NAME)

clean:
	rm $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re