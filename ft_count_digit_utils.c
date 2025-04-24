/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digit_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:09:20 by asando            #+#    #+#             */
/*   Updated: 2025/04/23 23:02:49 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	count_digit_ptr(uintptr_t n)
{
	int	n_digit;

	n_digit = 0;
	while (n > 0)
	{
		n = n / 16;
		n_digit++;
	}
	return (n_digit);
}

int	count_digit_int(int n)
{
	int	n_digit;

	n_digit = 0;
	if (n == INT_MIN)
		return (10);
	else if (n == 0)
		return (1);
	if (n < 0)
		n = n * -1;
	while (n > 0)
	{
		n = n / 10;
		n_digit++;
	}
	return (n_digit);
}

int	count_digit_uint(unsigned int n)
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

int	count_digit_nbase(unsigned int n, int nbase)
{
	int	n_digit;

	n_digit = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / nbase;
		n_digit++;
	}
	return (n_digit);
}
