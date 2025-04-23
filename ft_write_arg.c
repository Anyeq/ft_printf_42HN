/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 09:54:24 by asando            #+#    #+#             */
/*   Updated: 2025/04/23 16:11:30 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf.h"

int	write_arg(unsigned char c, va_list args, t_prse *prse)
{
	int			nchar;
	const char	*xsmall;
	const char	*xbig;

	xsmall = "0123456789abcdef";
	xbig = "0123456789ABCDEF";
	nchar = 0;
	if (c == 'c')
		nchar += ft_putchar(va_arg(args, unsigned int), prse);
	else if (c == 's')
		nchar += ft_putstr(va_arg(args, char *), prse);
	else if (c == 'p')
		nchar += ft_putptr(va_arg(args, void *), prse);
	else if (c == 'd' || c == 'i')
		nchar += ft_putint(va_arg(args, int), prse);
	else if (c == 'u')
		nchar += ft_putunint(va_arg(args, unsigned int), prse);
	if (c == 'x')
		nchar += ft_putnum_base(va_arg(args, unsigned int), 16, xsmall, prse);
	if (c == 'X')
		nchar += ft_putnum_base(va_arg(args, unsigned int), 16, xbig, prse);
	return (nchar);
}
