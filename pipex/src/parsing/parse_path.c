/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkane <mkane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 07:23:12 by mkane             #+#    #+#             */
/*   Updated: 2024/03/15 12:43:39 by mkane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

static	int	ft_access(char *cmd, t_pipex *pipex, char **envp, int index);
static	char	**ft_get_path(char **envp);
static	void	ft_free(char **path);
static void	exit_malloc(t_pipex *pipex);

void	ft_parse_path(char **envp, t_pipex *pipex)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	pipex->path = malloc(sizeof(char *) * pipex->len_cmd + 1);
	if (!pipex->path)
		exit_malloc(pipex);
	while (i < pipex->len_cmd)
	{
		if (!ft_access(pipex->cmd[i][0], pipex, envp, i))
		{
			ft_free(pipex->path);
			exit_malloc(pipex);
		}
		i++;
	}
}

static	int	ft_access(char *cmd, t_pipex *pipex, char **envp, int index)
{
	char	**env_path;
	char	*tmp;

	env_path = ft_get_path(envp);
	if (!env_path)
		return (0);
	int (i) = -1;
	while (env_path[++i])
	{
		tmp = ft_strjoin(env_path[i], cmd);
		if (!tmp)
			return (ft_free(env_path), 0);
		if (!access(tmp, F_OK | R_OK))
		{
			pipex->path[index] = tmp;
			return (ft_free(env_path), 1);
		}
		free(tmp);
	}
	pipex->path[index] = ft_strdup("avec/un/chien/la");
	if (!pipex->path)
		return (ft_free(env_path), 0);
	ft_free(env_path);
	return (1);
}

static	char	**ft_get_path(char **envp)
{
	char	**path;
	char	*tmp;

	int (i) = -1;
	int (j) = -1;
	path = NULL;
	while (envp[++i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path = ft_split(envp[i] + 5, ':');
			path = 0;
			if (!path)
				return (NULL);
			while (path[++j])
			{
				tmp = ft_strdup(path[j]);
				free(path[ j]);
				path[j] = ft_strjoin(tmp, "/");
				free(tmp);
				if (!path[j])
					return (ft_free(path), NULL);
			}
		}
	}
	return (path);
}

static	void	ft_free(char **path)
{
	int	i;

	i = 0;
	while (path && path[i])
	{
		free(path[i]);
		i++;
	}
	if (path)
		free(path);
}

static void	exit_malloc(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->cmd[i])
		ft_free(pipex->cmd[i++]);
	free(pipex->cmd);
	exit(1);
}
