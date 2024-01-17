/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_argv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkane <mkane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 20:06:43 by mkane             #+#    #+#             */
/*   Updated: 2023/12/24 21:14:20 by mkane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

char	*join_argv(int argc, char **argv)
{
	int		i;
	char	*tab;
	char	*tmp;

	if (argc == 2)
		return (argv[1]);
	i = 1;
	tab = ft_strdup("");
	while (i < argc)
	{
		tmp = ft_strjoin(tab, argv[i]);
		free(tab);
		tab = tmp;
		if (i < argc - 1)
		{
			tmp = ft_strjoin(tab, " ");
			free(tab);
			tab = tmp;
		}
		i++;
	}
	return (tab);
}
