/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkane <mkane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 18:43:26 by mkane             #+#    #+#             */
/*   Updated: 2023/12/15 02:10:33 by mkane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_putchar(char c);
int	ft_putstr(char *str);
size_t	ft_strlen(const char *s);
int	ft_parser(va_list arg, const char c);
int	ft_putnbr_base(int nbr, char *base);
int	ft_putptr(void *ptr);
int	ft_ptr_hex(unsigned long long nbr, char *base);
int	ft_put_uint(unsigned int nbr, char *base);
#endif