/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grvelva <grvelva@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 09:43:52 by grvelva           #+#    #+#             */
/*   Updated: 2020/12/18 12:27:21 by grvelva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_char(char c, t_frmt *frmt)
{
	int		len;
	char	empty;
	int		i;

	len = putchar_len(frmt);
	empty = (frmt->flag & ZERO) ? '0' : ' ';
	if (frmt->flag & MINUS)
		i = putchar_left(len, c, ' ');
	else
		i = putchar_right(len, c, empty);
	return (i);
}

int		putchar_left(int len, char c, char empty)
{
	int i;

	i = 0;
	i += write(1, &c, 1);
	while (i < len)
		i += write(1, &empty, 1);
	return (i);
}

int		putchar_right(int len, char c, char empty)
{
	int i;

	i = 0;
	while (i < (len - 1))
		i += write(1, &empty, 1);
	i += write(1, &c, 1);
	return (i);
}

int		putchar_len(t_frmt *frmt)
{
	int	len;

	if (frmt->precision > -1 && frmt->precision < 1)
		len = frmt->precision;
	else
		len = 1;
	if (frmt->wide > -1)
		len = (frmt->wide > len) ? frmt->wide : len;
	return (len);
}
