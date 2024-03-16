/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkane <mkane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:41:22 by kane              #+#    #+#             */
/*   Updated: 2024/03/16 11:48:05 by mkane            ###   ########.fr       */
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
	pid_t	pid;
	int		fd[2];
	int		fd_in;
	int		fd_out;
	int		len_cmd;
	int		loop_index;
	char	**path;
	char	***cmd;
}	t_pipex;

// parsing
char	ft_parse_cmd(char **argv, t_pipex *pipex);
void	ft_parse_path(char **envp, t_pipex *pipex);

// execution
void	ft_pipex(t_pipex *pipex);

// utils
void	ft_error(char *str);
void	ft_clean_cmds(t_pipex *pipex);
void	ft_clean_path(t_pipex *pipex);

#endif