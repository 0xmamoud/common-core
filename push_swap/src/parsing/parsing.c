/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkane <mkane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 18:42:57 by mkane             #+#    #+#             */
/*   Updated: 2023/12/24 19:49:40 by mkane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	parsing(char *argv)
{
	char	**tab;
	int		i;

	i = 0;
	if (!ft_check_digit(argv))
		return (0);
	tab = ft_split(argv, ' ');
	if (!ft_check_atoi(tab))
	{
		ft_free_tab(tab);
		return (0);
	}
	ft_free_tab(tab);
	return (1);
}

int	ft_check_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(ft_isdigit(str[i]) || str[i] == '-'
				|| str[i] == '+' || str[i] == ' '))
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_atoi(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		if (ft_long_atoi(str[i]) == -2147483650)
			return (0);
		i++;
	}
	i = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (ft_long_atoi(str[i]) == ft_long_atoi(str[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
