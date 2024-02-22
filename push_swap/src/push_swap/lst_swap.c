/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkane <mkane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 18:09:38 by mkane             #+#    #+#             */
/*   Updated: 2024/02/21 01:15:27 by mkane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_lst_swap(t_stack **stack)
{
	int		nbr1;
	int		nbr2;
	t_stack	*tmp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	nbr1 = tmp->nb;
	nbr2 = tmp->next->nb;
	tmp->nb = nbr2;
	tmp->next->nb = nbr1;
	ft_update_index(stack);
}

void	ft_lst_swap_a(t_stack **stack)
{
	ft_lst_swap(stack);
	ft_printf("sa\n");
}

void	ft_lst_swap_b(t_stack **stack)
{
	ft_lst_swap(stack);
	ft_printf("sb\n");
}

void	ft_lst_swap_both(t_stack **stack_a, t_stack **stack_b)
{
	ft_lst_swap(stack_a);
	ft_lst_swap(stack_b);
	ft_printf("ss\n");
}
