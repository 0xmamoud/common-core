/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvements_case.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kane <kane@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 02:15:06 by kane              #+#    #+#             */
/*   Updated: 2024/02/06 07:00:17 by kane             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_rra_rrb(t_stack **a, t_stack **b, int pos_a, int pos_b)
{
	pos_a = ft_reverse_pos(a, pos_a);
	pos_b = ft_reverse_pos(b, pos_b);
	while (pos_a > 1 && pos_b > 1)
	{
		ft_lst_reverse_rotate_both(a, b);
		pos_a--;
		pos_b--;
	}
	if (pos_a > 1)
	{
		while (pos_a > 1)
		{
			ft_lst_reverse_rotate_a(a);
			pos_a--;
		}
	}
	else
	{
		while (pos_b > 1)
		{
			ft_lst_reverse_rotate_b(b);
			pos_b--;
		}
	}
}

void	ft_rra_rb(t_stack **a, t_stack **b, int pos_a, int pos_b)
{
	pos_a = ft_reverse_pos(a, pos_a);
	while (pos_a > 1 && pos_b > 1)
	{
		ft_lst_reverse_rotate_a(a);
		ft_lst_rotate_b(b);
		pos_a--;
		pos_b--;
	}
	if (pos_a > 1)
	{
		while (pos_a > 1)
		{
			ft_lst_reverse_rotate_a(a);
			pos_a--;
		}
	}
	else
	{
		while (pos_b > 1)
		{
			ft_lst_rotate_b(b);
			pos_b--;
		}
	}
}

void	ft_ra_rrb(t_stack **a, t_stack **b, int pos_a, int pos_b)
{
	pos_b = ft_reverse_pos(b, pos_b);
	while (pos_a > 1 && pos_b > 1)
	{
		ft_lst_rotate_a(a);
		ft_lst_reverse_rotate_b(b);
		pos_a--;
		pos_b--;
	}
	if (pos_a > 1)
	{
		while (pos_a > 1)
		{
			ft_lst_rotate_a(a);
			pos_a--;
		}
	}
	else
	{
		while (pos_b > 1)
		{
			ft_lst_reverse_rotate_b(b);
			pos_b--;
		}
	}
}

void	ft_ra_rb(t_stack **a, t_stack **b, int pos_a, int pos_b)
{
	while (pos_a > 1 && pos_b > 1)
	{
		ft_lst_rotate_both(a, b);
		pos_a--;
		pos_b--;
	}
	if (pos_a > 1)
	{
		while (pos_a > 1)
		{
			ft_lst_rotate_a(a);
			pos_a--;
		}
	}
	else
	{
		while (pos_b > 1)
		{
			ft_lst_rotate_b(b);
			pos_b--;
		}
	}
}
