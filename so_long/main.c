/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkane <mkane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 00:58:56 by kane              #+#    #+#             */
/*   Updated: 2024/02/20 23:09:40 by mkane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

int	main(int ac, char **av)
{
	t_data	data;
	int		fd;
	char	*map;

	if (ac != 2)
		return (ft_printf("Error\n"));
	if (!ft_check_extension(av[1]))
		return (ft_printf("Error extension\n"));
	map = ft_strjoin("", av[1]);
	fd = open(map, O_RDONLY);
	if (!parsing(fd, &data, map))
	{
		free(map);
		ft_free_map(data.map);
		return (0);
	}
	free(map);
	data.move = 0;
	init_game(&data);
	mlx_key_hook(data.win, ft_movement, &data);
	mlx_hook(data.win, DestroyNotify, StructureNotifyMask, ft_close, &data);
	mlx_loop(data.mlx);
}
