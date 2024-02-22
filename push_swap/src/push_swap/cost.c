/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkane <mkane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 05:42:05 by kane              #+#    #+#             */
/*   Updated: 2024/02/21 20:28:49 by mkane            ###   ########.fr       */
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

int	ft_compare_cost(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_cheaper_move(t_cost cost)
{
	int	cheaper;

	cheaper = cost.ra_rb;
	if (cost.rra_rrb < cheaper)
		cheaper = cost.rra_rrb;
	if (cost.rra_rb < cheaper)
		cheaper = cost.rra_rb;
	if (cost.ra_rrb < cheaper)
		cheaper = cost.ra_rrb;
	return (cheaper);
}
