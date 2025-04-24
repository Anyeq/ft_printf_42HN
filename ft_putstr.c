/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 13:50:53 by asando            #+#    #+#             */
/*   Updated: 2025/04/24 13:22:12 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	putstr_out(const char *s, int precision)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (precision != 0 && i == precision)
			return (i);
		write(STDOUT_FILENO, &s[i], 1);
		i++;
	}
	return (i);
}

static int	null_case(void)
{
	write(STDOUT_FILENO, "(null)", 6);
	return (6);
}

int	ft_putstr(const char *s, t_prse *prse)
{
	int	n_digit;
	int	len_str;
	int	precision;

	if (s == NULL)
		return (null_case());
	precision = prse->precision;
	n_digit = 0;
	len_str = ft_strlen(s);
	if (len_str > precision && precision != 0)
		len_str = 0;
	else if (len_str <= precision && precision != 0)
		precision = 0;
	if (prse->flag_minus == 0)
	{
		n_digit += write_width(prse->width, precision, 0, len_str);
		n_digit += putstr_out(s, prse->precision);
	}
	else if (prse->flag_minus == 1)
	{
		n_digit += putstr_out(s, prse->precision);
		n_digit += write_width(prse->width, precision, 0, len_str);
	}
	return (n_digit);
}
