/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_putnbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:01:30 by asando            #+#    #+#             */
/*   Updated: 2025/04/17 16:34:30 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "libftprintf.h"
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
void	mod_putnbr_fd(int n, int fd, t_prse *prse)
{
	char	c;

	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (n == INT_MIN)
	{
		prse->num_min = 1;
		write(fd, "2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		prse->num_min = 1;
		n = n * -1;
	}
	if (n / 10 > 0)
		ft_putnbr_fd(n / 10, fd);
	c = (n % 10) + '0';
	write(fd, &c, 1);
	return ;
}
