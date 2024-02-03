/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kane <kane@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:48:56 by mkane             #+#    #+#             */
/*   Updated: 2024/02/03 21:14:27 by kane             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_push_swap(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	tmp = *stack_a;
	if (ft_check_sorted(stack_a))
		return ;
	if (ft_stack_last(tmp)->pos == 3)
		ft_sort_three(stack_a);
	else if (ft_stack_last(tmp)->pos == 5)
		ft_sort_five(stack_a, stack_b);
	else
		ft_sort(stack_a, stack_b);

}
