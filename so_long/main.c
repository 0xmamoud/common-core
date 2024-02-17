/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kane <kane@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 00:58:56 by kane              #+#    #+#             */
/*   Updated: 2024/02/17 22:49:02 by kane             ###   ########.fr       */
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
	free(data.map);
}
