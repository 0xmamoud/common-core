/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_stack_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkane <mkane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 21:56:37 by mkane             #+#    #+#             */
/*   Updated: 2024/03/21 18:42:13 by mkane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*ft_fill_stack_a(char *argv)
{
	t_stack	*stack_a;
	t_stack	*tmp;
	char	**tab;
	int		i;
	int		nb;

	i = 0;
	stack_a = NULL;
	tab = ft_split(argv, ' ');
	if (!tab)
		exit(1);
	while (tab[i])
	{
		nb = ft_atoi(tab[i]);
		tmp = ft_create_stack(nb, i + 1);
		ft_stack_add_back(&stack_a, tmp);
		free(tab[i]);
		i++;
	}
	free(tab);
	return (stack_a);
}
