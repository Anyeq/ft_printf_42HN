/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 13:50:53 by asando            #+#    #+#             */
/*   Updated: 2025/04/25 13:56:07 by asando           ###   ########.fr       */
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

static int	print_arg(t_prse *prse, const char *s)
{
	int	n_digit;

	n_digit = 0;
	if (prse->flag_dot == 1 && prse->precision == 0)
	{
		write(STDOUT_FILENO, "", 1);
		return (n_digit);
	}
	n_digit += putstr_out(s, prse->precision);
	return (n_digit);
}

static int	null_case(t_prse *prse)
{
	int	nd;
	int	nstr;

	nd = 0;
	nstr = 6;
	if (prse->flag_dot == 1 && prse->precision == 0)
		nstr = 0;
	if (prse->flag_minus == 0)
	{
		nd += write_width(prse->width, prse->precision, prse->flag_zero, nstr);
		nd += print_arg(prse, "(null)");
	}
	else if (prse->flag_minus == 1)
	{
		nd += print_arg(prse, "(null)");
		nd += write_width(prse->width, prse->precision, prse->flag_zero, nstr);
	}
	return (nd);
}

static int	print_str(const char *s, t_prse *prse, int precision, int len_str)
{
	int	n_digit;

	n_digit = 0;
	if (prse->flag_dot == 1 && prse->precision == 0)
		len_str = 0;
	if (prse->flag_minus == 0)
	{
		n_digit += write_width(prse->width, precision, 0, len_str);
		n_digit += print_arg(prse, s);
	}
	else if (prse->flag_minus == 1)
	{
		n_digit += print_arg(prse, s);
		n_digit += write_width(prse->width, precision, 0, len_str);
	}
	return (n_digit);
}

int	ft_putstr(const char *s, t_prse *prse)
{
	int	n_digit;
	int	len_str;
	int	precision;

	if (s == NULL)
		return (null_case(prse));
	precision = prse->precision;
	n_digit = 0;
	len_str = ft_strlen(s);
	if (len_str > precision && precision != 0)
		len_str = 0;
	else if (len_str <= precision && precision != 0)
		precision = 0;
	n_digit += print_str(s, prse, precision, len_str);
	return (n_digit);
}
