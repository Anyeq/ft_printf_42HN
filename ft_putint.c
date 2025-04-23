/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:01:30 by asando            #+#    #+#             */
/*   Updated: 2025/04/23 18:07:47 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf.h"
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
static void	putint_out(int n)
{
	char	c;

	if (n == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (n == INT_MIN)
	{
		return ;
		write(1, "2147483648", 10);
	}
	if (n < 0)
		n = n * -1;
	if (n / 10 > 0)
		putint_out(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
	return ;
}

static void	width_precision_fix(int n, int f_plus, int *nstr, int *prcs)
{
	if (n < 0 || f_plus == 1)
	{
		*nstr += 1;
		*prcs += 1;
	}
}

int	ft_putint(int n, t_prse *prse)
{
	int	nd;
	int	nstr;
	int	nstr_prcs;
	int	prcs;

	nstr = count_digit_int(n);
	nstr_prcs = count_digit_int(n);
	nd = nstr;
	prcs = prse->precision;
	width_precision_fix(n, prse->flag_plus, &nstr, &prcs);
	if (prse->flag_minus == 0)
	{
		nd += write_width(prse->width, prcs, prse->flag_zero, nstr);
		nd += write_sign(prse->flag_plus, n, NULL);
		nd += write_precision(prse->precision, nstr_prcs);
		putint_out(n);
	}
	else if (prse->flag_minus == 1)
	{
		nd += write_sign(prse->flag_plus, n, NULL);
		nd += write_precision(prse->precision, nstr_prcs);
		putint_out(n);
		nd += write_width(prse->width, prcs, prse->flag_zero, nstr);
	}
	return (nd);
}
