/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_case.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkane <mkane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:59:51 by mkane             #+#    #+#             */
/*   Updated: 2024/01/18 21:31:19 by mkane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_three_case(t_stack **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->nb;
	second = (*stack_a)->next->nb;
	third = (*stack_a)->next->next->nb;
	if (first > second && second > third && first > third)
	{
		ft_lst_rotate_a(stack_a);
		ft_lst_swap_a(stack_a);
	}
	else if ((first > second && second < third && first > third)
		|| (first > second && first < third && second < third))
		ft_lst_swap_a(stack_a);
	else if (first < second && first > third && second > third)
	{
		ft_lst_rotate_a(stack_a);
		ft_lst_rotate_a(stack_a);
	}
	else if (first < second && first < third && second > third)
	{
		ft_lst_swap_a(stack_a);
		ft_lst_rotate_a(stack_a);
	}
}
