/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkane <mkane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 21:41:38 by mkane             #+#    #+#             */
/*   Updated: 2024/03/21 20:51:34 by mkane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static	int	ft_movement(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (ft_strncmp(line, "sa\n", 4) == 0)
		return (ft_lst_swap(stack_a), 1);
	else if (ft_strncmp(line, "sb\n", 4) == 0)
		return (ft_lst_swap(stack_b), 1);
	else if (ft_strncmp(line, "ss\n", 4) == 0)
		return (ft_lst_swap(stack_a), ft_lst_swap(stack_b), 1);
	else if (ft_strncmp(line, "pa\n", 4) == 0)
		return (ft_lst_push(stack_b, stack_a), 1);
	else if (ft_strncmp(line, "pb\n", 4) == 0)
		return (ft_lst_push(stack_a, stack_b), 1);
	else if (ft_strncmp(line, "ra\n", 4) == 0)
		return (ft_lst_rotate(stack_a), 1);
	else if (ft_strncmp(line, "rb\n", 4) == 0)
		return (ft_lst_rotate(stack_b), 1);
	else if (ft_strncmp(line, "rr\n", 4) == 0)
		return (ft_lst_rotate(stack_a), ft_lst_rotate(stack_b), 1);
	else if (ft_strncmp(line, "rra\n", 5) == 0)
		return (ft_lst_reverse_rotate(stack_a), 1);
	else if (ft_strncmp(line, "rrb\n", 5) == 0)
		return (ft_lst_reverse_rotate(stack_b), 1);
	else if (ft_strncmp(line, "rrr\n", 5) == 0)
		return (ft_lst_reverse_rotate(stack_a), \
		ft_lst_reverse_rotate(stack_b), 1);
	return (0);
}

static int	ft_checker(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (ft_movement(stack_a, stack_b, line))
			free(line);
		else
		{
			ft_free_stack(*stack_a);
			if (*stack_b)
				ft_free_stack(*stack_b);
			write(2, "Error\n", 6);
			free(line);
			exit(1);
		}
		line = get_next_line(0);
	}
	if (!ft_check_sorted(stack_a) || *stack_b)
		return (0);
	return (ft_printf("OK\n"), 1);
}

static void	ft_exit(t_stack **stack_a, t_stack **stack_b)
{
	ft_free_stack(*stack_a);
	if (*stack_b)
		ft_free_stack(*stack_b);
	write(2, "KO\n", 3);
	exit(0);
}

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
	if (!ft_checker(&stack_a, &stack_b))
		ft_exit(&stack_a, &stack_b);
	ft_free_stack(stack_a);
	return (0);
}
