/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grvelva <grvelva@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 09:43:52 by grvelva           #+#    #+#             */
/*   Updated: 2020/12/13 20:08:47 by grvelva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_unbr(va_list args, s_output *frmt)
{
	long long		nbr;
	char			empty;
	int 			len;

	nbr = va_arg(args, unsigned int);
	(frmt->precision > -1) ? frmt->flag = frmt->flag & 15 : frmt->flag;
	empty = ((frmt->flag & ZERO) && frmt->precision == -1) ? '0' : ' ';
	if (frmt->precision == 0 && nbr == 0)
		len = put_zero(frmt->wide);
	else
	{
		if (frmt->flag & MINUS)
			len = putnbr_left(frmt, nbr, ' ');
		else
			len = putnbr_right(frmt, nbr, empty);
	}
	return (len);
}
