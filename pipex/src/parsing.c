/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkane <mkane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 08:53:58 by mkane             #+#    #+#             */
/*   Updated: 2024/03/12 16:32:30 by mkane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_init(t_pipex *pipex, char *infile, char *outfile, char **env)
{
	pipex->infile = open(infile, O_RDONLY);
	pipex->outfile = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	pipex->env = ft_env(env);
}

char	**ft_env(char **env)
{
	int		i;
	int		j;
	char	**path;
	char	*tmp;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			path = ft_split(env[i] + 5, ':');
			j = 0;
			while (path[j])
			{
				tmp = ft_strjoin(path[j], "/");
				free(path[j]);
				path[j] = tmp;
				j++;
			}
		}
		i++;
	}
	return (path);
}

char	*ft_path(t_pipex pipex, char *av)
{
	char	*path;
	char	*tmp;
	char	**args;
	int		i;

	args = ft_split(av, ' ');
	i = 0;
	path = NULL;
	while (pipex.env[i])
	{
		tmp = ft_strjoin(pipex.env[i], args[0]);
		if (access(tmp, F_OK | R_OK) == 0)
		{
			path = ft_strjoin(pipex.env[i], args[0]);
			if (!path)
				ft_error("");
			free(tmp);
			break ;
		}
		free(tmp);
		i++;
	}
	ft_free_split(args);
	return (path);
}

