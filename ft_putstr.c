/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 13:50:53 by asando            #+#    #+#             */
/*   Updated: 2025/04/22 13:21:23 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf.h"
#include "./libft/libft.h"
/*
 * FUNCTION (G)
 * ==> put string into file decriptor provided
 * CALLED FUNCTION
 * ==> ft_puchar_fd(libft.h)
 * PARAMETER (n = 2)
 * ==> 1.char 2.int
 * WORK
 * ==> put string into fd by calling fd_puchar_fd to every character
 * RETURN
 * ==> none
 * REFERENCE
 * ==>
*/
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

int	ft_putstr(const char *s, t_prse *prse)
{
	int n_digit;
	int	len_str;
	int	precision;

	precision = prse->precision;
	n_digit = 0;
	len_str = ft_strlen(s);
	if (len_str > precision)
		len_str = 0;
	else if (len_str <= precision)
		precision = 0;
	if (prse->width > 0 && prse->flag_minus == 0)
	{
		n_digit += write_width(prse->width, precision, 0, len_str);
		n_digit += putstr_out(s, prse->precision);
	}
	else if (prse->width > 0 && prse->flag_minus == 1)
	{
		n_digit += putstr_out(s, prse->precision);
		n_digit += write_width(prse->width, precision, 0, len_str);
	}
	else
		n_digit += putstr_out(s, prse->precision);
	return (n_digit);
}
