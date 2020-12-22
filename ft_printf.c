/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grvelva <grvelva@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 18:26:12 by grvelva           #+#    #+#             */
/*   Updated: 2020/12/21 12:08:59 by grvelva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_result(const char *str, va_list args)
{
	int		result;
	t_frmt	*frmt;
	int		tmp;

	result = 0;
	while (*str)
	{
		if (*str != '%')
			result += write(1, str++, 1);
		else if ((frmt = frmt_parser(str, args)))
		{
			str += frmt->parsed_size;
			if ((tmp = (frmt_print(args, frmt))) >= 0)
				result += tmp;
			else
			{
				free(frmt);
				return (-1);
			}
			free(frmt);
		}
		else
			return (-1);
	}
	return (result);
}

int		ft_printf(const char *str, ...)
{
	va_list		args;
	int			result;

	va_start(args, str);
	result = get_result(str, args);
	va_end(args);
	return (result);
}
