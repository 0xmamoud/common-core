/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kane <kane@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 23:21:50 by mkane             #+#    #+#             */
/*   Updated: 2024/01/29 15:44:29 by kane             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int		median;
	int		min_pos;
	int		min;

	while (ft_stack_last((*stack_a))->pos != 3)
	{
		median = ft_median(stack_a);
		min_pos = ft_min_pos(stack_a);
		min = ft_min(stack_a);
		while ((*stack_a)->nb != min)
		{
			if (min_pos > median)
				ft_lst_reverse_rotate_a(stack_a);
			else
				ft_lst_rotate_a(stack_a);
		}
		ft_lst_push_b(stack_a, stack_b);
	}
	ft_sort_three(stack_a);
	while (*stack_b)
		ft_lst_push_a(stack_b, stack_a);
}
