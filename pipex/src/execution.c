/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kane <kane@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 12:43:43 by mkane             #+#    #+#             */
/*   Updated: 2024/03/16 23:00:02 by kane             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static	void	ft_execve(char *argv, char **envp);
static	void	child_process(t_pipex *pipex, char *argv, char **envp);

void	ft_pipex(t_pipex *pipex, char *argv, char **envp)
{
	if (pipe(pipex->fd) == -1)
		ft_error();
	pipex->pid = fork();
	if (pipex->pid == -1)
		ft_error();
	if (pipex->pid == 0)
		child_process(pipex, argv, envp);
	else
	{
		close(pipex->fd[1]);
		dup2(pipex->fd[0], STDIN_FILENO);
		close(pipex->fd[0]);
	}
}

static	void	child_process(t_pipex *pipex, char *argv, char **envp)
{
	close(pipex->fd[0]);
	if (pipex->loop_index == 0)
	{
		dup2(pipex->fd_in, STDIN_FILENO);
		if (pipex->fd_in < 0)
			ft_error();
	}
	if (pipex->loop_index == pipex->len_cmd - 1)
	{
		dup2(pipex->fd_out, STDOUT_FILENO);
		if (pipex->fd_out < 0)
			ft_error();
	}
	else
	{
		dup2(pipex->fd[1], STDOUT_FILENO);
	}
	ft_execve(argv, envp);
}

static	void	ft_execve(char *argv, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(argv, ' ');
	if (!cmd)
		ft_error();
	path = ft_path(cmd[0], envp);
	if (!path)
	{
		ft_free(cmd);
		ft_error();
	}
	if (execve(path, cmd, envp) == -1)
	{
		ft_free(cmd);
		ft_error();
	}
}
