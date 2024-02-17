/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kane <kane@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 00:57:00 by kane              #+#    #+#             */
/*   Updated: 2024/02/17 22:45:46 by kane             ###   ########.fr       */
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
# define CLOSED_ERROR "your map is not a closed map"
# define CHARACTERS_ERROR "your map characters are not valid"

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
typedef struct s_data
{
	char	**map;
	t_count	count;
	t_pos	player_pos;
}	t_data;


// utils

// parsing
char	**ft_create_map(int fd);
int		ft_check_map(t_data *data);
int		parsing(int fd, t_data *data);
int		ft_check_rectangle(char **str);
int		ft_check_map(t_data *data);
int		ft_check_rectangle(char **str);
int		ft_check_closed(char **str);
int		ft_check_closed2(char **str);
int		ft_check_characters(t_data *data);
void	ft_count_characters(t_data *data);
#endif