/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:01:30 by asando            #+#    #+#             */
/*   Updated: 2025/05/15 12:07:49 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

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
