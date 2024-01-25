/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_over_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kane <kane@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 23:21:50 by mkane             #+#    #+#             */
/*   Updated: 2024/01/25 21:17:27 by kane             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_find_max_min(t_stack **stack, int nbr)
{
	t_stack	*tmp;
	int		min;
	int		cost;

	tmp = *stack;
	cost = tmp->pos;
	min = tmp->nb;
	if (ft_stack_last(tmp)->pos == 1)
		return (cost);
	while (tmp)
	{
		if (tmp->nb > min && tmp->nb < nbr)
		{
			min = tmp->nb;
			cost = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (cost);
}

int	ft_lowest_nbr(t_stack **stack_a, t_stack **stack_b, int *pos)
{
	t_stack	*tmpa;
	int		tmp_cost;
	int		cost;
	int		nbr;

	tmpa = *stack_a;
	cost = 2147483647;
	nbr = tmpa->nb;
	while (tmpa)
	{
		tmp_cost = tmpa->pos + ft_find_max_min(stack_b, tmpa->nb);
		if (tmp_cost < cost)
		{
			cost = tmp_cost;
			nbr = tmpa->nb;
			*pos = tmp_cost - tmpa->pos;
		}
		tmpa = tmpa->next;
	}
	return (nbr);
}

void	ft_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmpa;
	int		cost;
	int		pos;

	tmpa = *stack_a;
	ft_lst_push_b(stack_a, stack_b);
	ft_lst_push_b(stack_a, stack_b);
	while (ft_stack_last(*stack_a)->pos != 1)
	{
		pos = ft_lowest_nbr(stack_a, stack_b, &cost);
		while (tmpa->nb != pos)
		{
			if (cost > 0)
			{
				ft_lst_rotate_both(stack_a, stack_b);
				cost--;
			}
			else
				ft_lst_rotate_a(stack_a);
			tmpa = *stack_a;
		}
		while (cost > 0)
		{
			ft_lst_rotate_b(stack_b);
			cost--;
		}
		ft_lst_push_b(stack_a, stack_b);
	}
	ft_lst_push_b(stack_a, stack_b);
	while (ft_stack_last(*stack_b)->pos != 1)
		ft_lst_push_a(stack_b, stack_a);
	ft_lst_push_a(stack_b, stack_a);
}

int	ft_min(t_stack **stack)
{
	t_stack	*tmp;
	int		min;

	tmp = *stack;
	min = tmp->nb;
	while (tmp)
	{
		if (tmp->nb < min)
			min = tmp->nb;
		tmp = tmp->next;
	}
	return (min);
}

// void	ft_sort(t_stack **stack_a, t_stack ** stack_b)
// {
// 	t_stack	*tmpa;
// 	int		min;

// 	tmpa = *stack_a;
// 	while (ft_stack_last(*stack_a)->pos != 1)
// 	{
// 		min = ft_min(stack_a);
// 		while (tmpa->nb != min)
// 		{
// 			ft_lst_rotate_a(stack_a);
// 			tmpa = *stack_a;
// 		}
// 		ft_lst_push_a(stack_a, stack_b);
// 	}
// 	ft_lst_push_a(stack_a, stack_b);
// 	while (ft_stack_last(*stack_b)->pos != 1)
// 		ft_lst_push_b(stack_b, stack_a);
// 	ft_lst_push_b(stack_b, stack_a);
// }

int	ft_check_sort(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp->next)
	{
		if (tmp->nb > tmp->next->nb)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	ft_get_median(t_stack **stack)
{
	t_stack	*tmp;
	int		median;
	int		max;

	tmp = *stack;
	max = ft_stack_last(tmp)->pos;
	median = max / 2;
	return (median);
}

