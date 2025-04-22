/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 13:50:53 by asando            #+#    #+#             */
/*   Updated: 2025/04/22 09:45:07 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
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
int	ft_putchar(unsigned int s)
{
	write(STDOUT_FILENO, &s, 1);
	return (1);
}
