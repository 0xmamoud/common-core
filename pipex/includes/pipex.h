/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkane <mkane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 01:20:00 by mkane             #+#    #+#             */
/*   Updated: 2024/03/12 17:06:47 by mkane            ###   ########.fr       */
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
# include "../libft/libft.h"

typedef struct s_pipex
{
	char	*path;
	char	**cmd;
	char	**env;
	int		infile;
	int		outfile;
	int		fd[2];
}	t_pipex;

// utils
void	ft_error(char *str);
char	*ft_path(t_pipex pipex, char *av);
char	**ft_env(char **env);
void	ft_free_split(char **str);
// src
void	ft_pipe(t_pipex *pipex, char *av, char **env);
void	ft_execve(t_pipex *pipex, char *av, char **env);
void	ft_init(t_pipex *pipex, char *infile, char *outfile, char **env);

#endif