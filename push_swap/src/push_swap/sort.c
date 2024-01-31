/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kane <kane@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 20:36:22 by kane              #+#    #+#             */
/*   Updated: 2024/01/31 11:40:15 by kane             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_sort(t_stack **a, t_stack **b)
{
	int	nbr_a;
	int	nbr_b;

	ft_lst_push_b(a, b);
	ft_lst_push_b(a, b);
	ft_printf("a: %d\n", (*a)->nb);
	while (ft_stack_last(*a)->pos != 3)
	{
		if ((*a)->nb < ft_min(b) || (*a)->nb > ft_max(b))
		{
			ft_printf("a: %d\n", (*a)->nb);
			while (ft_max_pos(b) != 1)
			{
				ft_printf("b: %d\n", (*b)->nb);
				if (ft_max_pos(b) > ft_median(b))
					ft_lst_reverse_rotate_b(b);
				else
					ft_lst_rotate_b(b);
			}
			ft_lst_push_b(a, b);
		}
		else
		{
			ft_lowest_cost(a, b, &nbr_a, &nbr_b);
			ft_printf("nbr_a: %d, nbr_b = %d\n", nbr_a, nbr_b);
			while ((*b)->nb != nbr_a)
				ft_move(a, b, nbr_a, nbr_b);
		}
	}
	ft_sort_three(a);
	while ((*b)->nb != ft_max(b))
	{
		if (ft_find_pos(b, ft_max(b)) > ft_median(b))
			ft_lst_reverse_rotate_b(b);
		else
			ft_lst_rotate_b(b);
	}
	while (*b)
	{
		int nbr = ft_target_a(a, (*b)->nb);
		ft_printf("nbr: %d\n", nbr);
		while ((*a)->nb != nbr)
		{
			if (ft_find_pos(a, nbr) > ft_median(a))
				ft_lst_reverse_rotate_a(a);
			else
				ft_lst_rotate_a(a);
		}
		ft_lst_push_a(b, a);
	}
	while ((*a)->nb != ft_min(a))
	{
		ft_printf("a: %d\n", (*a)->nb);
		if (ft_find_pos(a, ft_min(a)) > ft_median(a))
			ft_lst_reverse_rotate_a(a);
		else
			ft_lst_rotate_a(a);
	}
}

void	ft_move(t_stack **a, t_stack **b, int nbr_a, int nbr_b)
{
	int	pos_a;
	int	pos_b;
	int	median_a;
	int	median_b;

	pos_a = ft_find_pos(a, nbr_a);
	pos_b = ft_find_pos(b, nbr_b);
	median_a = ft_median(a);
	median_b = ft_median(b);
	ft_printf("pos_a: %d, pos_b: %d\n", pos_a, pos_b);
	if (pos_a == 1 && pos_b == 1)
		ft_lst_push_b(a, b);
	else if (pos_a == 1 && pos_b > 1)
	{
		if (pos_b > median_b)
			ft_lst_reverse_rotate_b(b);
		else
			ft_lst_rotate_b(b);
	}
	else if (pos_b == 1 && pos_a > 1)
	{
		if (pos_a > median_a)
			ft_lst_reverse_rotate_a(a);
		else
			ft_lst_rotate_a(a);
	}
	else
	{
		if (pos_a > median_a && pos_b > median_b)
			ft_lst_reverse_rotate_both(a, b);
		else if (pos_a > median_a && pos_b < median_b)
		{
			ft_lst_reverse_rotate_a(a);
			ft_lst_rotate_b(b);
		}
		else if (pos_a < median_a && pos_b > median_b)
		{
			ft_lst_rotate_a(a);
			ft_lst_reverse_rotate_b(b);
		}
		else
			ft_lst_rotate_both(a, b);
	}
}

void	ft_lowest_cost(t_stack **a, t_stack **b, int *nbr_a, int *nbr_b)
{
	t_stack	*tmp;
	int		cost;
	int		tmp_cost;
	int		nbr;

	tmp = *a;
	cost = 2147483647;
	while (tmp)
	{
		nbr = ft_target(b, tmp->nb);
		ft_printf("nbr: %d\n", nbr);
		tmp_cost = ft_cost(a, b, tmp->nb, nbr);
		if (cost > tmp_cost)
		{
			cost = tmp_cost;
			*nbr_a = tmp->nb;
			*nbr_b = nbr;
		}
		tmp = tmp->next;
	}
}

int	ft_target(t_stack **stack, int nbr)
{
	t_stack	*tmp;
	int		lowest;

	tmp = *stack;
	lowest = tmp->nb;
	while (tmp)
	{
		ft_printf("lowest = %d\n", lowest);
		if (tmp->nb > lowest && tmp->nb < nbr)
			lowest = tmp->nb;
		tmp = tmp->next;
	}
	return (lowest);
}

int	ft_target_a(t_stack **stack, int nbr)
{
	t_stack	*tmp;
	int		max;

	tmp = *stack;
	max = 2147483647;
	while (tmp)
	{
		ft_printf("max = %d\n", max);
		if (tmp->nb < max && tmp->nb > nbr)
			max = tmp->nb;
		tmp = tmp->next;
	}
	return (max);
}

int	ft_cost(t_stack **a, t_stack **b, int nbr_a, int nbr_b)
{
	int	pos_a;
	int	pos_b;
	int	len_a;
	int	len_b;

	pos_a = ft_find_pos(a, nbr_a);
	pos_b = ft_find_pos(b, nbr_b);
	len_a = ft_stack_last(*a)->pos;
	len_b = ft_stack_last(*b)->pos;
	ft_printf("pos_a: %d, pos_b: %d\n", pos_a, pos_b);
	if (pos_a > ft_median(a) && pos_b > ft_median(b))
		return (ft_max_cost(len_a - pos_a + 1, len_b - pos_b + 1));
	else if (pos_a > ft_median(a) && pos_b < ft_median(b))
		return (len_a - pos_a + 1 + pos_b);
	else if (pos_a < ft_median(a) && pos_b > ft_median(b))
		return (pos_a + len_b - pos_b + 1);
	else
		return (ft_max_cost(pos_a, pos_b));
}

int	ft_max_cost(int cost_a, int cost_b)
{
	if (cost_a > cost_b)
		return (cost_a);
	else
		return (cost_b);
}
int	ft_find_pos(t_stack **stack, int nbr)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp->nb != nbr)
		tmp = tmp->next;
	return (tmp->pos);
}
