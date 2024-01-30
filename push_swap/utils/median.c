/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kane <kane@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:54:33 by kane              #+#    #+#             */
/*   Updated: 2024/01/29 15:21:08 by kane             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_median(t_stack **stack)
{
	int	len;
	int	median;

	len = ft_stack_last(*stack)->pos;

	if (len % 2 == 0)
		median = len / 2;
	else
		median = (len / 2) + 1;
	return (median);
}
