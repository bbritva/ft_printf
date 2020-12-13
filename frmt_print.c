/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frmt_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grvelva <grvelva@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 14:23:16 by grvelva           #+#    #+#             */
/*   Updated: 2020/12/07 12:02:15 by grvelva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	frmt_print(va_list args, s_output *frmt)
{
//	 printf("flag = %d\n", frmt->flag);
//	 printf("wide = %d\n", frmt->wide);
//	 printf("precision = %d\n", frmt->precision);
//	 printf("type = %c\n", frmt->type);
//	 printf("dbl_type = %d\n", frmt->dbl_type);
	if (frmt->type == 's')
		return (print_string(args, frmt));
	if (frmt->type == 'c')
		return (print_char((char)va_arg(args, int), frmt));
	if (frmt->type == 'p')
		return (print_ptr(args, frmt));
	if (frmt->type == '%')
		return (print_char('%', frmt));
	if (frmt->type == 'd' || frmt->type == 'i')
		return (print_nbr(args, frmt));
	return (0);
}
