/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kane <kane@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 19:38:00 by mkane             #+#    #+#             */
/*   Updated: 2024/02/03 23:35:15 by kane             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long long	ft_long_atoi(const char *nptr)
{
	long long	char_to_int;
	int			sign;

	sign = 1;
	char_to_int = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		if (*(nptr + 1) == '+' || *(nptr + 1) == '-')
			return (-2147483650);
		nptr++;
	}
	while ((*nptr >= '0' && *nptr <= '9'))
	{
		char_to_int = (char_to_int * 10) + (*nptr - '0');
		nptr++;
	}
	if (char_to_int > 2147483647 || char_to_int < -2147483648)
		return (-2147483650);
	return (sign * char_to_int);
}
