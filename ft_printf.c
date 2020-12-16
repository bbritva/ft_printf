/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grvelva <grvelva@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 18:26:12 by grvelva           #+#    #+#             */
/*   Updated: 2020/12/16 19:48:14 by grvelva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	va_list		args;
	t_frmt		*frmt;
	int			result;

	result = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str != '%')
			result += write(1, str++, 1);
		else
			if ((frmt = frmt_parser(str, args)))
			{
				str += frmt->parsed_size;
				result += frmt_print(args, frmt);
				free(frmt);
			}
			else
			{
				result = -1;
				break;
			}
	}
	va_end(args);
	return (result);
}
