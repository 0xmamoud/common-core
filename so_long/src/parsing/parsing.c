/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkane <mkane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 07:38:36 by mkane             #+#    #+#             */
/*   Updated: 2024/02/19 18:38:35 by mkane            ###   ########.fr       */
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
	if (!path_finding(data->map))
		return (0);
	return (1);
}
