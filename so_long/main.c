/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kane <kane@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 00:58:56 by kane              #+#    #+#             */
/*   Updated: 2024/02/19 03:21:57 by kane             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

int	main(int ac, char **av)
{
	t_data	data;
	int		fd;
	char	*map;

	if (ac != 2)
		return( ft_printf("Error\n"));
	map = ft_strjoin("./maps/", av[1]);
	fd = open(map, O_RDONLY);
	if (!parsing(fd, &data))
	{
		ft_free_map(data.map);
		return (0);
	}
	init_game(&data);
	mlx_loop(data.mlx);
	ft_free_map(data.map);
	free(map);
}
