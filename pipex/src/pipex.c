/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kane <kane@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 15:24:05 by mkane             #+#    #+#             */
/*   Updated: 2024/03/10 22:02:13 by kane             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_pipex(t_pipex *pipex, char *av, char **env)
{
	pid_t	pid;
	int		fd[2];

	pipex->env = ft_get_path(env);
	if (pipe(fd) == -1)
		ft_error("Error creating pipe");
	pid = fork();
	if (pid == -1)
		ft_error("Error creating child process");
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		ft_execve(pipex, av, env);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

void	ft_execve(t_pipex *pipex, char *av, char **env)
{
	pipex->path = ft_parse_args(*pipex, av);
	pipex->cmd = ft_split(av, ' ');
	if (execve(pipex->path, pipex->cmd, env) == -1)
		ft_error("Error executing command");
}
