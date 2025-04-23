/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:01:30 by asando            #+#    #+#             */
/*   Updated: 2025/04/23 11:06:56 by asando           ###   ########.fr       */
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
static int	count_digit(uintptr_t n)
{
	int	n_digit;

	n_digit = 0;
	while (n > 0)
	{
		n = n / 16;
		n_digit++;
	}
	return (n_digit);
}

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
	n_digit = count_digit((uintptr_t)n);
	putptr_out((uintptr_t)n);
	return (n_digit);
}

int	ft_putptr(void *n, t_prse *prse)
{
	int	n_digit;
	int	str_size;

	str_size = 14;
	n_digit = 0;
	if (prse->precision > 12)
		str_size = (prse->precision - 12) + 14;
	if ((prse->width > 0 || prse->precision > 0) && prse->flag_minus == 0)
	{
		n_digit += write_width(prse->width, prse->precision, prse->flag_zero, str_size);
		n_digit += write_sign(prse->flag_plus, 42, "0x");
		n_digit += write_precision(prse->precision, 12);
		n_digit += putptr_main(n);
	}
	else if ((prse->width > 0 || prse->precision > 0) && prse->flag_minus == 1)
	{
		n_digit += write_sign(prse->flag_plus, 42, "0x");
		n_digit += write_precision(prse->precision, 12);
		n_digit += putptr_main(n);
		n_digit += write_width(prse->width, prse->precision, prse->flag_zero, str_size);
	}
	else
	{
		n_digit += write_sign(prse->flag_plus, 42, "0x");
		n_digit += putptr_main(n);
	}
	return (n_digit);
}
