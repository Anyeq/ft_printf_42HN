/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:01:30 by asando            #+#    #+#             */
/*   Updated: 2025/04/25 12:18:06 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	putptr_out(uintptr_t n)
{
	if (n / 16 > 0)
		putptr_out(n / 16);
	write(STDOUT_FILENO, &("0123456789abcdef"[n % 16]), 1);
	return ;
}

static int	putptr_main(void *n)
{
	int	n_digit;

	if (n == NULL)
	{
		write(STDOUT_FILENO, "(nil)", 5);
		return (5);
	}
	n_digit = count_digit_ptr((uintptr_t)n);
	putptr_out((uintptr_t)n);
	return (n_digit);
}

static int	count_nstr(void *n, int precision)
{
	int			main_digit;
	uintptr_t	num;

	main_digit = 0;
	num = (uintptr_t)n;
	if (n == NULL)
		return (main_digit);
	while (num / 16 > 0)
	{
		num /= 16;
		main_digit++;
	}
	main_digit++;
	if (precision > main_digit)
		main_digit = precision;
	return (main_digit + 2);
}

static int	null_case(t_prse *prse)
{
	int	nd;

	nd = 5;
	if ((prse->width > 0 || prse->precision > 0) && prse->flag_minus == 0)
	{
		nd += write_width(prse->width, prse->precision, prse->flag_zero, 5);
		write(STDOUT_FILENO, "(nil)", 5);
		return (nd);
	}
	else if ((prse->width > 0 || prse->precision > 0) && prse->flag_minus == 1)
	{
		write(STDOUT_FILENO, "(nil)", 5);
		nd += write_width(prse->width, prse->precision, prse->flag_zero, 5);
		return (nd);
	}
	else
	{
		write(STDOUT_FILENO, "(nil)", 5);
		return (nd);
	}
	return (nd);
}

int	ft_putptr(void *n, t_prse *prse)
{
	int	nd;
	int	nstr;

	nstr = count_nstr(n, prse->precision);
	nd = 0;
	if (n == NULL)
	{
		nd += null_case(prse);
		return (nd);
	}
	if (prse->flag_minus == 0)
	{
		nd += write_width(prse->width, prse->precision, prse->flag_zero, nstr);
		nd += write_sign(prse, 42, "0x");
		nd += write_precision(prse->precision, nstr - 2);
		nd += putptr_main(n);
	}
	else if (prse->flag_minus == 1)
	{
		nd += write_sign(prse, 42, "0x");
		nd += write_precision(prse->precision, nstr - 2);
		nd += putptr_main(n);
		nd += write_width(prse->width, prse->precision, prse->flag_zero, nstr);
	}
	return (nd);
}
