NAME = lem-in

SRC = lem.c
		
INCLUDES = libft/libft.a

all: $(NAME)

$(NAME): $(SRC)
		make -C libft
		gcc -Wall -Werror -Wextra $(SRC) $(INCLUDES) -o $(NAME) -g

clean: 
		make clean -C libft

fclean: clean
		make fclean -C libft
		rm -f $(NAME)

re: fclean all