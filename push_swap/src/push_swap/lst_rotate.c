/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkane <mkane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 21:21:07 by mkane             #+#    #+#             */
/*   Updated: 2024/02/21 01:14:45 by mkane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_lst_rotate(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	ft_stack_add_back(stack, tmp);
	*stack = (*stack)->next;
	tmp->next = NULL;
	ft_update_index(stack);
}

void	ft_lst_rotate_a(t_stack **stack)
{
	ft_lst_rotate(stack);
	ft_printf("ra\n");
}

void	ft_lst_rotate_b(t_stack **stack)
{
	ft_lst_rotate(stack);
	ft_printf("rb\n");
}

void	ft_lst_rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	ft_lst_rotate(stack_a);
	ft_lst_rotate(stack_b);
	ft_printf("rr\n");
}
