/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnum_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:01:30 by asando            #+#    #+#             */
/*   Updated: 2025/04/23 12:14:22 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf.h"
//#include "libft.h"
//#include "libftprintf.h"
/*
 * FUNCTION (G)
 * ==> put number into fd provided
 * CALLED FUNCTION
 * ==> write(unistd.h)
 * PARAMETER (n = 2)
 * ==> 1.int 2.int
 * WORK
 * ==> devide by ten to get every digit and write it to fd
 * ==> if number consist a sign multiplyit to -1 to get positif number
 * ==> write sign separately
 * ==> if number == INT_MIN from limits.h write it on fd right away
 * RETURN
 * ==> none
 * REFERENCE
 * ==>
*/
static void	putnumbase_out(unsigned int n, int nbase, const char *base)
{
	if (n == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (n / nbase > 0)
		putnumbase_out(n / nbase, nbase, base);
	write(1, &base[n % nbase], 1);
	return ;
}

int	ft_putnum_base(unsigned int n, int nbase, const char *base)
{
	int	n_digit;

	n_digit = count_digit_nbase(n, nbase);
	putnumbase_out(n, nbase, base);
	return (n_digit);
}
