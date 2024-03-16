/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkane <mkane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 07:25:17 by mkane             #+#    #+#             */
/*   Updated: 2024/03/16 13:10:24 by mkane            ###   ########.fr       */
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
		if (!pipex->cmd[i])
		{
			while (j <= i)
				free(pipex->cmd[j++]);
			free(pipex->cmd);
			return (0);
		}
		i++;
	}
	return (1);
}
