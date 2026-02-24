CC = c++ -Wall -Wextra -Werror
CFILES = Truth_table.cpp utils.cpp main.cpp
NAME = ex04

all: Makefile $(NAME)

$(NAME): 
	$(CC) -g $(CFILES) -o $(NAME)

clean:
	rm $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re