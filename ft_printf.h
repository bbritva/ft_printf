/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grvelva <grvelva@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 18:28:40 by grvelva           #+#    #+#             */
/*   Updated: 2020/12/09 11:20:31 by grvelva          ###   ########.fr       */
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

typedef struct
{
	void			*content;
	unsigned int	flag;
	int				wide;
	int				precision;
	char			type;
	int				dbl_type;
	int				parsed_size;

}					s_output;

int			ft_printf(const char *str, ...);
s_output	*frmt_parser(const char *str, va_list args);
int			frmt_print(va_list args, s_output *frmt);
int			print_string(va_list args, s_output *frmt);
size_t		output_len(s_output *frmt, char *str);
size_t		s_len(s_output *frmt, char *str);
size_t		output_nlen(s_output *frmt, int nbr);
size_t		n_len(s_output *frmt, int nbr);
void		put_left(size_t len, size_t str_len, char *str, char empty);
void		put_right(size_t len, size_t str_len, char *str, char empty);
void		putchar_left(size_t len, char c, char empty);
void		putchar_right(size_t len, char c, char empty);
size_t		putchar_len(s_output *frmt);
int			print_char(char c, s_output *frmt);
int			print_ptr(va_list args, s_output *frmt);
char		*ft_ptrtostr(long long int nbr, char *base);
int			print_nbr(va_list args, s_output *frmt);


#endif
