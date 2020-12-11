/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grvelva <grvelva@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 09:43:52 by grvelva           #+#    #+#             */
/*   Updated: 2020/12/11 17:08:17 by grvelva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_nbr(va_list args, s_output *frmt)
{
	int		nbr;
//	char	empty;
	int 	len;

	nbr = va_arg(args, int);
	len = 0;
//	empty = ((frmt->flag & ZERO) && frmt->precision != -1) ? '0' : ' ';
	if (frmt->flag & MINUS)
		len = putnbr_left(frmt, nbr, ' ');
//	else
//		len = putnbr_left(frmt, nbr, ' ');
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
		len--;
	}
	while (i++ < (frmt->precision - n_len(nbr)))
		ft_putchar_fd('0', 1);
	(nbr > 0) ? ft_putnbr_fd(nbr, 1) : ft_putnbr_fd(-nbr, 1);
	i += n_len(nbr);
	while (i++ < len)
		ft_putchar_fd(empty, 1);
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
		nbr = -nbr;
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
