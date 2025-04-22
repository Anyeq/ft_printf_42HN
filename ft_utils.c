/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 09:40:56 by asando            #+#    #+#             */
/*   Updated: 2025/04/22 09:54:45 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

static int	write_width(size_t width, size_t precision, int f_zero, size_t nstr)
{
	int	nchar;

	nchar = 0;
	while (nchar < (width - (nstr + precision))
	{
		if (f_zero == 1)
			write(STDOUT_FILENO, "0", 1);
		else if (f_zero == 0)
			write(STDOUT_FILENO, " ", 1);
		nchar++;
	}
	return (nchar);
}

static int	write_precision(size_t precision, int nstr)
{
	int	nchar;

	nchar = 0;
	while (nchar < (precision - nstr))
	{
		write(STDOUT_FILENO, "0", 1);
		nchar++;
	}
	return (nchar);
}

int	write_wnp(t_prse *prse, int nstr, void *num, void (*func)(void *))
{
	int	nchar;

	nchar = 0;
	if (prse->flag_minus == 0 && prse->width > 0)
	{
		nchar += write_width(prse->width, prse->precision, prse->flag_zero, nstr);
		nchar += write_precision(prse->precision, nstr);
		func(num);
	}
	else if (prse->flag_minus > 0 && prse->width > 0)
	{
		nchar += write_precision(prse->precision, nstr);
		func(num);
		nchar += write_width(prse->width, prse->precision, 0, nstr);
	}
	return (nchar);
}
