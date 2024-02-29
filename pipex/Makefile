# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkane <mkane@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/27 06:39:11 by mkane             #+#    #+#              #
#    Updated: 2024/02/27 06:51:25 by mkane            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

BONUS = pipex_bonus

PIPEX_DIR = ./srcs/pipex/


SRC = 

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

HEADERS = ./includes/pipex.h

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	$(CC) $(CFLAGS) -I$(HEADERS) ${OBJ} -L./libft -lft -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -include$(HEADERS) -o $@ -c $<

clean:
	make -C libft clean
	-rm -f $(OBJ)

fclean: clean
	make -C libft fclean
	-rm -f $(NAME)

re: fclean all