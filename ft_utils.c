/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 09:40:56 by asando            #+#    #+#             */
/*   Updated: 2025/04/22 10:04:56 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "libftprintf.h"

int	write_width(size_t width, size_t precision, int f_zero, size_t nstr)
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

int	write_precision(size_t precision, int nstr)
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
