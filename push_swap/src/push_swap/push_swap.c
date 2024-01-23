/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkane <mkane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:48:56 by mkane             #+#    #+#             */
/*   Updated: 2024/01/23 00:01:07 by mkane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_push_swap(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	(void)stack_b;

	tmp = *stack_a;
	if (ft_stack_last(tmp)->pos == 3)
		ft_three_case(stack_a);
	else
		ft_sort(stack_a, stack_b);

}
