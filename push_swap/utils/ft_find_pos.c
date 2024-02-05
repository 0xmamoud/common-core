/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kane <kane@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 04:00:47 by kane              #+#    #+#             */
/*   Updated: 2024/02/05 22:14:34 by kane             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_find_pos(t_stack **stack, int nbr)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp)
	{
		if (tmp->nb == nbr)
			break ;
		tmp = tmp->next;
	}
	return (tmp->pos);
}
