/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grvelva <grvelva@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 09:43:52 by grvelva           #+#    #+#             */
/*   Updated: 2020/12/13 17:51:14 by grvelva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_hex(va_list args, s_output *frmt)
{
	long long		nbr;
	char			empty;
	int 			len;

	nbr = va_arg(args, long long);
	(frmt->precision > -1) ? frmt->flag = frmt->flag & 15 : frmt->flag;
	empty = ((frmt->flag & ZERO) && frmt->precision == -1) ? '0' : ' ';
	if (frmt->precision == 0 && nbr == 0)
		len = put_zero(frmt->wide);
	else
	{
		if (frmt->flag & MINUS)
			len = puthex_left(frmt, nbr, ' ');
		else
			len = puthex_right(frmt, nbr, empty);
	}
	return (len);
}

int 	puthex_left(s_output *frmt, long long nbr, char empty)
{
	int	wide;
	int	i;
	int num_len;
	int	prec;

	wide = output_hlen(frmt, nbr);
	num_len = hex_len(nbr);
	prec = ((frmt->precision > 0) && (frmt->precision > num_len)) ?
			frmt->precision : num_len ;
	i = 0;
	if (nbr < 0)
	{
		ft_putchar_fd('-', 1);
		i++;
		prec++;
	}
	while (i < (prec - num_len))
	{
		ft_putchar_fd('0', 1);
		i++;
	}
	i += (nbr < 0) ? ft_puthex(-nbr) : ft_puthex(nbr);
	while (i < wide)
	{
		ft_putchar_fd(empty, 1);
		i++;
	}
	return (wide);
}

int	puthex_right(s_output *frmt, long long nbr, char empty)
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
	{
		ft_putchar_fd(empty, 1);
		i++;
	}
	if (nbr < 0)
	{
		ft_putchar_fd('-', 1);
		i++;
	}
	while ((i < (wide - prec)) && empty == '0')
	{
		ft_putchar_fd(empty, 1);
		i++;
	}
	while (i < (wide - num_len))
	{
		ft_putchar_fd('0', 1);
		i++;
	}
	(nbr < 0) ? ft_puthex(-nbr) : ft_puthex(nbr);
	return (wide);
}

size_t	hex_len(long long nbr)
{
	size_t nbr_len;

	nbr_len = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		nbr = -nbr;
	while (nbr > 0 && ++nbr_len)
		nbr = nbr / 16;
	return (nbr_len);
}

size_t	output_hlen(s_output *frmt, long long nbr)
{
	size_t	len;

	len = hex_len(nbr);
	len = (frmt->wide > (int)len) ? frmt->wide : len;
	if (frmt->precision > (int)len)
	{
		len = frmt->precision;
		(nbr < 0) ? len++ : len;
	}
	return (len);
}


int		ft_puthex(long long i)
{
	char	*base;

	base = "0123456789abcdef";
	if (i == 0)
	{
		ft_putchar_fd(base[0], 1);
		return (1);
	} else if (i > 15)
		return (ft_puthex(i / 16) + ft_puthex(i % 16));
	else
	{
		ft_putchar_fd(base[i], 1);
		return (1);
	}
}
//
//int		put_zero(int wide)
//{
//	int i;
//
//	i = wide;
//	while (i--)
//		ft_putchar_fd(' ', 1);
//	return (wide);
//}