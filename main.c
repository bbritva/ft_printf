/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grvelva <grvelva@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 18:35:20 by grvelva           #+#    #+#             */
/*   Updated: 2020/12/16 09:42:22 by grvelva          ###   ########.fr       */
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

	str1 = "a123456789a";
	str2 = "b123456789b";
	ptf_result = printf("lib:\"%03d\"", -1234);
    printf("\n");
	ft_ptf_result = ft_printf(" my:\"%03d\"", -1234);
    printf("\n");
	printf(" my result = %d\n", ft_ptf_result);
	printf("lib result = %d\n", ptf_result);
}
