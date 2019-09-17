# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hluton <hluton@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/17 16:37:54 by hluton            #+#    #+#              #
#    Updated: 2019/09/10 21:20:27 by hluton           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

FLAGS = -g -Wall -Wextra -Werror

LIB = libft/

FILES = lem_in.c \
		error.c \
		parse_room.c \
		parse_room_2.c \
		check_ants.c \
		check_connections.c \
		check_connections_2.c \
		free.c \
		free_2.c \
		free_3.c \
		find_pathes.c \
		find_pathes_2.c \
		find_pathes_3.c \
		find_pathes_4.c \
		find_pathes_5.c \
		find_pathes_6.c \
		find_pathes_7.c \
		find_pathes_8.c \
		find_pathes_9.c \
		bfs.c \
		update_stack.c \
		bfs_2.c \
		bfs_3.c \
		bfs_4.c \
		bfs_5.c \
		ants_logistics.c \
		ants_logistics_2.c \
		ants_logistics_3.c \
		print_lem.c \
		print_lem_2.c \
		walk_step.c \
		start_ant.c \
		hash.c \
		validation.c

OBJ = $(FILES:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(OBJ) -L./libft -lft -o $(NAME)

$(OBJ): %.o: %.c
	gcc $(FLAGS) -c $< -o $@

$(LIB):
	make -C ./libft

re: fclean all

clean:
	rm $(OBJ)

fclean: clean
	rm $(NAME)
