/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkane <mkane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 01:20:00 by mkane             #+#    #+#             */
/*   Updated: 2024/02/27 08:31:24 by mkane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <string.h>
#include "../libft/libft.h"

typedef struct s_pipex
{
	char	**cmd;
	char	*path;
	int		fd[2];
	int		infile;
	int		outfile;
}	t_pipex;

// utils
void	ft_error(char *str);

#endif