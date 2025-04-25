/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 13:50:53 by asando            #+#    #+#             */
/*   Updated: 2025/04/25 09:21:33 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putchar(unsigned int s, t_prse *prse)
{
	int	n_digit;

	n_digit = 0;
	if (prse->flag_minus == 0 && prse->no_spec == 0)
	{
		n_digit += write_width(prse->width, prse->precision, 0, 1);
		write(STDOUT_FILENO, &s, 1);
		return (n_digit + 1);
	}
	else if (prse->flag_minus == 1 && prse->no_spec == 0)
	{
		write(STDOUT_FILENO, &s, 1);
		n_digit += write_width(prse->width, prse->precision, 0, 1);
		return (n_digit + 1);
	}
	write(STDOUT_FILENO, &s, 1);
	return (n_digit + 1);
}
