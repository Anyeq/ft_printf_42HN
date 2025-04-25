/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:01:30 by asando            #+#    #+#             */
/*   Updated: 2025/04/25 12:17:39 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

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
		write(1, "2147483648", 10);
		return ;
	}
	if (n < 0)
		n = n * -1;
	if (n / 10 > 0)
		putint_out(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
	return ;
}

static void	width_precision_sign(int n, int f_plus, int *nstr, int *prcs)
{
	if (n < 0 || f_plus == 1)
	{
		*nstr += 1;
		*prcs += 1;
	}
}

static void	print_arg(int n, int f_dot, int precision)
{
	if (f_dot == 1 && precision == 0)
	{
		write(STDOUT_FILENO, "", 1);
		return ;
	}
	putint_out(n);
	return ;
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
	width_precision_sign(n, prse->flag_plus, &nstr, &prcs);
	if (prse->flag_minus == 0)
	{
		nd += write_width(prse->width, prcs, prse->flag_zero, nstr);
		nd += write_sign(prse, n, NULL);
		nd += write_precision(prse->precision, nstr_prcs);
		print_arg(n, prse->flag_dot, prse->precision);
	}
	else if (prse->flag_minus == 1)
	{
		nd += write_sign(prse, n, NULL);
		nd += write_precision(prse->precision, nstr_prcs);
		print_arg(n, prse->flag_dot, prse->precision);
		nd += write_width(prse->width, prcs, prse->flag_zero, nstr);
	}
	return (nd);
}
