/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkane <mkane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 04:02:26 by mkane             #+#    #+#             */
/*   Updated: 2024/02/19 22:02:29 by mkane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	ft_check_map(t_data *data)
{
	if (!ft_check_rectangle(data->map))
	{
		ft_printf("%s\n", RECTANGLE_ERROR);
		return (0);
	}
	if (!ft_check_closed(data->map))
	{
		ft_printf("%s\n", CLOSED_ERROR);
		return (0);
	}
	if (!ft_check_characters(data))
	{
		ft_printf("%s\n", CHARACTERS_ERROR);
		return (0);
	}
	return (1);
}

int	ft_check_rectangle(char **str)
{
	size_t	line_size;
	size_t	i;

	i = 0;
	line_size = ft_strlen(str[i]);
	while (str[i])
	{
		if (ft_strlen(str[i]) != line_size)
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_closed(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i][j])
	{
		if (str[i][j] != '1')
			return (0);
		j++;
	}
	j--;
	while (str[i])
	{
		if (str[i][j] != '1')
			return (0);
		i++;
	}
	if (!ft_check_closed2(str))
		return (0);
	return (1);
}

int	ft_check_closed2(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i][j] != '1')
			return (0);
		i++;
	}
	i--;
	while (str[i][j])
	{
		if (str[i][j] != '1')
			return (0);
		j++;
	}
	return (1);
}
