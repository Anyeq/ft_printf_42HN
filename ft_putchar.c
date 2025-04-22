/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 13:50:53 by asando            #+#    #+#             */
/*   Updated: 2025/04/22 12:12:37 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf.h"
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
int	ft_putchar(unsigned int s, t_prse *prse)
{
	int	n_digit;

	n_digit = 0;
	if (prse->width > 0 && prse->flag_minus == 0)
	{
		n_digit += write_width(prse->width, prse->precision, 0, 1);
		write(STDOUT_FILENO, &s, 1);
		return (n_digit);
	}
	else if (prse->width > 0 && prse->flag_minus == 1)
	{
		write(STDOUT_FILENO, &s, 1);
		n_digit += write_width(prse->width, prse->precision, 0, 1);
		return (n_digit);
	}
	write(STDOUT_FILENO, &s, 1);
	return (n_digit + 1);
}
