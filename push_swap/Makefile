# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkane <mkane@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/18 18:09:23 by mkane             #+#    #+#              #
#    Updated: 2024/02/22 01:46:05 by mkane            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

BONUS = checker

PARSING_DIR = ./src/parsing/

PUSH_SWAP_DIR = ./src/push_swap/

UTILS_DIR = ./utils/

CHECKER_DIR = ./src/checker/


SRC = main.c\
	$(PUSH_SWAP_DIR)lst_swap.c\
	$(PUSH_SWAP_DIR)lst_push.c\
	$(PUSH_SWAP_DIR)lst_rotate.c\
	$(PUSH_SWAP_DIR)lst_reverse_rotate.c\
	$(PUSH_SWAP_DIR)cost.c\
	$(PUSH_SWAP_DIR)mouvements_case.c\
	$(PUSH_SWAP_DIR)push_swap.c\
	$(PUSH_SWAP_DIR)sort_three.c\
	$(PUSH_SWAP_DIR)sort_five.c\
	$(PUSH_SWAP_DIR)sort.c\
	$(PARSING_DIR)parsing.c\
	$(PARSING_DIR)join_argv.c\
	$(UTILS_DIR)ft_long_atoi.c\
	$(UTILS_DIR)ft_create_stack.c\
	$(UTILS_DIR)ft_stack_add_back.c\
	$(UTILS_DIR)ft_stack_last.c\
	$(UTILS_DIR)ft_fill_stack_a.c\
	$(UTILS_DIR)ft_free_stack.c\
	$(UTILS_DIR)ft_stack_add_front.c\
	$(UTILS_DIR)ft_update_index.c\
	$(UTILS_DIR)median.c\
	$(UTILS_DIR)min.c\
	$(UTILS_DIR)max.c\
	$(UTILS_DIR)ft_check_sorted.c\
	$(UTILS_DIR)ft_find_pos.c\

OBJ = $(SRC:.c=.o)


CHECKER_SRC = $(CHECKER_DIR)checker.c\
			$(PUSH_SWAP_DIR)lst_swap.c\
			$(PUSH_SWAP_DIR)lst_push.c\
			$(PUSH_SWAP_DIR)lst_rotate.c\
			$(PUSH_SWAP_DIR)lst_reverse_rotate.c\
			$(PUSH_SWAP_DIR)cost.c\
			$(PUSH_SWAP_DIR)mouvements_case.c\
			$(PUSH_SWAP_DIR)push_swap.c\
			$(PUSH_SWAP_DIR)sort_three.c\
			$(PUSH_SWAP_DIR)sort_five.c\
			$(PUSH_SWAP_DIR)sort.c\
			$(PARSING_DIR)parsing.c\
			$(PARSING_DIR)join_argv.c\
			$(UTILS_DIR)ft_long_atoi.c\
			$(UTILS_DIR)ft_create_stack.c\
			$(UTILS_DIR)ft_stack_add_back.c\
			$(UTILS_DIR)ft_stack_last.c\
			$(UTILS_DIR)ft_fill_stack_a.c\
			$(UTILS_DIR)ft_free_stack.c\
			$(UTILS_DIR)ft_stack_add_front.c\
			$(UTILS_DIR)ft_update_index.c\
			$(UTILS_DIR)median.c\
			$(UTILS_DIR)min.c\
			$(UTILS_DIR)max.c\
			$(UTILS_DIR)ft_check_sorted.c\
			$(UTILS_DIR)ft_find_pos.c\
			

CHECKER_OBJ = $(CHECKER_SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

HEADERS = ./includes/push_swap.h

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	$(CC) $(CFLAGS) -I$(HEADERS) ${OBJ} -L./libft -lft -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -include$(HEADERS) -o $@ -c $<

bonus: $(BONUS)

$(BONUS): $(CHECKER_OBJ)
	make -C libft
	$(CC) $(CFLAGS) -I$(HEADERS) ${CHECKER_OBJ} -L./libft -lft -o $(BONUS)

clean:
	make -C libft clean
	-rm -f $(OBJ) $(CHECKER_OBJ)

fclean: clean
	make -C libft fclean
	-rm -f $(NAME) $(BONUS)

re: fclean all

