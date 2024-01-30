/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kane <kane@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:59:04 by kane              #+#    #+#             */
/*   Updated: 2024/01/29 15:18:25 by kane             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_min(t_stack **stack)
{
	int		min;
	t_stack	*tmp;

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

int	ft_min_pos(t_stack **stack)
{
	int		min;
	int		pos;
	t_stack	*tmp;

	tmp = *stack;
	min = tmp->nb;
	pos = tmp->pos;
	while (tmp)
	{
		if (tmp->nb < min)
		{
			min = tmp->nb;
			pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (pos);
}
