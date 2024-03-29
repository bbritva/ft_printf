/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grvelva <grvelva@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 18:35:20 by grvelva           #+#    #+#             */
/*   Updated: 2020/12/21 11:42:58 by grvelva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	char	*str1;
	char	*str2;
	int		ptf_result;
	int		ft_ptf_result;

	str1 = "a123456789a";
	str2 = "b123456789b";
	ptf_result = printf("\"%p\"", &ptf_result);
	printf("\n");
	ft_ptf_result = ft_printf("\"%p\"", &ptf_result);
	printf("\n");
	printf(" my result = %d\n", ft_ptf_result);
	printf("lib result = %d\n", ptf_result);
}
