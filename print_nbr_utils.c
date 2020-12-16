/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grvelva <grvelva@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 09:43:52 by grvelva           #+#    #+#             */
/*   Updated: 2020/12/16 20:26:31 by grvelva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		n_len(long long nbr)
{
	int nbr_len;

	nbr_len = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		nbr = -nbr;
	while (nbr > 0 && ++nbr_len)
		nbr = nbr / 10;
	return (nbr_len);
}

int		output_nlen(t_frmt *frmt, long long nbr)
{
	int	len;

	len = n_len(nbr);
	len = (frmt->wide > len) ? frmt->wide : len;
	if (frmt->precision > len)
	{
		len = frmt->precision;
		(nbr < 0) ? len++ : len;
	}
	return (len);
}

int		ft_putnbr(long long i)
{
	if (i == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	else if (i > 9)
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
