# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkane <mkane@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/08 04:48:00 by kane              #+#    #+#              #
#    Updated: 2024/02/13 12:40:26 by mkane            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

PARSING_DIR = ./src/parsing/

GAME_DIR = ./src/game/

UTILS_DIR = ./utils/

SRC = main.c\
	$(PARSING_DIR)ft_create_map.c\
	$(PARSING_DIR)check_map.c\
	$(PARSING_DIR)check_map2.c\
	$(PARSING_DIR)parsing.c\


OBJ = $(SRC:.c=.o)

LIBFT = ./lib/libft

LIBFTFLAGS = -L. -lft

MLX = ./lib/minilibx-linux

MLXFLAGS = -L. -Lmlx_linux -lmlx -Imlx_linux -lXext -lX11 -lm -lz

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3

HEADERS = ./includes/so_long.h

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT)
	mv $(LIBFT)/libft.a .
	make -C $(MLX)
	mv $(MLX)/libmlx.a .
	$(CC) $(CFLAGS) -I$(HEADERS) ${OBJ} $(LIBFTFLAGS) $(MLXFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -include$(HEADERS) -o $@ -c $<

clean:
	make -C $(LIBFT) clean
	make -C $(MLX) clean
	-rm -f $(OBJ)

fclean: clean
	-rm -f $(NAME) libft.a libmlx.a

re: fclean all