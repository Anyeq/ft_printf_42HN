/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 09:40:56 by asando            #+#    #+#             */
/*   Updated: 2025/04/23 10:26:58 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf.h"

static int	count_str_size(int precision, int nstr)
{
	int	str_size;

	if (precision > nstr)
		str_size = precision;
	else if (precision <= nstr)
		str_size = nstr;
	return (str_size);
}

int	write_width(int width, int precision, int f_zero, int nstr)
{
	int	nchar;
	int	str_size;

	str_size = count_str_size(precision, nstr);
	nchar = 0;
	while (nchar < (width - str_size))
	{
		if (f_zero == 1 && precision == 0)
			write(STDOUT_FILENO, "0", 1);
		else if (f_zero == 0)
			write(STDOUT_FILENO, " ", 1);
		nchar++;
	}
	return (nchar);
}

int	write_precision(int precision, int nstr)
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

int	write_sign(int flag_plus, int num, char *sign)
{
	int	nchar;

	nchar = 0;
	if (num < 0)
	{
		write(STDOUT_FILENO, "-", 1);
		nchar++;
	}
	else if (num > 0 && flag_plus == 1)
	{
		write(STDOUT_FILENO, "+", 1);
		nchar++;
	}
	if (sign != NULL)
	{
		write(STDOUT_FILENO, sign, 2);
		nchar += 2;
	}
	return (nchar);
}
