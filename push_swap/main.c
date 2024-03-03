/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kane <kane@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 02:27:47 by mkane             #+#    #+#             */
/*   Updated: 2024/03/03 21:05:12 by kane             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*tab;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	tab = join_argv(argc, argv);
	if (!parsing(tab))
	{
		write(2, "Error\n", 6);
		if (argc > 2)
			free(tab);
		return (0);
	}
	stack_a = ft_fill_stack_a(tab);
	if (argc > 2)
		free(tab);
	ft_push_swap(&stack_a, &stack_b);
	ft_free_stack(stack_a);
	return (0);
}
