/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grvelva <grvelva@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 17:42:30 by grvelva           #+#    #+#             */
/*   Updated: 2020/10/31 17:42:35 by grvelva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	unsigned char chr;

	if (c > 255)
		return (0);
	chr = (unsigned char)c;
	return (((chr >= 65) && (chr <= 90)) || ((chr >= 97) && (chr <= 122)));
}
