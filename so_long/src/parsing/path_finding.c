/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kane <kane@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 23:15:56 by kane              #+#    #+#             */
/*   Updated: 2024/02/19 00:59:06 by kane             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

char	**copy_map(char **map)
{
	char	**copy;
	int		i;

	i = 0;
	while (map[i])
		i++;
	copy = ft_calloc(i + 1, sizeof(char *));
	i = 0;
	while (map[i])
	{
		copy[i] = ft_strdup(map[i]);
		i++;
	}
	return (copy);
}

void	flood_fill(char **map, int x, int y)
{
	if (map[x][y] == '1' || map[x][y] == 'X')
		return ;
	map[x][y] = 'X';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
	return ;
}

int	path_finding(char **map)
{
	char	**copy;
	int		i;
	int		j;

	copy = copy_map(map);
	flood_fill(copy, 1, 1);
	i = 0;
	while (copy[i])
	{
		j = 0;
		while (copy[i][j])
		{
			if (copy[i][j] != '1' && copy[i][j] != 'X' && copy[i][j] != '0')
			{
				ft_printf("%s\n", PATH_ERROR);
				ft_free_map(copy);
				return (0);
			}
			j++;
		}
		i++;
	}
	ft_free_map(copy);
	return (1);
}
