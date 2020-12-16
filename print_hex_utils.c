/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grvelva <grvelva@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 09:43:52 by grvelva           #+#    #+#             */
/*   Updated: 2020/12/16 20:00:30 by grvelva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		hex_len(long long nbr)
{
	int nbr_len;

	nbr_len = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		nbr = -nbr;
	while (nbr > 0 && ++nbr_len)
		nbr = nbr / 16;
	return (nbr_len);
}

int		output_hlen(t_frmt *frmt, long long nbr)
{
	int	len;

	len = hex_len(nbr);
	len = (frmt->wide > len) ? frmt->wide : len;
	if (frmt->precision > len)
	{
		len = frmt->precision;
		(nbr < 0) ? len++ : len;
	}
	return (len);
}

int		ft_puthex(long long i, char *base)
{
	if (i == 0)
	{
		ft_putchar_fd(base[0], 1);
		return (1);
	}
	else if (i > 15)
		return (ft_puthex(i / 16, base) + ft_puthex(i % 16, base));
	else
	{
		ft_putchar_fd(base[i], 1);
		return (1);
	}
}
