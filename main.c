/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grvelva <grvelva@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 18:35:20 by grvelva           #+#    #+#             */
/*   Updated: 2020/12/13 14:51:28 by grvelva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	char *str1;
	char *str2;
	int ptf_result;
	int ft_ptf_result;
//{%05.*d}", -15, 42
	str1 = "a123456789a";
	str2 = "b123456789b";
	ptf_result = printf("lib:\"%u\"", 4294967295u);
    printf("\n");
	ft_ptf_result = ft_printf(" my:\"%u\"", 4294967295u);
    printf("\n");
	printf(" my result = %d\n", ft_ptf_result);
	printf("lib result = %d\n", ptf_result);
}
