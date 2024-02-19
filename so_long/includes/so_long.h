/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kane <kane@student.42.fr>                  +#+  +:+       +#+        */
/*                                               +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 00:57:00 by kane              #+#    #+#             */
/*   Updated: 2024/02/19 02:04:37 by kane             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/libft/libft.h"
# include "../lib/minilibx-linux/mlx.h"
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

// parsing defines
# define RECTANGLE_ERROR "your map is not a rectancle"
# define CLOSED_ERROR "your map is not a closed map"
# define CHARACTERS_ERROR "your map characters are not valid"
# define PATH_ERROR "your map is not valid"

// assets defines
# define WALL "assets/wall.xpm"
# define FLOOR "assets/floor.xpm"
# define COLLECTIBLE "assets/collectible.xpm"
# define EXIT "assets/exit.xpm"
# define PLAYER "assets/player.xpm"

// game defines
# define WIN_WIDTH 1024
# define WIN_HEIGHT 768
# define ASSET_SIZE 64

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

typedef struct s_assets
{
	void	*wall;
	void	*floor;
	void	*collectible;
	void	*exit;
	void	*player;
	int		width;
	int		height;
}	t_assets;
typedef struct s_data
{
	void		*mlx;
	void		*win;
	char		**map;
	t_count		count;
	t_pos		player_pos;
	t_assets	assets;
}	t_data;


// utils
void	ft_free_map(char **map);

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
char	**copy_map(char **map);
void	flood_fill(char **map, int x, int y);
int		path_finding(char **map);

// game
void	init_game(t_data *data);
void	ft_get_assets(t_data *data);
void	ft_fill_window(t_data *data);
void	put_image(t_data *data, int y, int x);
#endif