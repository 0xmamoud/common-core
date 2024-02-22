/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkane <mkane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:05:33 by mkane             #+#    #+#             */
/*   Updated: 2024/02/22 04:00:26 by mkane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	ft_movement(int keycode, t_data *data)
{
	if (keycode == ESC)
		ft_close(data);
	if (keycode == W || keycode == UP)
		ft_move(data, data->player_pos.pos_x - 1, data->player_pos.pos_y);
	if (keycode == S || keycode == DOWN)
		ft_move(data, data->player_pos.pos_x + 1, data->player_pos.pos_y);
	if (keycode == A || keycode == LEFT)
		ft_move(data, data->player_pos.pos_x, data->player_pos.pos_y - 1);
	if (keycode == D || keycode == RIGHT)
		ft_move(data, data->player_pos.pos_x, data->player_pos.pos_y + 1);
	return (0);
}

void	ft_move(t_data *data, int x, int y)
{
	if (data->map[x][y] == '1')
		return ;
	data->map[data->player_pos.pos_x][data->player_pos.pos_y] = '0';
	if (data->map[x][y] == 'E')
	{
		if (data->count.collectible == 0)
			ft_close(data);
		else
			return ;
	}
	data->player_pos.pos_x = x;
	data->player_pos.pos_y = y;
	if (data->map[x][y] == 'C')
		data->count.collectible--;
	data->map[x][y] = 'P';
	data->move++;
	ft_fill_window(data);
}
