/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grvelva <grvelva@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 09:43:52 by grvelva           #+#    #+#             */
/*   Updated: 2020/12/13 14:14:22 by grvelva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_nbr(va_list args, s_output *frmt)
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
			len = putnbr_left(frmt, nbr, ' ');
		else
			len = putnbr_right(frmt, nbr, empty);
	}
	return (len);
}

int 	putnbr_left(s_output *frmt, long long nbr, char empty)
{
	int	wide;
	int	i;
	int num_len;
	int	prec;

	wide = output_nlen(frmt, nbr);
	num_len = n_len(nbr);
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
	i += (nbr < 0) ? ft_putnbr(-nbr) : ft_putnbr(nbr);
	while (i < wide)
	{
		ft_putchar_fd(empty, 1);
		i++;
	}
	return (wide);
}

int	putnbr_right(s_output *frmt, long long nbr, char empty)
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
	(nbr < 0) ? ft_putnbr(-nbr) : ft_putnbr(nbr);
	return (wide);
}

size_t	n_len(long long nbr)
{
	size_t nbr_len;

	nbr_len = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		nbr = -nbr;
	while (nbr > 0 && ++nbr_len)
		nbr = nbr / 10;
	return (nbr_len);
}

size_t	output_nlen(s_output *frmt, long long nbr)
{
	size_t	len;

	len = n_len(nbr);
	len = (frmt->wide > (int)len) ? frmt->wide : len;
	if (frmt->precision > (int)len)
	{
		len = frmt->precision;
		(nbr < 0) ? len++ : len;
	}
	return (len);
}


int		ft_putnbr(long long i)
{
//	if (i == -2147483648)
//	{
//		ft_putstr_fd("-2147483648", 1);
//		return (11);
//	} else if (i < 0)
//	{
//		ft_putchar_fd('-', 1);
//		return (ft_putnbr(-i) + 1);
//	} else
	if (i == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	} else if (i > 9)
		return (ft_putnbr(i / 10) + ft_putnbr(i % 10));
	else
	{
		ft_putchar_fd(i + '0', 1);
		return (1);
	}
}

int		put_zero(int wide)
{
	int i;

	i = wide;
	while (i--)
		ft_putchar_fd(' ', 1);
	return (wide);
}