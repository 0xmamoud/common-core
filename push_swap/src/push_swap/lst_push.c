/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkane <mkane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 19:07:12 by mkane             #+#    #+#             */
/*   Updated: 2024/02/22 02:49:54 by mkane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_lst_push(t_stack **src, t_stack **dst)
{
	t_stack	*tmp;

	if (!src || !*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = NULL;
	ft_stack_add_front(dst, tmp);
	ft_update_index(src);
	ft_update_index(dst);
}

void	ft_lst_push_a(t_stack **src, t_stack **dst)
{
	ft_lst_push(src, dst);
	ft_printf("pa\n");
}

void	ft_lst_push_b(t_stack **src, t_stack **dst)
{
	ft_lst_push(src, dst);
	ft_printf("pb\n");
}
