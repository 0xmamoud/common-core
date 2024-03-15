/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kane <kane@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 12:43:43 by mkane             #+#    #+#             */
/*   Updated: 2024/03/15 20:38:51 by kane             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static	void	ft_execve(t_pipex *pipex);
static	void	child_process(t_pipex *pipex);

void	ft_pipex(t_pipex *pipex)
{
	if (pipe(pipex->fd) == -1)
		ft_error("");
	pipex->pid = fork();
	if (pipex->pid == -1)
		ft_error("");
	if (pipex->pid == 0)
		child_process(pipex);
	else
	{
		close(pipex->fd[1]);
		dup2(pipex->fd[0], STDIN_FILENO);
		while (wait(NULL) > 0)
			;
	}
}

static	void	child_process(t_pipex *pipex)
{
	close(pipex->fd[0]);
	if (pipex->loop_index == 0)
	{
		dup2(pipex->fd_in, STDIN_FILENO);
		if (pipex->fd_in < 0)
			ft_error("");
	}
	if (pipex->loop_index == pipex->len_cmd - 1)
	{
		dup2(pipex->fd_out, STDOUT_FILENO);
		if (pipex->fd_out < 0)
			ft_error("");
	}
	else
	{
		dup2(pipex->fd[1], STDOUT_FILENO);
		if (pipex->fd[1] < 0)
			ft_error("");
	}
	ft_execve(pipex);
}

static	void	ft_execve(t_pipex *pipex)
{
	if (access(pipex->path[pipex->loop_index], F_OK | R_OK) == -1)
		ft_error("");
	if (execve(pipex->path[pipex->loop_index], \
	pipex->cmd[pipex->loop_index], NULL) == -1)
		ft_error(pipex->cmd[pipex->loop_index][0]);
}
