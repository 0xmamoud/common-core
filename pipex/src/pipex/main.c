/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kane <kane@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 06:50:51 by mkane             #+#    #+#             */
/*   Updated: 2024/03/10 22:03:58 by kane             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/pipex.h"

int	main(int ac, char **av, char **env)
{
	t_pipex	pipex;
	int		i;

	if (ac == 5)
	{
		pipex.infile = ft_open(av[1], O_RDONLY);
		pipex.outfile = ft_open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC);
		dup2(pipex.infile, STDIN_FILENO);
		dup2(pipex.outfile, STDOUT_FILENO);
		i = 2;
		while (i < ac - 2)
			ft_pipex(&pipex, av[i++], env);
		ft_execve(&pipex, av[ac - 2], env);
		free(pipex.env);
		close(pipex.infile);
		close(pipex.outfile);
	}
	return (0);
}
