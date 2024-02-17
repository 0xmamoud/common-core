/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kane <kane@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 00:58:56 by kane              #+#    #+#             */
/*   Updated: 2024/02/18 00:31:17 by kane             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

int	main(int ac, char **av)
{
	t_data	data;
	int		fd;
	char	*map;

	(void)ac;
	map = ft_strjoin("./maps/", av[1]);
	fd = open(map, O_RDONLY);
	parsing(fd, &data);
	ft_free_map(data.map);
	free(map);
}
