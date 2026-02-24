CC = c++ -Wall -Wextra -Werror
CFILES = inverse_function.cpp main.cpp
NAME = ex11

all: Makefile $(NAME)

$(NAME): 
	$(CC) -g $(CFILES) -o $(NAME)

clean:
	rm $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re