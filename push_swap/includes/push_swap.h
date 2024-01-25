/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kane <kane@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 02:23:14 by mkane             #+#    #+#             */
/*   Updated: 2024/01/25 20:25:47 by kane             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"

typedef struct s_stack
{
	int				pos;
	int				nb;
	struct s_stack	*next;
}					t_stack;

typedef struct s_env
{
	t_stack	*stack_a;
	t_stack	*stack_b;
}				t_env;

t_stack		*ft_stack_last(t_stack *stack);
t_stack		*ft_create_stack(int nb, int pos);
t_stack		*ft_fill_stack_a(char *argv);
void		ft_stack_add_back(t_stack **stack, t_stack *new);
void		ft_free_tab(char **tab);
void		ft_free_stack(t_stack *stack);
void		ft_stack_add_front(t_stack **stack, t_stack *new);
void		ft_update_index(t_stack **stack);
void		ft_lst_swap(t_stack **stack);
void		ft_lst_swap_a(t_stack **stack);
void		ft_lst_swap_b(t_stack **stack);
void		ft_lst_swap_both(t_stack **stack_a, t_stack **stack_b);
void		ft_lst_push(t_stack **src, t_stack **dst);
void		ft_lst_push_a(t_stack **src, t_stack **dst);
void		ft_lst_push_b(t_stack **src, t_stack **dst);
void		ft_lst_rotate(t_stack **stack);
void		ft_lst_rotate_a(t_stack **stack);
void		ft_lst_rotate_b(t_stack **stack);
void		ft_lst_rotate_both(t_stack **stack_a, t_stack **stack_b);
void		ft_lst_reverse_rotate(t_stack **stack);
void		ft_lst_reverse_rotate_a(t_stack **stack);
void		ft_lst_reverse_rotate_b(t_stack **stack);
void		ft_lst_reverse_rotate_both(t_stack **stack_a, t_stack **stack_b);
void		ft_three_case(t_stack **stack_a);
void		ft_push_swap(t_stack **stack_a, t_stack **stack_b);
int			ft_check_digit(char *str);
int			parsing(char *argv);
int			ft_check_atoi(char **str);
long long	ft_long_atoi(const char *nptr);
char		*join_argv(int argc, char **argv);
int			ft_get_median(t_stack **stack);
int			ft_min(t_stack **stack);
int			ft_check_sort(t_stack **stack);
void		ft_sort(t_stack **stack_a, t_stack **stack_b);
int			ft_lowest_nbr(t_stack **stack_a, t_stack **stack_b, int *pos);
int			ft_find_max_min(t_stack **stack, int nbr);
#endif