/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:01:30 by asando            #+#    #+#             */
/*   Updated: 2025/04/18 09:04:00 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <limits.h>
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
static int	count_digit(unsigned int n)
{
	int	n_digit;

	n_digit = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		n_digit++;
	}
	return (n_digit);
}

static void	putunint_out(unsigned int n)
{
	char	c;

	if (n == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (n / 10 > 0)
		putunint_out(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
	return ;
}

int	ft_putunint(unsigned int n)
{
	int	n_digit;

	n_digit = count_digit(n);
	putunint_out(n);
	return (n_digit);
}
