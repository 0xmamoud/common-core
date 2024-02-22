/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_argv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkane <mkane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 20:06:43 by mkane             #+#    #+#             */
/*   Updated: 2024/02/22 02:59:20 by mkane            ###   ########.fr       */
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
	if (!ft_isjoinable(argv))
		return (NULL);
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

int	ft_isjoinable(char **str)
{
	int	i;
	int	j;

	i = 1;
	while (str[i])
	{
		if (ft_strlen(str[i]) == 0)
			return (0);
		j = 0;
		while (str[i][j] == ' ')
		{
			if (!str[i][j + 1])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
