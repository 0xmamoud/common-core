/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_over_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkane <mkane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 23:21:50 by mkane             #+#    #+#             */
/*   Updated: 2024/01/23 20:58:19 by mkane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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

int	ft_find_cost_b(t_stack **stack_b, int nbr)
{
	t_stack	*tmp;
	int		cost;
	int		max;

	tmp = *stack_b;
	cost = 0;
	max = tmp->nb;
	while (tmp)
	{
		if (tmp->nb < nbr && tmp->nb > max)
		{
			max = tmp->nb;
			cost = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (cost);
}

int	ft_lower_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmpa;
	int		cost;
	int		tmp_cost;

	tmpa = *stack_a;
	cost = 2147483647;
	while (tmpa)
	{
		ft_printf("cost = %d\n", cost);
		tmp_cost = tmpa->pos + ft_find_cost_b(stack_b, tmpa->nb);
		if (tmp_cost < cost)
			cost = tmp_cost;
		tmpa = tmpa->next;
	}
	return (cost);
}

int	ft_min(t_stack **stack)
{
	t_stack	*tmp;
	int		min;

	tmp = *stack;
	min = tmp->nb;
	if (ft_stack_last(tmp)->pos == 1)
		return (min);
	while (tmp)
	{
		if (tmp->nb < min)
			min = tmp->nb;
		tmp = tmp->next;
	}
	return (min);
}

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

void	ft_sort(t_stack **stack_a, t_stack ** stack_b)
{
	t_stack	*tmpa;
	int 	min;
	
	tmpa = *stack_a;
	while (ft_stack_last(*stack_a)->pos != 1)
	{
		min = ft_min(stack_a);
		while (tmpa->nb != min)
		{
			ft_lst_rotate_a(stack_a);
			tmpa = *stack_a;
		}
		ft_lst_push_a(stack_a, stack_b);
	}
	ft_lst_push_a(stack_a, stack_b);
	while (ft_stack_last(*stack_b)->pos != 1)
		ft_lst_push_b(stack_b, stack_a);
	ft_lst_push_b(stack_b, stack_a);
}
