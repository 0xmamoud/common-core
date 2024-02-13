/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkane <mkane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 00:57:00 by kane              #+#    #+#             */
/*   Updated: 2024/02/13 12:27:38 by mkane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define RECTANGLE_ERROR "your map is not a rectancle"
# define CLOSED_ERROR "your map is not a rectangle"


typedef struct s_data
{
	char	**map;
	t_count	count;
	t_pos	player_pos;
}	t_data;

typedef struct s_count
{
	int	collectible;
	int	exit;
	int	player;
}	t_count;

typedef struct s_pos
{
	int	pos_x;
	int	pos_y;
}	t_pos;


// utils

// parsing
char	**ft_create_map(int fd);
int		ft_check_map(t_data *data);
int		parsing(int fd, t_data *data);
int		ft_check_rectangle(char **str);
#endif