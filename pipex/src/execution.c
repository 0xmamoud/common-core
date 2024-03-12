/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkane <mkane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 15:24:05 by mkane             #+#    #+#             */
/*   Updated: 2024/03/12 17:04:46 by mkane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_pipe(t_pipex *pipex, char *av, char **env)
{
	pid_t	pid;

	if (pipe(pipex->fd) == -1)
		ft_error("Error creating pipe");
	pid = fork();
	if (pid == -1)
		ft_error("Error creating child process");
	if (pid == 0)
	{
		close(pipex->fd[0]);
		dup2(pipex->fd[1], STDOUT_FILENO);
		ft_execve(pipex, av, env);
	}
	else
	{
		close(pipex->fd[1]);
		dup2(pipex->fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

void	ft_execve(t_pipex *pipex, char *av, char **env)
{
	pipex->path = ft_path(*pipex, av);
	if (!pipex->path)
	{
		ft_free_split(pipex->env);
		ft_putstr_fd("command not found\n", 2);
		exit(127);
	}
	pipex->cmd = ft_split(av, ' ');
	if (execve(pipex->path, pipex->cmd, env) == -1)
	{
		ft_free_split(pipex->cmd);
		ft_free_split(pipex->env);
		if (pipex->path)
			free(pipex->path);
		ft_error("");
	}
}
