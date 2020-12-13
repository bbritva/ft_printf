/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grvelva <grvelva@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 09:43:52 by grvelva           #+#    #+#             */
/*   Updated: 2020/12/13 16:22:25 by grvelva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_hex(va_list args, s_output *frmt)
{
	size_t		len;
	size_t		str_len;
	long long	num;
	char 		*str;
	char		empty;

	num = va_arg(args, long long);
	str = ft_hextostr(num, "0123456789abcdef");
	frmt->precision = -1;
	str_len = s_len(frmt, str);
	len = output_len(frmt, str);
	empty = (frmt->flag & ZERO) ? '0' : ' ';
	if (frmt->flag & MINUS)
		put_left(len, str_len, str, ' ');
	else
		put_right(len, str_len, str, empty);
	if (str)
		free (str);
	return (len);
}

int 	hex_size(long long nbr)
{
	int ptr_len;

	ptr_len = 0;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		ptr_len++;
		nbr = nbr / 16;
	}
	return (ptr_len);
}

char	*ft_hextostr(long long nbr, char *base)
{
	char	*str;
	int		i;
	int		size;

	size = hex_size(nbr) + 1;
	str = (char *)malloc(sizeof(char) * size);
	if (str)
	{
		i = size - 2;
		while (nbr / 16 != 0)
		{
			str[i] = base[nbr % 16];
			nbr = nbr / 16;
			i--;
		}
		str[i] = base[nbr];
		str[size - 1] = 0;
	}
	return (str);
}