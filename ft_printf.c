/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grvelva <grvelva@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 18:26:12 by grvelva           #+#    #+#             */
/*   Updated: 2020/12/14 14:36:23 by grvelva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	va_list		args;
	int			i;
	s_output	*frmt;
	int			result;

	i = 0;
	result = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] != '%')
		{
			ft_putchar_fd(str[i++], 1);
			result++;
		}
		else
		{
			frmt = frmt_parser(&str[i], args);
			i += frmt->parsed_size;
			result += frmt_print(args, frmt);
			if (frmt)
				free(frmt);
			frmt = NULL;
		}
	}
	va_end(args);
	return (result);
}
