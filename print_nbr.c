/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grvelva <grvelva@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 09:43:52 by grvelva           #+#    #+#             */
/*   Updated: 2020/12/12 11:34:03 by grvelva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_nbr(va_list args, s_output *frmt)
{
	int		nbr;
	char	empty;
	int 	len;

	(void) frmt;
	nbr = va_arg(args, int);
	len = 0;
	empty = ((frmt->flag & ZERO) && frmt->precision != -1) ? '0' : ' ';
	if (frmt->flag & MINUS)
		len = putnbr_left(frmt, nbr, ' ');
//	else
//		len = putnbr_right(frmt, nbr, empty);
	return (len);
}

int 	putnbr_left(s_output *frmt, int nbr, char empty)
{
	size_t	len;
	size_t	i;

	len = output_nlen(frmt, nbr);
	i = 0;
	if (nbr < 0)
	{
		ft_putchar_fd('-', 1);
		i++;
		while ((i - 1) < (frmt->precision - n_len(nbr)))
		{
			ft_putchar_fd('0', 1);
			i++;
		}
	}
	(nbr > 0) ? ft_putnbr(nbr) : ft_putnbr(-nbr);
	i += (nbr > 0) ? n_len(nbr) : n_len(nbr) + 1;
	while (i < len)
	{
		ft_putchar_fd(empty, 1);
		i++;
	}
	return (len);
}

//void	putnbr_right(size_t len, size_t nbr_len, int nbr, char empty)
//{
//	size_t i;
//
//	i = 0;
//	if (nbr < 0)
//		ft_putchar_fd('-', 1);
//	while (i++ < (len - nbr_len))
//		ft_putchar_fd('0', 1);
//	ft_putnbr_fd(-nbr, 1);
//	while (i++ < len)
//		ft_putchar_fd(empty, 1);
//}

size_t	n_len(int nbr)
{
	size_t nbr_len;

	nbr_len = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
//		nbr_len++;
	}
	while (nbr > 0 && ++nbr_len)
		nbr = nbr / 10;
	return (nbr_len);
}

size_t	output_nlen(s_output *frmt, int nbr)
{
	size_t	len;

	len = n_len(nbr);
	len = (frmt->wide > (int)len) ? frmt->wide : len;
	return (len);
}


int		ft_putnbr(int i)
{
	if (i == -2147483648)
	{
		ft_putstr_fd("-2147483648", 1);
		return (11);
	} else if (i < 0)
	{
		ft_putchar_fd('-', 1);
		return (ft_putnbr(-i) + 1);
	} else if (i == 0)
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