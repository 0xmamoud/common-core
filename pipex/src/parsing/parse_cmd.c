/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kane <kane@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 07:25:17 by mkane             #+#    #+#             */
/*   Updated: 2024/03/15 21:13:27 by kane             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

char	ft_parse_cmd(char **argv, t_pipex *pipex)
{
	int (i) = 0;
	int (j) = 0;
	pipex->cmd = malloc(sizeof(char **) * pipex->len_cmd);
	if (!pipex->cmd)
		return (0);
	while (i < pipex->len_cmd)
	{
		pipex->cmd[i] = ft_split(argv[i + 2], ' ');
		if (!pipex->cmd[i] || !pipex->cmd[i][0])
		{
			while (j <= i)
			{
				free(pipex->cmd[j]);
				j++;
			}
			free(pipex->cmd);
			return (0);
		}
		i++;
	}
	return (1);
}
