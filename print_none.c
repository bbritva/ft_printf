/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grvelva <grvelva@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 09:43:52 by grvelva           #+#    #+#             */
/*   Updated: 2020/12/16 19:02:02 by grvelva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_none(t_frmt *frmt)
{
	size_t	len;
	char	empty;

	if (frmt->precision > -1 && frmt->precision < 1)
		len = frmt->precision;
	else
		len = 1;
	if (frmt->wide > -1)
		len = ((size_t)frmt->wide > len) ? frmt->wide : len;
	empty = (frmt->flag & ZERO) ? '0' : ' ';
	put_none(len, empty);

	return (len);
}

void	put_none(size_t len, char empty)
{
	size_t i;

	i = 0;
	while (i++ < len)
		ft_putchar_fd(empty, 1);
}
