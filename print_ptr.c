/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grvelva <grvelva@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 09:43:52 by grvelva           #+#    #+#             */
/*   Updated: 2020/12/13 11:44:21 by grvelva          ###   ########.fr       */
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
	frmt->precision = -1;
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

int 	ptr_size(long long int nbr)
{
	int ptr_len;

	ptr_len = 0;
	while (nbr > 0)
	{
		ptr_len++;
		nbr = nbr / 16;
	}
	return (ptr_len);
}

char	*ft_ptrtostr(long long int nbr, char *base)
{
	char	*str;
	int		i;
	int		size;

	size = ptr_size(nbr) + 3;
	str = (char *)malloc(sizeof(char) * size);
	if (str)
	{
		i = size - 2;
		str[0] = '0';
		str[1] = 'x';
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