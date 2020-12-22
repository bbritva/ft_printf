/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grvelva <grvelva@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 09:43:52 by grvelva           #+#    #+#             */
/*   Updated: 2020/12/18 14:41:38 by grvelva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_none(t_frmt *frmt)
{
	int		len;
	char	empty;

	if (frmt->precision > -1 && frmt->precision < 1)
		len = frmt->precision;
	else
		len = 1;
	if (frmt->wide > -1)
		len = (frmt->wide > len) ? frmt->wide : len;
	empty = (frmt->flag & ZERO) ? '0' : ' ';
	len = put_none(len, empty);
	return (len);
}

int		put_none(int len, char empty)
{
	int i;

	i = 0;
	while (i < len - 1)
		i += write(1, &empty, 1);
	return (i);
}
