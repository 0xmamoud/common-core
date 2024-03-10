/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkane <mkane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 06:50:51 by mkane             #+#    #+#             */
/*   Updated: 2024/03/10 17:15:14 by mkane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/pipex.h"

int	main(int ac, char **av, char **env)
{
	t_pipex	pipex;
	int		i;

	if (ac == 6)
	{
		pipex.infile = ft_open(av[1], O_RDONLY);
		pipex.outfile = ft_open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC);
		dup2(pipex.infile, STDIN_FILENO);
		i = 2;
		while (i < ac - 2)
		{
			ft_pipex(&pipex, av[i], env);
			i++;
		}
		dup2(pipex.outfile, STDOUT_FILENO);
		ft_pipex(&pipex, av[ac - 2], env);
		free(pipex.env);
		close(pipex.infile);
		close(pipex.outfile);
	}
	return (0);
}
