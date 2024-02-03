/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kane <kane@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 00:20:21 by kane              #+#    #+#             */
/*   Updated: 2024/02/03 00:21:45 by kane             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_check_sorted(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp)
	{
		if (tmp->nb > tmp->next->nb)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
