CC = c++ -Wall -Wextra -Werror
CFILES = negation_normal_form.cpp main.cpp
NAME = ex05

all: Makefile $(NAME)

$(NAME): 
	$(CC) -g $(CFILES) -o $(NAME)

clean:
	rm $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re