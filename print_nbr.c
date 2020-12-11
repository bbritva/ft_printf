/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grvelva <grvelva@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 09:43:52 by grvelva           #+#    #+#             */
/*   Updated: 2020/12/11 13:51:05 by grvelva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_nbr(va_list args, s_output *frmt)
{
	size_t	len;
	size_t	nbr_len;
	int		nbr;
	char	empty;

	nbr = va_arg(args, int);
//	if (!str)
//		str = "(null)";
	nbr_len = n_len(frmt, nbr);
	len = output_nlen(frmt, nbr);
	empty = (frmt->flag & ZERO) ? '0' : ' ';
	if (frmt->flag & MINUS)
		put_left(len, str_len, str, ' ');
	else
		put_right(len, str_len, str, empty);
	return (len);
}

void	put_left(size_t len, size_t str_len, char *str, char empty)
{
	size_t i;

	i = 0;
	while (i < str_len && i < len)
		ft_putchar_fd(str[i++], 1);
	while (i++ < len)
		ft_putchar_fd(empty, 1);
}

void	put_right(size_t len, size_t str_len, char *str, char empty)
{
	size_t i;

	i = 0;
	while ((int)i++ < ((int)len - (int)str_len))
		ft_putchar_fd(empty, 1);
	while (i++ <= len)
		ft_putchar_fd(*str++, 1);
}

size_t	n_len(s_output *frmt, int nbr)
{
	size_t nbr_len;

	nbr_len = (nbr > 0) ? 0 : 1;
	while (nbr > 0 && ++nbr_len)
		nbr = nbr / 10;
	nbr_len = (frmt->precision > (int)nbr_len) ? frmt->precision : nbr_len;
	return (nbr_len);
}

size_t	output_nlen(s_output *frmt, char *str)
{
	size_t	len;

	if (frmt->precision > -1 && frmt->precision < (int)ft_strlen(str))
		len = frmt->precision;
	else
		len = ft_strlen(str);
	if (frmt->wide > -1)
		len = ((size_t)frmt->wide > len) ? frmt->wide : len;
	return (len);
}
