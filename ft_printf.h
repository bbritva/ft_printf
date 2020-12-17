/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grvelva <grvelva@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 18:28:40 by grvelva           #+#    #+#             */
/*   Updated: 2020/12/17 11:14:19 by grvelva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# define ZERO 16
# define MINUS 8
# define SHARP 4
# define SPACE 2
# define PLUS 1

typedef	struct
{
	unsigned int	flag;
	int				wide;
	int				precision;
	char			type;
	int				dbl_type;
	int				parsed_size;
}					t_frmt;

int					ft_printf(const char *str, ...);
t_frmt				*frmt_parser(const char *str, va_list args);
int					frmt_print(va_list args, t_frmt *frmt);
int					print_string(va_list args, t_frmt *frmt);
size_t				output_len(t_frmt *frmt, char *str);
size_t				s_len(t_frmt *frmt, char *str);
int					output_nlen(t_frmt *frmt, long long nbr);
int					n_len(long long nbr);
int					output_hlen(t_frmt *frmt, long long nbr);
int					hex_len(long long nbr);
void				put_left(size_t len, size_t str_len, char *str,
					char empty);
void				put_right(size_t len, size_t str_len, char *str,
					char empty);
int					putnbr_left(t_frmt *frmt, long long nbr, char empty);
int					putnbr_right(t_frmt *frmt, long long nbr, char empty);
int					puthex_left(t_frmt *frmt, long long nbr, char empty,
					char *base);
int					puthex_right(t_frmt *frmt, long long nbr, char empty,
					char *base);
void				putchar_left(size_t len, char c, char empty);
void				putchar_right(size_t len, char c, char empty);
size_t				putchar_len(t_frmt *frmt);
int					print_char(char c, t_frmt *frmt);
int					print_ptr(va_list args, t_frmt *frmt);
char				*ft_ptrtostr(unsigned long nbr, char *base);
int					print_nbr(va_list args, t_frmt *frmt);
int					print_unbr(va_list args, t_frmt *frmt);
int					ft_putnbr(long long i);
int					ft_puthex(long long i, char *base);
int					put_zero(int i);
int					print_hex(va_list args, t_frmt *frmt);
int					print_none(t_frmt *frmt);
void				put_none(size_t len, char empty);

#endif
