/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnum_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:01:30 by asando            #+#    #+#             */
/*   Updated: 2025/04/29 13:25:48 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	putnumbase_out(unsigned int n, int nbase, const char *base)
{
	if (n == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (n / nbase > 0)
		putnumbase_out(n / nbase, nbase, base);
	write(1, &base[n % nbase], 1);
	return ;
}

static char	*sign_choose(t_prse *prse, unsigned int num, const char *base)
{
	char	*str;

	str = NULL;
	if (num == 0)
		return (str);
	if (prse->flag_hashtag == 1 && base[10] == 'A')
		str = "0X";
	else if (prse->flag_hashtag == 1 && base[10] == 'a')
		str = "0x";
	return (str);
}

int	ft_putnum_base(unsigned int n, int nbase, const char *base, t_prse *prse)
{
	int		nstr;
	int		nd;
	char	*sign;

	sign = sign_choose(prse, n, base);
	nstr = count_digit_nbase(n, nbase);
	nd = nstr;
	if (prse->flag_minus == 0)
	{
		nd += write_width(prse->width, prse->precision, prse->flag_zero, nstr);
		nd += write_sign(prse, 42, sign);
		nd += write_precision(prse->precision, nstr);
		putnumbase_out(n, nbase, base);
	}
	else if (prse->flag_minus == 1)
	{
		nd += write_sign(prse, 42, sign);
		nd += write_precision(prse->precision, nstr);
		putnumbase_out(n, nbase, base);
		nd += write_width(prse->width, prse->precision, prse->flag_zero, nstr);
	}
	return (nd);
}
