/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 13:50:53 by asando            #+#    #+#             */
/*   Updated: 2025/04/20 08:49:07 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
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
void	ft_putstr(char *s, int precision)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && i < precision)
	{
		ft_putchar_fd(s[i], STDOUT_FILENO);
		i++;
	}
	return ;
}
