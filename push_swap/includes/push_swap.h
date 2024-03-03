/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kane <kane@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 02:23:14 by mkane             #+#    #+#             */
/*   Updated: 2024/03/03 19:56:48 by kane             ###   ########.fr       */
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

typedef struct s_cost
{
	int	ra_rb;
	int	rra_rrb;
	int	rra_rb;
	int	ra_rrb;
}					t_cost;

t_stack		*ft_stack_last(t_stack *stack);
t_stack		*ft_create_stack(int nb, int pos);
t_stack		*ft_fill_stack_a(char *argv);
void		ft_stack_add_back(t_stack **stack, t_stack *new);
void		ft_free_tab(char **tab);
void		ft_free_stack(t_stack *stack);
void		ft_stack_add_front(t_stack **stack, t_stack *new);
void		ft_update_index(t_stack **stack);
int			ft_check_sorted(t_stack **stack);
int			ft_median(t_stack **stack);
int			ft_min(t_stack **stack);
int			ft_min_pos(t_stack **stack);
int			ft_max(t_stack **stack);
int			ft_max_pos(t_stack **stack);
int			ft_find_pos(t_stack **stack, int nbr);
long long	ft_long_atoi(const char *nptr);

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

int			ft_check_digit(char *str);
int			parsing(char *argv);
int			ft_check_atoi(char **str);
char		*join_argv(int argc, char **argv);
int			ft_isjoinable(char **str);

void		ft_cost(t_stack **a, t_stack **b, int *nbr_a, int *nbr_b);
int			ft_target_nbr_b(int nbr, t_stack **b);
int			ft_min_cost(t_stack **a, t_stack **b, int nbr_a, int nbr_b);
int			ft_compare_cost(int a, int b);
int			ft_cheaper_move(t_cost cost);
void		ft_cost_a(t_stack **a, t_stack **b, int *nbr_a, int *nbr_b);
int			ft_target_nbr_a(int nbr, t_stack **a);


void		ft_push_swap(t_stack **stack_a, t_stack **stack_b);
void		ft_sort_three(t_stack **stack_a);
void		ft_sort_five(t_stack **stack_a, t_stack **stack_b);
void		ft_sort(t_stack **a, t_stack **b);
void		ft_move_to_top_b(t_stack **b, int pos);
void		ft_move_to_top_a(t_stack **a, int pos);
int			ft_reverse_pos(t_stack **stack, int pos);
void		ft_double_rotation(t_stack **a, t_stack **b, int pos_a, int pos_b);
void		ft_rra_rrb(t_stack **a, t_stack **b, int pos_a, int pos_b);
void		ft_rra_rb(t_stack **a, t_stack **b, int pos_a, int pos_b);
void		ft_ra_rrb(t_stack **a, t_stack **b, int pos_a, int pos_b);
void		ft_ra_rb(t_stack **a, t_stack **b, int pos_a, int pos_b);
#endif