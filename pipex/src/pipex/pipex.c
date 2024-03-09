/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kane <kane@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 06:50:51 by mkane             #+#    #+#             */
/*   Updated: 2024/03/09 23:05:16 by kane             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/pipex.h"

int	main(int ac, char **av, char **ev)
{
	t_pipex	pipex;

	if (ac == 2)
	{
		pipex.env = ft_get_path(ev);
		if (!pipex.env)
			ft_error("PATH not found");
		pipex.path = ft_parse_args(pipex, av[1]);
		ft_printf("%s\n", pipex.path);
	}
	return (0);
}
