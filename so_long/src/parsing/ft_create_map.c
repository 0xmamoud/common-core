/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkane <mkane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 04:08:08 by mkane             #+#    #+#             */
/*   Updated: 2024/02/19 23:27:03 by mkane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

char	**ft_create_map(int fd)
{
	char	*tab;
	char	*tmp;
	char	*line;
	char	**map;

	tab = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		tmp = ft_strjoin(tab, line);
		free(tab);
		free(line);
		tab = tmp;
	}
	if (ft_strlen(tab) <= 1 || tab[0] == '\n')
	{
		free(tab);
		free(line);
		return (NULL);
	}
	map = ft_split(tab, '\n');
	free(tab);
	return (map);
}
