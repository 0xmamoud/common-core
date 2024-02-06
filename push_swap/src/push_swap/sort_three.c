/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kane <kane@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:59:51 by mkane             #+#    #+#             */
/*   Updated: 2024/02/06 07:07:46 by kane             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_sort_three(t_stack **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->nb;
	second = (*stack_a)->next->nb;
	third = (*stack_a)->next->next->nb;
	if (first > second && first > third && second > third)
	{
		ft_lst_rotate_a(stack_a);
		ft_lst_swap_a(stack_a);
	}
	else if (first > second && first > third && second < third)
		ft_lst_rotate_a(stack_a);
	else if (first < second && first > third && second > third)
		ft_lst_reverse_rotate_a(stack_a);
	else if (first > second && first < third && second < third)
		ft_lst_swap_a(stack_a);
	else if (first < second && first < third && second > third)
	{
		ft_lst_reverse_rotate_a(stack_a);
		ft_lst_swap_a(stack_a);
	}
}
