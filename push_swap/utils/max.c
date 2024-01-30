/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kane <kane@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:02:04 by kane              #+#    #+#             */
/*   Updated: 2024/01/29 15:04:16 by kane             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_max(t_stack **stack)
{
	int		max;
	t_stack	*tmp;

	tmp = *stack;
	max = tmp->nb;
	while (tmp)
	{
		if (tmp->nb > max)
			max = tmp->nb;
		tmp = tmp->next;
	}
	return (max);
}

int	ft_max_pos(t_stack **stack)
{
	int		max;
	int		pos;
	t_stack	*tmp;

	tmp = *stack;
	max = tmp->nb;
	pos = tmp->pos;
	while (tmp)
	{
		if (tmp->nb > max)
		{
			max = tmp->nb;
			pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (pos);
}
