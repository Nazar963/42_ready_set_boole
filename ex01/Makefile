CC = c++ -Wall -Wextra -Werror
CFILES = Multiplier.cpp Adder.cpp main.cpp
NAME = ex01

all: Makefile $(NAME)

$(NAME): 
	$(CC) -g $(CFILES) -o $(NAME)

clean:
	rm $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re