CC = c++ -Wall -Wextra -Werror
CFILES = curve.cpp main.cpp
NAME = ex10

all: Makefile $(NAME)

$(NAME): 
	$(CC) -g $(CFILES) -o $(NAME)

clean:
	rm $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re