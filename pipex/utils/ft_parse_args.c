/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kane <kane@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 08:55:35 by mkane             #+#    #+#             */
/*   Updated: 2024/03/10 20:36:56 by kane             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*ft_parse_args(t_pipex pipex, char *av)
{
	char	*path;
	char	**args;
	int		i;

	args = ft_split(av, ' ');
	if (!args)
		ft_error("Error: command not found");
	path = NULL;
	i = 0;
	while (pipex.env[i])
	{
		if (access(ft_strjoin(pipex.env[i], args[0]), F_OK | R_OK) == 0)
		{
			path = ft_strjoin(pipex.env[i], args[0]);
			if (!path)
				ft_error("Error: malloc failed");
			break ;
		}
		i++;
	}
	ft_free_split(args);
	return (path);
}
