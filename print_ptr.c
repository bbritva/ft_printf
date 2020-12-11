/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grvelva <grvelva@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 09:43:52 by grvelva           #+#    #+#             */
/*   Updated: 2020/12/07 15:16:35 by grvelva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_ptr(va_list args, s_output *frmt)
{
	size_t		len;
	size_t		str_len;
	uintptr_t	ptr;
	char 		*str;
	char		empty;

	ptr = va_arg(args, uintptr_t);
	str = (ptr) ? ft_ptrtostr(ptr, "0123456789abcdef") : "0x0";
	str_len = s_len(frmt, str);
	len = output_len(frmt, str);
	empty = (frmt->flag & ZERO) ? '0' : ' ';
	if (frmt->flag & MINUS)
		put_left(len, str_len, str, ' ');
	else
		put_right(len, str_len, str, empty);
	if (ft_strlen(str) > 5)
		free (str);
	return (len);
}

char	*ft_ptrtostr(long long int nbr, char *base)
{
	char	*str;
	int		i;

	str = (char *)malloc(12);
	if (str)
	{
		i = 0;
		while (i < 11)
			str[i++] = '0';
		str[1] = 'x';
		str[2] = '1';
		i = 10;
		while (nbr / 16 != 0)
		{
			str[i] = base[nbr % 16];
			nbr = nbr / 16;
			i--;
		}
		str[i] = base[nbr];
		str[11] = 0;
	}
	return (str);
}