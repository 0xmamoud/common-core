/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_argv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkane <mkane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 20:06:43 by mkane             #+#    #+#             */
/*   Updated: 2024/03/21 17:42:47 by mkane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

char	*join_argv(int argc, char **argv)
{
	char	*tmp;

	if (argc == 2)
		return (argv[1]);
	char *(tab) = ft_strdup("");
	if (!ft_isjoinable(argv) || !tab)
		return (NULL);
	int (i) = 0;
	while (++i < argc)
	{
		tmp = ft_strjoin(tab, argv[i]);
		if (!tmp)
			return (free(tab), NULL);
		free(tab);
		tab = tmp;
		if (i < argc - 1)
		{
			tmp = ft_strjoin(tab, " ");
			if (!tmp)
				return (free(tab), NULL);
			free(tab);
			tab = tmp;
		}
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
