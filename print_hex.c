/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grvelva <grvelva@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 09:43:52 by grvelva           #+#    #+#             */
/*   Updated: 2020/12/16 20:04:34 by grvelva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_hex(va_list args, t_frmt *frmt)
{
	long long		nbr;
	char			empty;
	int				len;
	char			*base;

	base = (frmt->type == 'x') ? "0123456789abcdef" : "0123456789ABCDEF";
	nbr = va_arg(args, unsigned int);
	(frmt->precision > -1) ? frmt->flag = frmt->flag & 15 : frmt->flag;
	empty = ((frmt->flag & ZERO) && frmt->precision == -1) ? '0' : ' ';
	if (frmt->precision == 0 && nbr == 0)
		len = put_zero(frmt->wide);
	else
	{
		if (frmt->flag & MINUS)
			len = puthex_left(frmt, nbr, ' ', base);
		else
			len = puthex_right(frmt, nbr, empty, base);
	}
	return (len);
}

int		puthex_left(t_frmt *frmt, long long nbr, char empty, char *base)
{
	int	wide;
	int	i;
	int num_len;
	int	prec;

	wide = output_hlen(frmt, nbr);
	num_len = hex_len(nbr);
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
	i += (nbr < 0) ? ft_puthex(-nbr, base) : ft_puthex(nbr, base);
	while (i < wide)
		i += write(1, &empty, 1);
	return (wide);
}

int		puthex_right(t_frmt *frmt, long long nbr, char empty, char *base)
{
	int	wide;
	int	i;
	int num_len;
	int	prec;

	wide = output_hlen(frmt, nbr);
	num_len = hex_len(nbr);
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
	(nbr < 0) ? ft_puthex(-nbr, base) : ft_puthex(nbr, base);
	return (wide);
}
