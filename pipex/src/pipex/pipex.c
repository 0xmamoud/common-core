/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkane <mkane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 06:50:51 by mkane             #+#    #+#             */
/*   Updated: 2024/03/12 17:06:59 by mkane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/pipex.h"

static void	ft_child(t_pipex *pipex, char *av, char **env)
{
	if (pipex->infile < 0)
	{
		ft_free_split(pipex->env);
		ft_error("");
	}
	close(pipex->fd[0]);
	dup2(pipex->fd[1], STDOUT_FILENO);
	dup2(pipex->infile, STDIN_FILENO);
	ft_execve(pipex, av, env);
}

static void	ft_parent(t_pipex *pipex, char *av, char **env)
{
	if (pipex->outfile < 0)
	{
		ft_free_split(pipex->env);
		ft_error("");
	}
	close(pipex->fd[1]);
	dup2(pipex->fd[0], STDIN_FILENO);
	dup2(pipex->outfile, STDOUT_FILENO);
	ft_execve(pipex, av, env);
}

int	main(int ac, char **av, char **env)
{
	t_pipex	pipex;
	pid_t	pid;

	if (ac == 5)
	{
		ft_init(&pipex, av[1], av[ac - 1], env);
		if (pipe(pipex.fd) == -1)
			ft_error("");
		pid = fork();
		if (pid == -1)
			ft_error("");
		if (pid == 0)
			ft_child(&pipex, av[2], env);
		ft_parent(&pipex, av[3], env);
	}
	return (0);
}
