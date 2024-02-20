/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkane <mkane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 23:15:56 by kane              #+#    #+#             */
/*   Updated: 2024/02/20 23:15:45 by mkane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	path_finding(t_data *data)
{
	char	**copy;
	int		i;
	int		j;

	copy = copy_map(data->map);
	flood_fill(copy, data->player_pos.pos_x, data->player_pos.pos_y);
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
	if (map[x][y] == 'E')
	{
		map[x][y] = 'X';
		return ;
	}
	map[x][y] = 'X';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
	return ;
}
