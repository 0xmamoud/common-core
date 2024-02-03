/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kane <kane@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 20:36:22 by kane              #+#    #+#             */
/*   Updated: 2024/02/03 05:35:01 by kane             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_sort(t_stack **a, t_stack **b)
{
	int	nbr_a;
	int	nbr_b;

	ft_lst_push_b(a, b);
	ft_lst_push_b(a, b);
	while (ft_stack_last(*a)->pos != 3)
	{
		if ((*a)->nb < ft_min(b) || (*a)->nb > ft_max(b))
		{
			ft_rotate_to_top_b(b, ft_max_pos(b));
			ft_lst_push_b(a, b);
		}
		else
		{
			ft_lowest_cost(a, b, &nbr_a, &nbr_b);
			int pos_a = ft_find_pos(a, nbr_a);
			int pos_b = ft_find_pos(b, nbr_b);
			ft_rotate_to_top_a(a, pos_a);
			ft_rotate_to_top_b(b, pos_b);
			ft_lst_push_b(a, b);
		}
	}
	ft_sort_three(a);
	ft_rotate_to_top_b(b, ft_max_pos(b));
	ft_lst_push_a(b, a);
	while ((*b))
	{
		int test = ft_target_a(a, (*b)->nb);
		ft_rotate_to_top_a(a, ft_find_pos(a, test));
		ft_lst_push_a(b, a);
	}
}

void	ft_rotate_to_top_b(t_stack **stack, int pos)
{
	int	median;
	int	len;

	len = ft_stack_last(*stack)->pos;
	median = ft_median(stack);
	if (pos > median)
	{
		while (pos <= len)
		{
			ft_lst_reverse_rotate_b(stack);
			pos++;
		}
	}
	else
	{
		while (pos > 1)
		{
			ft_lst_rotate_b(stack);
			pos--;
		}
	}
}

void	ft_rotate_to_top_a(t_stack **stack, int pos)
{
	int	median;
	int	len;

	len = ft_stack_last(*stack)->pos;
	median = ft_median(stack);
	if (pos > median)
	{
		while (pos <= len)
		{
			ft_lst_reverse_rotate_a(stack);
			pos++;
		}
	}
	else
	{
		while (pos > 1)
		{
			ft_lst_rotate_a(stack);
			pos--;
		}
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
	lowest = -2147483648;
	while (tmp)
	{
		if (tmp->nb > lowest && tmp->nb <= nbr)
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

	pos_a = ft_find_pos(a, nbr_a);
	pos_b = ft_find_pos(b, nbr_b);
	if (pos_a > ft_median(a) && pos_b > ft_median(b))
		return (ft_max_cost(ft_reverse_pos(a, pos_a), ft_reverse_pos(b, pos_b)));
	else if (pos_a > ft_median(a) && pos_b < ft_median(b))
		return (ft_reverse_pos(a, pos_a) + pos_b);
	else if (pos_a < ft_median(a) && pos_b > ft_median(b))
		return (pos_a + ft_reverse_pos(b, pos_b));
	else
		return (ft_max_cost(pos_a, pos_b));
}

int	ft_reverse_pos(t_stack **stack, int pos)
{
	int	len;
	int	i;

	len = ft_stack_last(*stack)->pos;
	i = 1;
	while (pos <= len)
	{
		pos++;
		i++;
	}
	return (i);
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
