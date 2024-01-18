/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkane <mkane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 02:27:47 by mkane             #+#    #+#             */
/*   Updated: 2024/01/19 00:25:49 by mkane            ###   ########.fr       */
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
	char *test = "432";
	env.stack_b = ft_fill_stack_a(test);
	// ft_push_swap(&env.stack_a, &env.stack_b);
	ft_printf("%d\n", ft_lower_cost(&env.stack_a, &env.stack_b));
	ft_free_stack(env.stack_a);
	return (0);
}
