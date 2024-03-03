/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kane <kane@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 05:42:05 by kane              #+#    #+#             */
/*   Updated: 2024/03/03 22:10:17 by kane             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_cost(t_stack **a, t_stack **b, int *nbr_a, int *nbr_b)
{
	t_stack	*tmp;
	int		nbr;
	int		cost;
	int		tmp_cost;

	tmp = *a;
	*nbr_a = tmp->nb;
	*nbr_b = (*b)->nb;
	cost = 2147483647;
	while (tmp)
	{
		nbr = ft_target_nbr_b(tmp->nb, b);
		tmp_cost = ft_min_cost(a, b, tmp->nb, nbr);
		if (tmp_cost < cost)
		{
			cost = tmp_cost;
			*nbr_a = tmp->nb;
			*nbr_b = nbr;
		}
		tmp = tmp->next;
	}
}

int	ft_target_nbr_b(int nbr, t_stack **b)
{
	t_stack	*tmp;
	int		nbr_b;
	int		diff;

	tmp = *b;
	nbr_b = ft_max(b);
	diff = 2147483647;
	while (tmp)
	{
		if (nbr - tmp->nb < diff && nbr > tmp->nb)
		{
			diff = nbr - tmp->nb;
			nbr_b = tmp->nb;
		}
		tmp = tmp->next;
	}
	return (nbr_b);
}

void	ft_cost_a(t_stack **a, t_stack **b, int *nbr_a, int *nbr_b)
{
	t_stack	*tmp;
	int		nbr;
	int		cost;
	int		tmp_cost;

	tmp = *b;
	*nbr_a = ft_min(a);
	*nbr_b = ft_max(b);
	cost = 2147483647;
	while (tmp)
	{
		nbr = ft_target_nbr_a(tmp->nb, a);
		tmp_cost = ft_min_cost(a, b, nbr, tmp->nb);
		if (tmp_cost < cost)
		{
			cost = tmp_cost;
			*nbr_b = tmp->nb;
			*nbr_a = nbr;
		}
		tmp = tmp->next;
	}
}

int	ft_target_nbr_a(int nbr, t_stack **a)
{
	t_stack	*tmp;
	int		nbr_a;
	int		diff;

	tmp = *a;
	nbr_a = ft_min(a);
	diff = 2147483647;
	while (tmp)
	{
		if (tmp->nb - nbr < diff && tmp->nb > nbr)
		{
			diff = tmp->nb - nbr;
			nbr_a = tmp->nb;
		}
		tmp = tmp->next;
	}
	return (nbr_a);
}

int	ft_min_cost(t_stack **a, t_stack **b, int nbr_a, int nbr_b)
{
	t_cost	cost;
	int		pos_a;
	int		pos_b;

	pos_a = ft_find_pos(a, nbr_a);
	pos_b = ft_find_pos(b, nbr_b);
	cost.ra_rb = ft_compare_cost(pos_a, pos_b);
	cost.rra_rrb = ft_compare_cost(ft_reverse_pos(a, pos_a),
			ft_reverse_pos(b, pos_b));
	cost.rra_rb = ft_reverse_pos(a, pos_a) + pos_b ;
	cost.ra_rrb = pos_a + ft_reverse_pos(b, pos_b);
	return (ft_cheaper_move(cost));
}
