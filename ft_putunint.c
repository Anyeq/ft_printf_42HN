/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:01:30 by asando            #+#    #+#             */
/*   Updated: 2025/04/23 23:06:12 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
/*
 * FUNCTION (G)
 * ==> put number into fd provided
 * CALLED FUNCTION
 * ==> write(unistd.h)
 * PARAMETER (n = 2)
 * ==> 1.int 2.int
 * WORK
 * ==> devide by ten to get every digit and write it to fd
 * ==> if number consist a sign multiplyit to -1 to get positif number
 * ==> write sign separately
 * ==> if number == INT_MIN from limits.h write it on fd right away
 * RETURN
 * ==> none
 * REFERENCE
 * ==>
*/
static void	putunint_out(unsigned int n)
{
	char	c;

	if (n == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (n / 10 > 0)
		putunint_out(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
	return ;
}

int	ft_putunint(unsigned int n, t_prse *prse)
{
	int	nstr;
	int	nd;

	nstr = count_digit_uint(n);
	nd = nstr;
	if (prse->flag_minus == 0)
	{
		nd += write_width(prse->width, prse->precision, prse->flag_zero, nstr);
		nd += write_precision(prse->precision, nstr);
		putunint_out(n);
	}
	else if (prse->flag_minus == 1)
	{
		nd += write_precision(prse->precision, nstr);
		putunint_out(n);
		nd += write_width(prse->width, prse->precision, prse->flag_zero, nstr);
	}
	return (nd);
}
