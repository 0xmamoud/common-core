/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kane <kane@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 01:20:00 by mkane             #+#    #+#             */
/*   Updated: 2024/03/10 19:53:14 by kane             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <string.h>

#include "../libft/libft.h"

typedef struct s_pipex
{
	char	*path;
	char	**env;
	char	**cmd;
	int		infile;
	int		outfile;
}	t_pipex;

// utils
void	ft_error(char *str);
char	*ft_parse_args(t_pipex pipex, char *av);
char	**ft_get_path(char **env);
void	ft_free_split(char **str);
int		ft_open(char *file, int flag);

// src
void	ft_pipex(t_pipex *pipex, char *av, char **env);
void	ft_execve(t_pipex *pipex, char *av, char **env);

#endif