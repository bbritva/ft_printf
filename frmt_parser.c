/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frmt_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grvelva <grvelva@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 19:05:49 by grvelva           #+#    #+#             */
/*   Updated: 2020/12/09 11:20:35 by grvelva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void gggg(int i);

int			flag_parse(const char *str, int len, s_output *frmt)
{
	frmt->flag = 0;
	while (ft_strchr("-0# +", (int)str[len]))
	{
		(str[len] == '0') ? frmt->flag = frmt->flag | ZERO : frmt->flag;
		(str[len] == '-') ? frmt->flag = frmt->flag | MINUS : frmt->flag;
		(str[len] == '#') ? frmt->flag = frmt->flag | SHARP : frmt->flag;
		(str[len] == ' ') ? frmt->flag = frmt->flag | SPACE : frmt->flag;
		(str[len++] == '+') ? frmt->flag = frmt->flag | PLUS : frmt->flag;
	}
	return (len);
}

int			wide_parse(const char *str, int len, s_output *frmt, va_list args)
{
	frmt->wide = 0;
	if (str[len] == '*')
	{
		frmt->wide = va_arg(args, int);
		len++;
	}
	else
		while (ft_isdigit(str[len]))
			if (frmt->wide > 0)
				frmt->wide = frmt->wide * 10 + (str[len++] - '0');
			else
				frmt->wide = str[len++] - '0';
	return (len);
}

int			precsn_parse(const char *str, int len, s_output *frmt, va_list args)
{
	frmt->precision = -1;
	if (str[len] == '.')
	{
		frmt->precision = 0;
		len++;
		if (str[len] == '*')
		{
			frmt->precision = va_arg(args, int);
			len++;
		}
		else
			while (ft_isdigit(str[len]))
				frmt->precision = frmt->precision * 10 + (str[len++] - '0');
	}
	return (len);
}

int			type_parse(const char *str, int len, s_output *frmt)
{
	frmt->dbl_type = 0;
	frmt->type = ft_strchr("cspdiuxX%nfgelh", (int)str[len++])[0];
	if (frmt->type == 'l' && str[len] == 'l')
	{
		frmt->dbl_type = 1;
		len++;
	}
	if (frmt->type == 'h' && str[len] == 'h')
	{
		frmt->dbl_type = 1;
		len++;
	}
	return (len);
}

s_output	*frmt_parser(const char *str, va_list args)
{
	s_output	*frmt;
	int			len;

	len = 1;
	if ((frmt = (s_output *)malloc(sizeof(s_output))))
	{
		len = flag_parse(str, len, frmt);
		len = wide_parse(str, len, frmt, args);
		if (frmt->wide < 0)
		{
			frmt->wide = -frmt->wide;
			frmt->flag = frmt->flag | MINUS;
		}
		len = precsn_parse(str, len, frmt, args);
		len = type_parse(str, len, frmt);
		frmt->parsed_size = len;
	}
	return (frmt);
}

