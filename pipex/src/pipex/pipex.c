/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kane <kane@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 07:00:03 by mkane             #+#    #+#             */
/*   Updated: 2024/03/15 20:03:38 by kane             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

static	void	ft_init(t_pipex *pipex, char **argv, char **envp, int argc)
{
	if (!envp)
	{
		write(2, "Error: no environment\n", 22);
		exit(0);
	}
	pipex->len_cmd = argc - 3;
	pipex->loop_index = 0;
	pipex->fd_in = open(argv[1], O_RDONLY);
	pipex->fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	pipex->path = NULL;
	pipex->cmd = NULL;
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc == 5)
	{
		ft_init(&pipex, argv, envp, argc);
		if (!ft_parse_cmd(argv, &pipex))
		{
			write(2, "Error: malloc failed\n", 21);
			close(pipex.fd_in);
			close(pipex.fd_out);
			exit(1);
		}
		ft_parse_path(envp, &pipex);
		while (pipex.loop_index < pipex.len_cmd)
		{
			ft_pipex(&pipex);
			pipex.loop_index++;
		}
		ft_clean_cmds(&pipex);
		ft_clean_path(&pipex);
	}
	return (0);
}
