# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kane <kane@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/27 06:39:11 by mkane             #+#    #+#              #
#    Updated: 2024/03/16 20:18:54 by kane             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

BONUS = pipex_bonus

PIPEX_DIR = ./src/pipex/

PIPELINE_DIR = ./src/pipeline/

SRC_DIR = ./src/

PARSING_DIR = ./src/parsing/


SRC =\
	$(PIPEX_DIR)pipex.c\
	$(PIPELINE_DIR)pipeline.c\
	$(SRC_DIR)execution.c\
	$(SRC_DIR)path_parsing.c\
	$(SRC_DIR)utils.c

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

HEADERS = ./includes/pipex.h

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	$(CC) $(CFLAGS) -I$(HEADERS) ${OBJ} -L./libft -lft -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -include$(HEADERS) -o $@ -c $<

clean:
	@make -C libft clean
	@rm -f $(OBJ)

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)

re: fclean all