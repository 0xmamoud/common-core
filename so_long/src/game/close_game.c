/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkane <mkane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:40:07 by mkane             #+#    #+#             */
/*   Updated: 2024/02/19 19:36:03 by mkane            ###   ########.fr       */
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
