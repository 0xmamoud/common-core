/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkane <mkane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 00:58:56 by kane              #+#    #+#             */
/*   Updated: 2024/02/13 07:51:10 by mkane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

int	main(void)
{
	t_data	data;
	int		fd;

	fd = open("./maps/map.ber", O_RDONLY);
	parsing(fd, &data);
	close(fd);
	free(data.map);
}
