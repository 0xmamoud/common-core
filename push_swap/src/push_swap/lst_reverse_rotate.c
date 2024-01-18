/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_reverse_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkane <mkane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 21:36:12 by mkane             #+#    #+#             */
/*   Updated: 2024/01/18 19:28:24 by mkane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_lst_reverse_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = ft_stack_last(*stack);
	ft_stack_add_front(stack, tmp);
	tmp2 = *stack;
	while (tmp2->next != tmp)
		tmp2 = tmp2->next;
	tmp2->next = NULL;
	ft_update_index(stack);
}

void	ft_lst_reverse_rotate_a(t_stack **stack)
{
	ft_lst_reverse_rotate(stack);
	ft_printf("rra\n");
}

void	ft_lst_reverse_rotate_b(t_stack **stack)
{
	ft_lst_reverse_rotate(stack);
	ft_printf("rrb\n");
}

void	ft_lst_reverse_rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	ft_lst_reverse_rotate(stack_a);
	ft_lst_reverse_rotate(stack_b);
	ft_printf("rrr\n");
}
