/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkane <mkane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:06:15 by mkane             #+#    #+#             */
/*   Updated: 2024/03/16 12:38:48 by mkane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_error(char *str)
{
	perror(str);
	exit(0);
}

void	ft_clean_cmds(t_pipex *pipex)
{
	int	i;
	int	j;

	i = 0;
	while (i < pipex->len_cmd)
	{
		j = 0;
		while (pipex->cmd[i][j])
		{
			free(pipex->cmd[i][j]);
			j++;
		}
		free(pipex->cmd[i]);
		i++;
	}
	free(pipex->cmd);
}

void	ft_clean_path(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->len_cmd)
	{
		free(pipex->path[i]);
		i++;
	}
	free(pipex->path);
}
