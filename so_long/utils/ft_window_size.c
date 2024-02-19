/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkane <mkane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:13:24 by mkane             #+#    #+#             */
/*   Updated: 2024/02/19 16:25:50 by mkane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_window_size(t_data *data)
{
	int	width;
	int	height;

	width = 0;
	height = 0;
	while (data->map[height][width])
		width++;
	data->win_width = width * ASSET_SIZE + 1;
	while (data->map[height])
		height++;
	data->win_height = height * ASSET_SIZE + 1;
}
