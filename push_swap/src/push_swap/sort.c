/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kane <kane@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 20:36:22 by kane              #+#    #+#             */
/*   Updated: 2024/02/05 23:58:00 by kane             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_sort(t_stack **a, t_stack **b)
{
	int	nbr_a;
	int	nbr_b;

	ft_lst_push_b(a, b);
	ft_lst_push_b(a, b);
	while ((*a))
	{
		if (ft_min(b) > (*a)->nb || ft_max(b) < (*a)->nb)
		{
			ft_mouve_to_top_b(b, ft_max_pos(b));
			ft_lst_push_b(a, b);
		}
		else
		{
			ft_cost(a, b, &nbr_a, &nbr_b);
			ft_mouve_to_top_b(b, ft_find_pos(b, nbr_b));
			ft_mouve_to_top_a(a, ft_find_pos(a, nbr_a));
			ft_lst_push_b(a, b);
		}
	}
	// ft_mouve_to_top_b(b, ft_max_pos(b));
	// ft_lst_push_a(b, a);
	while (*b)
	{
		// int test = ft_target_nbr_a(a, (*b)->nb);
		// ft_mouve_to_top_a(a, ft_find_pos(a, test));
		// ft_lst_push_a(b, a);
		ft_mouve_to_top_b(b, ft_max_pos(b));
		ft_lst_push_a(b, a);
	}
}

void	ft_mouve_to_top_b(t_stack **b, int pos)
{
	while (pos > 1)
	{
		ft_lst_rotate_b(b);
		pos--;
	}
}


void	ft_mouve_to_top_a(t_stack **a, int pos)
{
	while (pos > 1)
	{
		ft_lst_rotate_a(a);
		pos--;
	}
}

int	ft_target_nbr_a(t_stack **a, int nbr)
{
	t_stack	*tmp;
	int		nbr_a;
	int		diff;

	tmp = *a;
	nbr_a = ft_max(a);
	diff = 2147483647;
	while (tmp)
	{
		if (tmp->nb - nbr < diff && diff > 0)
		{
			diff = nbr - tmp->nb;
			nbr_a = tmp->nb;
		}
		tmp = tmp->next;
	}
	return (nbr_a);
}
