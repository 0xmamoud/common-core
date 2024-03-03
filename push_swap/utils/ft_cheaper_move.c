/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cheaper_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kane <kane@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 22:10:04 by kane              #+#    #+#             */
/*   Updated: 2024/03/03 22:15:49 by kane             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
