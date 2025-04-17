/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_specifier_handle.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 09:54:24 by asando            #+#    #+#             */
/*   Updated: 2025/04/17 16:21:07 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"

void	write_conversion(unsigned char c, va_list args)
{
	if (c == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (c == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	else if (c == 'p')
	{

	}
	else if (c == 'd' || c == 'i')
	{
		ft_putnbr_fd(va_arg(args, int), 1);
	}
	else if (c == 'u')
	{}
	if (c == 'x'){}
	if (c == 'X'){}
	return (0);
}
