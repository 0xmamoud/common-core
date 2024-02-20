/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkane <mkane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:40:07 by mkane             #+#    #+#             */
/*   Updated: 2024/02/20 23:01:59 by mkane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	ft_close(t_data *data)
{
	mlx_destroy_image(data->mlx, data->assets.floor);
	mlx_destroy_image(data->mlx, data->assets.collectible);
	mlx_destroy_image(data->mlx, data->assets.exit);
	mlx_destroy_image(data->mlx, data->assets.player);
	mlx_destroy_image(data->mlx, data->assets.wall);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	ft_free_map(data->map);
	free(data->mlx);
	exit(0);
	return (0);
}

void	ft_clear_assets(t_data *data, int nbr)
{
	if (nbr == 1)
		mlx_destroy_image(data->mlx, data->assets.floor);
	if (nbr == 2)
	{
		mlx_destroy_image(data->mlx, data->assets.floor);
		mlx_destroy_image(data->mlx, data->assets.collectible);
	}
	if (nbr == 3)
	{
		mlx_destroy_image(data->mlx, data->assets.floor);
		mlx_destroy_image(data->mlx, data->assets.collectible);
		mlx_destroy_image(data->mlx, data->assets.exit);
	}
	if (nbr == 4)
	{
		mlx_destroy_image(data->mlx, data->assets.floor);
		mlx_destroy_image(data->mlx, data->assets.collectible);
		mlx_destroy_image(data->mlx, data->assets.exit);
		mlx_destroy_image(data->mlx, data->assets.player);
	}
	ft_free_map(data->map);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}
