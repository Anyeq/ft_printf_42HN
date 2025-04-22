/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 09:54:24 by asando            #+#    #+#             */
/*   Updated: 2025/04/22 08:26:19 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include "libftprintf.h"

static int	write_width(t_prse *prse, size_t nstr)
{
	int	nchar;

	nchar = 0;
	while (nchar < (prse->width - (nstr + prse->precision))
	{
		if (prse->sign_zero == 1)
			write(STDOUT_FILENO, "0", 1);
		else if (prse->sign_zero == 0)
			write(STDOUT_FILENO, " ", 1);
		nchar++;
	}
	return (nchar);
}

static int	write_precision(t_prse *prse, size_t nstr)
{
	int	nchar;

	nchar = 0;
	while (nchar < (prse->precision - nstr))
	{
		write(STDOUT_FILENO, "0", 1);
		nchar++;
	}
	return (nchar);
}

static int	write_conversion(unsigned char c, va_list args, t_prse *prse)
{
	int	nchar;

	nchar = 0;
	if (c == 'c')
		nchar += ft_putchar(va_arg(args, unsigned int));
	else if (c == 's')
		nchar += ft_putstr(va_arg(args, char *), prse->precision);
	else if (c == 'p')
		nchar += ft_putptr(va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		nchar += ft_putint(va_arg(args, int));
	else if (c == 'u')
		nchar += ft_putunint(va_arg(args, unsigned int));
	if (c == 'x')
		nchar += ft_putnum_base(va_arg(args, unsigned int), 16, "0123456789abcdef");
	if (c == 'X')
		nchar += ft_putnum_base(va_arg(args, unsigned int), 16, "0123456789ABCDEF");
	return (nchar);
}

int	write_arg(unsigned char c, va_list *args, t_prse **prse)
{
	int	nchar;

	nchar = 0;
	nchar += write_conversion(c, args, prse);
	return (0);
}
