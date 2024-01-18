/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_over_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkane <mkane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 23:21:50 by mkane             #+#    #+#             */
/*   Updated: 2024/01/19 00:28:50 by mkane            ###   ########.fr       */
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

int	ft_lowest_upper(t_stack **stack, int nbr)
{
	t_stack	*tmp;
	int		preview;

	tmp = *stack;
	preview = nbr;
	while (tmp)
	{
		if (tmp->nb < nbr)
			nbr = tmp->nb;
		tmp = tmp->next;
	}
	if (preview == nbr)
		return (1);
	return (0);
}

int	ft_find_cost_b(t_stack **stack_b, int nbr)
{
	t_stack	*tmp;
	int		cost;

	tmp = *stack_b;
	while (tmp)
	{
		if (tmp->nb < nbr && ft_lowest_upper(stack_b, tmp->nb) == 1)
			cost = tmp->pos;
		tmp = tmp->next;
	}
	return (cost);
}

int	ft_lower_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmpa;
	t_stack	*tmpb;
	int		cost;
	int		tmp_cost;

	tmpa = *stack_a;
	tmpb = *stack_b;
	cost = 0;
	while (tmpa)
	{
		tmp_cost = tmpa->pos + ft_find_cost_b(stack_b, tmpa->nb);
		if (tmp_cost < cost)
			cost = tmp_cost;
		tmpa = tmpa->next;
	}
	return (cost);
}
