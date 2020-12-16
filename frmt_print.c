/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frmt_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grvelva <grvelva@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 14:23:16 by grvelva           #+#    #+#             */
/*   Updated: 2020/12/16 19:02:02 by grvelva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	frmt_print(va_list args, t_frmt *frmt)
{
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
	if (frmt->type == 'x' || frmt->type == 'X')
		return (print_hex(args, frmt));
	if (frmt->type == 'u')
		return (print_unbr(args, frmt));
	return (print_none(frmt));
}
