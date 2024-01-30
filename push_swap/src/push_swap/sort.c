/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kane <kane@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 20:36:22 by kane              #+#    #+#             */
/*   Updated: 2024/01/30 01:33:12 by kane             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	nbr_a;
	int	nbr_b;
	int	min;
	int	max;

	min = ft_min(stack_a);
	max = ft_max(stack_a);
	ft_lst_push_b(stack_a, stack_b);
	ft_lst_push_b(stack_a, stack_b);
	while (*stack_a)
	{
		if ((*stack_a)->nb == min)
		{
			ft_lst_push_b(stack_a, stack_b);
			ft_lst_rotate_b(stack_b);
		}
		else if ((*stack_a)->nb == max)
			ft_lst_push_b(stack_a, stack_b);
		else
		{
			ft_lowest_cost(stack_a, stack_b, &nbr_a, &nbr_b);
			ft_rotation(stack_a, stack_b, nbr_a, nbr_b);
			ft_lst_push_b(stack_a, stack_b);
		}
	}
	while (*stack_b)
	{
		if ((*stack_b)->nb == ft_max(stack_b))
			ft_lst_push_a(stack_b, stack_a);
		else if ((*stack_b)->pos != ft_max(stack_b))
		{
			if (ft_max(stack_b) < ft_median(stack_b))
				ft_lst_reverse_rotate_b(stack_b);
			else
				ft_lst_rotate_b(stack_b);
		}
		else
			ft_lst_rotate_b(stack_b);
	}
}

void	ft_rotation(t_stack **a, t_stack **b, int nbr_a, int nbr_b)
{

	int		pos_a;
	int		pos_b;

	pos_a = ft_find_pos(a, nbr_a);
	pos_b = ft_find_pos(b, nbr_b);
	while (pos_a > 0)
	{
		if (pos_a > ft_median(a))
			ft_lst_reverse_rotate_a(a);
		else
			ft_lst_rotate_a(a);
		pos_a--;
	}
	while (pos_b > 0)
	{
		if (pos_b > ft_median(b))
			ft_lst_reverse_rotate_b(b);
		else
			ft_lst_rotate_b(b);
		pos_b--;
	}
}

int	ft_find_pos(t_stack **stack, int nbr)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp->nb != nbr)
		tmp = tmp->next;
	return (tmp->pos);
}

void	ft_lowest_cost(t_stack **a, t_stack **b, int *na, int *nb)
{
	t_stack	*tmp;
	int		cost;
	int		nbr;
	int		nbr_a;
	int		nbr_b;

	tmp = *a;
	cost = 2147483647;
	while (tmp)
	{
		nbr = ft_lowest_nbr(b, tmp->nb);
		if (cost > ft_cost(a, b, tmp->nb, nbr))
		{
			cost = ft_cost(a, b, tmp->nb, nbr);
			nbr_a = tmp->nb;
			nbr_b = nbr;
		}
		tmp = tmp->next;
	}
	*na = nbr_a;
	*nb = nbr_b;
}

int	ft_lowest_nbr(t_stack **stack, int nbr)
{
	t_stack	*tmp;
	int		lowest;

	tmp = *stack;
	lowest = tmp->nb;
	while (tmp)
	{
		if (tmp->nb < nbr && tmp->nb > lowest)
			lowest = tmp->nb;
		tmp = tmp->next;
	}
	return (lowest);
}

int	ft_cost(t_stack **a, t_stack **b, int nbr_a, int nbr_b)
{
	t_stack	*tmpa;
	t_stack	*tmpb;

	tmpa = *a;
	tmpb = *b;
	while (tmpa->nb != nbr_a)
		tmpa = tmpa->next;
	while (tmpb->nb != nbr_b)
		tmpb = tmpb->next;
	if (tmpa->pos < ft_median(a) && tmpb->pos < ft_median(b))
		return (tmpa->pos + tmpb->pos);
	else if (tmpa->pos < ft_median(a) && tmpb->pos > ft_median(b))
		return (tmpa->pos + tmpb->pos + 1 - ft_median(b));
	else if (tmpa->pos > ft_median(a) && tmpb->pos < ft_median(b))
		return (tmpa->pos + tmpb->pos + 1 - ft_median(a));
	else
		return (tmpa->pos + tmpb->pos + 2 - ft_median(a) - ft_median(b));
}
