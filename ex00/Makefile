CC = c++ -Wall -Wextra -Werror
CFILES = Adder.cpp main.cpp
NAME = ex00

all: $(NAME)

$(NAME):
	$(CC) -g $(CFILES) -o $(NAME)

clean:
	rm $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re