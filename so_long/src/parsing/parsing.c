/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kane <kane@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 07:38:36 by mkane             #+#    #+#             */
/*   Updated: 2024/02/17 23:13:14 by kane             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	parsing(int fd, t_data *data)
{
	data->count.player = 0;
	data->count.exit = 0;
	data->count.collectible = 0;
	data->map = ft_create_map(fd);
	if (!ft_check_map(data))
		return (0);
	return (1);
}
