/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:22:55 by asando            #+#    #+#             */
/*   Updated: 2025/04/23 16:38:52 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf.h"

static void	printf_out(const char *fmt, int *i, int *nchar)
{
	write(1, &fmt[*i], 1);
	*i += 1;
	*nchar += 1;
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		n_char;
	va_list	arg_list;
	t_prse	*prse_rslt;

	i = 0;
	n_char = 0;
	va_start(arg_list, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] != '%')
			{
				prse_rslt = parse_format(&format[i], &i);
				n_char += write_arg(format[i], arg_list, prse_rslt);
				free(prse_rslt);
				i++;
			}
		}
		printf_out(format, &i, &n_char);
	}
	va_end(arg_list);
	return (n_char);
}
