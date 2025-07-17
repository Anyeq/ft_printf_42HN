/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:01:30 by asando            #+#    #+#             */
/*   Updated: 2025/07/17 10:56:33 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	putunint_out(unsigned int n, t_prse *prse)
{
	char	c;

	if (n == 0)
	{
		if (write(1, "0", 1) < 1)
		{
			prse->write_err = 1;
			return ;
		}
		return ;
	}
	if (n / 10 > 0 && prse->write_err != 1)
		putunint_out(n / 10, prse);
	c = (n % 10) + '0';
	if (prse->write_err != 1)
	{
		if (write(1, &c, 1) < 1)
		{
			prse->write_err = 1;
			return ;
		}
	}
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
		putunint_out(n, prse);
		if (prse->write_err == 1)
			return (-1);
	}
	else if (prse->flag_minus == 1)
	{
		nd += write_precision(prse->precision, nstr);
		putunint_out(n, prse);
		if (prse->write_err == 1)
			return (-1);
		nd += write_width(prse->width, prse->precision, prse->flag_zero, nstr);
	}
	return (nd);
}
