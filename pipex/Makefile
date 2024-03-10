# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkane <mkane@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/27 06:39:11 by mkane             #+#    #+#              #
#    Updated: 2024/03/10 17:00:31 by mkane            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

BONUS = pipex_bonus

PIPEX_DIR = ./src/pipex/
UTILS_DIR = ./utils/
SRC_DIR = ./src/


SRC = $(SRC_DIR)pipex.c\
		$(PIPEX_DIR)main.c\
		$(UTILS_DIR)ft_error.c\
		$(UTILS_DIR)ft_path.c\
		$(UTILS_DIR)ft_parse_args.c\
		$(UTILS_DIR)ft_free.c\
		$(UTILS_DIR)ft_open_file.c\

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