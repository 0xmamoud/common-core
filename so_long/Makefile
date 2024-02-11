# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kane <kane@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/08 04:48:00 by kane              #+#    #+#              #
#    Updated: 2024/02/11 20:35:58 by kane             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = main.C

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

HEADERS =

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	mv libft/libft.a .
	$(CC) $(CFLAGS) -I$(HEADERS) ${OBJ} -L. -lft -o $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

clean:
	make -C libft clean
	-rm -f $(OBJ)

fclean: clean
	-rm -f $(NAME) libft.a

re: fclean all