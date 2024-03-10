/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kane <kane@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:06:11 by mkane             #+#    #+#             */
/*   Updated: 2024/03/10 20:24:29 by kane             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	ft_open(char *file, int flag)
{
	int	fd;

	fd = open(file, flag);
	if (fd == -1)
		ft_error("Error opening file");
	return (fd);
}

