/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkane <mkane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:41:22 by kane              #+#    #+#             */
/*   Updated: 2024/03/18 16:26:48 by mkane            ###   ########.fr       */
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
}	t_pipex;

void	ft_pipex(t_pipex *pipex, char *argv, char **envp);
char	*ft_path(char *cmd, char **envp);
void	ft_error(t_pipex *pipex, int error);
void	ft_free(char **str);

#endif