/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grvelva <grvelva@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 09:43:52 by grvelva           #+#    #+#             */
/*   Updated: 2020/12/16 20:20:37 by grvelva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_nbr(va_list args, t_frmt *frmt)
{
	int		nbr;
	char	empty;
	int		len;

	nbr = va_arg(args, int);
	(frmt->precision > -1) ? frmt->flag = frmt->flag & 15 : frmt->flag;
	empty = ((frmt->flag & ZERO) && frmt->precision < 0) ? '0' : ' ';
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

int		putnbr_left(t_frmt *frmt, long long nbr, char empty)
{
	int	wide;
	int	i;
	int num_len;
	int	prec;

	wide = output_nlen(frmt, nbr);
	num_len = n_len(nbr);
	prec = ((frmt->precision > 0) && (frmt->precision > num_len)) ?
		frmt->precision : num_len;
	i = 0;
	if (nbr < 0)
	{
		i += write(1, "-", 1);
		prec++;
	}
	while (i < (prec - num_len))
		i += write(1, "0", 1);
	i += (nbr < 0) ? ft_putnbr(-nbr) : ft_putnbr(nbr);
	while (i < wide)
		i += write(1, &empty, 1);
	return (i);
}

int		putnbr_right(t_frmt *frmt, long long nbr, char empty)
{
	int	wide;
	int	i;
	int num_len;
	int	prec;

	wide = output_nlen(frmt, nbr);
	num_len = n_len(nbr);
	prec = ((frmt->precision > 0) && (frmt->precision > num_len)) ?
		frmt->precision : num_len;
	(nbr < 0) ? prec++ : prec;
	i = 0;
	while ((i < (wide - prec)) && empty == ' ')
		i += write(1, &empty, 1);
	if (nbr < 0)
		i += write(1, "-", 1);
	while ((i < (wide - prec)) && empty == '0')
		i += write(1, &empty, 1);
	while (i < (wide - num_len))
		i += write(1, "0", 1);
	i += (nbr < 0) ? ft_putnbr(-nbr) : ft_putnbr(nbr);
	return (i);
}
