/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grvelva <grvelva@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 09:43:52 by grvelva           #+#    #+#             */
/*   Updated: 2020/12/16 19:03:48 by grvelva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_char(char c, t_frmt *frmt)
{
	size_t	len;
	char	empty;

	len = putchar_len(frmt);
	empty = (frmt->flag & ZERO) ? '0' : ' ';
	if (frmt->flag & MINUS)
		putchar_left(len, c, ' ');
	else
		putchar_right(len, c, empty);
	return (len);
}

void	putchar_left(size_t len, char c, char empty)
{
	size_t i;

	i = 1;
	ft_putchar_fd(c, 1);
	while (i++ < len)
		ft_putchar_fd(empty, 1);
}

void	putchar_right(size_t len, char c, char empty)
{
	size_t i;

	i = 0;
	while ((int)i++ < ((int)len - 1))
		ft_putchar_fd(empty, 1);
	ft_putchar_fd(c, 1);
}

size_t	putchar_len(t_frmt *frmt)
{
	size_t	len;

	if (frmt->precision > -1 && frmt->precision < 1)
		len = frmt->precision;
	else
		len = 1;
	if (frmt->wide > -1)
		len = ((size_t)frmt->wide > len) ? frmt->wide : len;
	return (len);
}
