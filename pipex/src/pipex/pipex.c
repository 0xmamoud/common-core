/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkane <mkane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 06:50:51 by mkane             #+#    #+#             */
/*   Updated: 2024/02/27 08:53:43 by mkane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	exec_cmd(t_pipex *pipex, char **ev, char *path, char **cmd)
{
	
}

void	exec_parent(t_pipex *pipex)
{
	ft_printf("parent\n");
}

#include "./includes/pipex.h"

int	main(int ac, char **av, char **ev)
{
	t_pipex	pipex;
	int	child1;
	int	child2;
	int	status;

	if (ac == 5)
	{
		
	}
	return (0);
}
