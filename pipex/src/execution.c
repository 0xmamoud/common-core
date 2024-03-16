/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkane <mkane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 12:43:43 by mkane             #+#    #+#             */
/*   Updated: 2024/03/16 16:04:41 by mkane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static	void	ft_revert(t_pipex *pipex, int i, char *str);
static	void	ft_execve(t_pipex *pipex);
static	void	child_process(t_pipex *pipex);

static	void	ft_revert(t_pipex *pipex, int i, char *str)
{
	if (i == 0)
		ft_error(str);
	if (i == 1)
		ft_putstr_fd("Command not found\n", 2);
	if (i == 2)
		ft_putstr_fd("No such file or directory\n", 2);
	ft_clean_cmds(pipex);
	ft_clean_path(pipex);
	exit(0);
}

void	ft_pipex(t_pipex *pipex)
{
	if (pipe(pipex->fd) == -1)
		ft_revert(pipex, 0, "");
	pipex->pid = fork();
	if (pipex->pid == -1)
		ft_revert(pipex, 0, "");
	if (pipex->pid == 0)
		child_process(pipex);
	else
	{
		close(pipex->fd[1]);
		dup2(pipex->fd[0], STDIN_FILENO);
		close(pipex->fd[0]);
	}
}

static	void	child_process(t_pipex *pipex)
{
	close(pipex->fd[0]);
	if (pipex->loop_index == 0)
	{
		dup2(pipex->fd_in, STDIN_FILENO);
		if (pipex->fd_in < 0)
			ft_revert(pipex, 2, "");
	}
	if (pipex->loop_index == pipex->len_cmd - 1)
	{
		dup2(pipex->fd_out, STDOUT_FILENO);
		if (pipex->fd_out < 0)
			ft_revert(pipex, 0, "Permission denied");
	}
	else
	{
		dup2(pipex->fd[1], STDOUT_FILENO);
	}
	ft_execve(pipex);
}

static	void	ft_execve(t_pipex *pipex)
{
	if (access(pipex->path[pipex->loop_index], F_OK) == -1)
		ft_revert(pipex, 2, "");
	if (execve(pipex->path[pipex->loop_index], \
	pipex->cmd[pipex->loop_index], NULL) == -1)
		ft_revert(pipex, 1, "");
}
