/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kane <kane@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:06:15 by mkane             #+#    #+#             */
/*   Updated: 2024/03/20 22:02:43 by kane             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_error(t_pipex *pipex, int error)
{
	if (pipex->here_doc)
		unlink("here_doc");
	if (pipex->fd_in != -1)
		close(pipex->fd_in);
	if (pipex->fd_out != -1)
		close(pipex->fd_out);
	if (pipex->fd[0] != -1)
		close(pipex->fd[0]);
	if (pipex->fd[1] != -1)
		close(pipex->fd[1]);
	if (error == 1)
		perror("pipex");
	if (error == 127)
		ft_putstr_fd("pipex: command not found\n", 2);
	exit(error);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
