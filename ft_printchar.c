/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 12:36:47 by asando            #+#    #+#             */
/*   Updated: 2025/06/10 12:42:13 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(unsigned int chr, t_prse *prse)
{
	if (write(STDOUT_FILENO, &chr, 1) < 1)
	{
		prse->write_err = 1;
		return (0);
	}
	return (1);
}
