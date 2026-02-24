CC = c++ -Wall -Wextra -Werror
CFILES = Gray_code.cpp main.cpp
NAME = ex02

all: Makefile $(NAME)

$(NAME): 
	$(CC) -g $(CFILES) -o $(NAME)

clean:
	rm $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re