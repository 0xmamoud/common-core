/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kane <kane@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 21:52:10 by kane              #+#    #+#             */
/*   Updated: 2024/03/09 22:50:54 by kane             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	**ft_get_path(char **env)
{
	int		i;
	int		j;
	char	**path;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			path = ft_split(ft_strdup(env[i] + 5), ':');
			j = 0;
			while (path[j])
			{
				path[j] = ft_strjoin(path[j], "/");
				if (!path[j])
					ft_error("Error: malloc failed");
				j++;
			}
			return (path);
		}
		i++;
	}
	return (NULL);
}
