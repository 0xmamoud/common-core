# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkane <mkane@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/18 18:09:23 by mkane             #+#    #+#              #
#    Updated: 2023/12/15 02:09:14 by mkane            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

TEST = a.out

SRC_DIR = ./src/

UTILS_DIR = ./utils/

SRC = $(SRC_DIR)ft_printf.c\
	  $(SRC_DIR)ft_parser.c\
	  $(SRC_DIR)ft_putptr.c\
	  $(SRC_DIR)ft_put_uint.c\
	  $(UTILS_DIR)ft_putchar.c\
	  $(UTILS_DIR)ft_putstr.c\
	  $(UTILS_DIR)ft_putnbr_base.c\
	  $(UTILS_DIR)ft_strlen.c\

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

HEADERS = ft_printf.h

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o : %.c
	$(CC) $(CFLAGS) -include$(HEADERS) -o $@ -c $<

clean:
	-rm -f $(OBJ)

fclean: clean
	-rm -f $(NAME)

re: fclean all

