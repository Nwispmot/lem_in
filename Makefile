OBJ_DIR	 = ./obj
LIB_DIR	 = ./libft

NAME	 = lem-in
LIBFT 	 = $(LIB_DIR)/libft.a

SRC 	 = lem.c repeat.c

OBJ 	 = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

CC	 = gcc
CFLAGS	 = -Wall -Wextra -Werror
LIB_INC  = -I $(LIB_DIR)/includes
LIB_LINK = -L $(LIB_DIR) -lft

all: $(NAME)

$(LIBFT):
	@make -C $(LIB_DIR) --no-print-directory	

$(OBJ_DIR):
	@mkdir -p $@

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIB_INC) $(LIB_LINK) -o $(NAME)
 
$(addprefix $(OBJ_DIR)/, %.o):%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(LIB_INC) -c $< -o $@

clean:
	@make -C $(LIB_DIR) clean --no-print-directory
	rm -rf $(OBJ_DIR)

fclean: clean
	@make -C $(LIB_DIR) fclean --no-print-directory
	rm -f $(NAME)

re: fclean all

