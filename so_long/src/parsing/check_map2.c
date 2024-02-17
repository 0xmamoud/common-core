/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kane <kane@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:39:37 by mkane             #+#    #+#             */
/*   Updated: 2024/02/17 23:13:03 by kane             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	ft_check_characters(t_data *data)
{
	int	i;
	int	j;

	ft_count_characters(data);
	if (data->count.collectible < 1 || data->count.exit != 1
		|| data->count.player != 1)
		return (0);
	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] != 'P' && data->map[i][j] != 'E'
				&& data->map[i][j] != 'C' && data->map[i][j] != '1'
				&& data->map[i][j] != '0')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_count_characters(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
			{
				data->player_pos.pos_x = i;
				data->player_pos.pos_y = j;
				data->count.player++;
			}
			else if (data->map[i][j] == 'E')
				data->count.exit++;
			else if (data->map[i][j] == 'C')
				data->count.collectible++;
			j++;
		}
		i++;
	}
}
