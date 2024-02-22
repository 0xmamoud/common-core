/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkane <mkane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 20:36:22 by kane              #+#    #+#             */
/*   Updated: 2024/02/21 21:07:55 by mkane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_sort(t_stack **a, t_stack **b)
{
	int	nbr_a;
	int	nbr_b;

	ft_lst_push_b(a, b);
	ft_lst_push_b(a, b);
	while (*a)
	{
		if (ft_min(b) > (*a)->nb || ft_max(b) < (*a)->nb)
		{
			ft_move_to_top_b(b, ft_max_pos(b));
			ft_lst_push_b(a, b);
		}
		else
		{
			ft_cost(a, b, &nbr_a, &nbr_b);
			ft_double_rotation(a, b, ft_find_pos(a, nbr_a),
				ft_find_pos(b, nbr_b));
			ft_lst_push_b(a, b);
		}
	}
	while (*b)
	{
		ft_move_to_top_b(b, ft_max_pos(b));
		ft_lst_push_a(b, a);
	}
}

void	ft_double_rotation(t_stack **a, t_stack **b, int pos_a, int pos_b)
{
	t_cost	cost;
	int		min_cost;

	cost.ra_rb = ft_compare_cost(pos_a, pos_b);
	cost.rra_rrb = ft_compare_cost(ft_reverse_pos(a, pos_a),
			ft_reverse_pos(b, pos_b));
	cost.rra_rb = ft_reverse_pos(a, pos_a) + pos_b ;
	cost.ra_rrb = pos_a + ft_reverse_pos(b, pos_b);
	min_cost = ft_cheaper_move(cost);
	if (min_cost == cost.rra_rrb)
		ft_rra_rrb(a, b, pos_a, pos_b);
	else if (min_cost == cost.rra_rb)
		ft_rra_rb(a, b, pos_a, pos_b);
	else if (min_cost == cost.ra_rrb)
		ft_ra_rrb(a, b, pos_a, pos_b);
	else
		ft_ra_rb(a, b, pos_a, pos_b);
}

void	ft_move_to_top_b(t_stack **b, int pos)
{
	if (pos > ft_median(b))
	{
		pos = ft_reverse_pos(b, pos);
		while (pos > 1)
		{
			ft_lst_reverse_rotate_b(b);
			pos--;
		}
	}
	else
	{
		while (pos > 1)
		{
			ft_lst_rotate_b(b);
			pos--;
		}
	}
}

int	ft_reverse_pos(t_stack **stack, int pos)
{
	int		size;
	int		i;

	size = ft_stack_last(*stack)->pos;
	i = 1;
	while (size >= pos)
	{
		i++;
		pos++;
	}
	return (i);
}
