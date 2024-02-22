/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkane <mkane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 02:42:23 by kane              #+#    #+#             */
/*   Updated: 2024/02/22 04:09:12 by mkane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	init_game(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		ft_free_map(data->map);
		free(data->mlx);
		exit(0);
	}
	ft_window_size(data);
	if (data->win_width > WIN_WIDTH || data->win_height > WIN_HEIGHT)
	{
		ft_free_map(data->map);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit(0);
	}
	data->win = mlx_new_window(data->mlx,
			data->win_width, data->win_height, "so_long");
	if (!data->win)
	{
		ft_free_map(data->map);
		free(data->mlx);
		exit(0);
	}
	ft_get_assets(data);
	ft_fill_window(data);
}

void	ft_get_assets(t_data *data)
{
	data->assets.width = 64;
	data->assets.height = 64;
	data->assets.floor = mlx_xpm_file_to_image(data->mlx, FLOOR,
			&data->assets.width, &data->assets.height);
	if (!data->assets.floor)
		ft_clear_assets(data, 0);
	data->assets.collectible = mlx_xpm_file_to_image(data->mlx, COLLECTIBLE,
			&data->assets.width, &data->assets.height);
	if (!data->assets.collectible)
		ft_clear_assets(data, 1);
	data->assets.exit = mlx_xpm_file_to_image(data->mlx, EXIT,
			&data->assets.width, &data->assets.height);
	if (!data->assets.exit)
		ft_clear_assets(data, 2);
	data->assets.player = mlx_xpm_file_to_image(data->mlx, PLAYER,
			&data->assets.width, &data->assets.height);
	if (!data->assets.player)
		ft_clear_assets(data, 3);
	data->assets.wall = mlx_xpm_file_to_image(data->mlx, WALL,
			&data->assets.width, &data->assets.height);
	if (!data->assets.wall)
		ft_clear_assets(data, 4);
}

void	ft_fill_window(t_data *data)
{
	int		x;
	int		y;
	char	*move;
	char	*tmp;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			put_image(data, y, x);
			x++;
		}
		y++;
	}
	tmp = ft_itoa(data->move);
	move = ft_strjoin("Moves: ", tmp);
	free(tmp);
	mlx_string_put(data->mlx, data->win, 20, 20, 0x000000, move);
	free(move);
}

void	put_image(t_data *data, int y, int x)
{
	if (data->map[y][x] == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->assets.wall,
			x * ASSET_SIZE, y * ASSET_SIZE);
	if (data->map[y][x] == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->assets.floor,
			x * ASSET_SIZE, y * ASSET_SIZE);
	if (data->map[y][x] == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->assets.collectible,
			x * ASSET_SIZE, y * ASSET_SIZE);
	if (data->map[y][x] == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->assets.exit,
			x * ASSET_SIZE, y * ASSET_SIZE);
	if (data->map[y][x] == 'P')
		mlx_put_image_to_window(data->mlx, data->win, data->assets.player,
			x * ASSET_SIZE, y * ASSET_SIZE);
}
