/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkane <mkane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 02:27:47 by mkane             #+#    #+#             */
/*   Updated: 2023/12/24 21:51:36 by mkane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_env	env;
	char	*tab;

	env.stack_a = NULL;
	env.stack_b = NULL;
	if (argc < 2)
		return (0);
	tab = join_argv(argc, argv);
	if (!parsing(tab))
	{
		ft_printf("Error\n");
		free(tab);
		return (0);
	}
	env.stack_a = ft_fill_stack_a(tab);
	ft_lst_push(&env.stack_a, &env.stack_b);
	ft_lst_push(&env.stack_a, &env.stack_b);
	ft_lst_push(&env.stack_a, &env.stack_b);
	// ft_lst_swap_both(&env.stack_a, &env.stack_b);
	ft_lst_reverse_rotate_both(&env.stack_a, &env.stack_b);
	t_stack *current = env.stack_a;
	t_stack *current2 = env.stack_b;
	while (current)
	{
		ft_printf("nbr = %d || pos = %d\n", current->nb, current->pos);
		current = current->next;
	}
	ft_printf("\n===============================\n");
	while (current2)
	{
		ft_printf("nbr = %d || pos = %d\n", current2->nb, current2->pos);
		current2 = current2->next;
	}
	ft_free_stack(current);
	ft_free_stack(current2);
	ft_free_stack(env.stack_a);
	ft_free_stack(env.stack_b);
	return (0);
}
