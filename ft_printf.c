/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:22:55 by asando            #+#    #+#             */
/*   Updated: 2025/05/20 07:41:43 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	printf_out(const char *fmt, int *i, ssize_t err)
{
	if (write(1, &fmt[*i], 1) < 1)
		return (-1);
	*i += 1;
	return (1);
}

static int	check_format(const char *format)
{
	int	i;
	int	sign_exist;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			sign_exist = 1;
			i++;
			while (!ft_isalpha(format[i]) && format[i] != '%')
			{
				if (format[i] == '\0' && sign_exist == 1)
					return (-1);
				i++;
			}
			if (format[i] == '%' || ft_isalpha(format[i]))
				sign_exist = 0;
		}
		i++;
	}
	return (0);
}

static int	print_arg(const char *fmt, t_prse *prse, va_list args, int *iter)
{
	int	i;
	int	n_char;

	n_char = 0;
	i = 1;
	i += parse_format(&fmt[i], prse);
	if (ft_isalpha(fmt[i]) || fmt[i] == '%')
		n_char = write_arg(fmt[i], args, prse, &i);
	*iter += i;
	return (n_char);
}

static int	eol_case(const char s, t_prse *prse)
{	if (s == '\0')
	{
		free(prse);
		return (1);
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		n_char;
	va_list	arg_list;
	t_prse	*prse_rslt;

	i = 0;
	n_char = check_format(format);
	prse_rslt = malloc(sizeof(t_prse));
	if (!prse_rslt)
		return (-1);
	va_start(arg_list, format);
	while (format[i] != '\0' && n_char >= 0)
	{
		while (format[i] == '%')
		{
			n_char += print_arg(&format[i], prse_rslt, arg_list, &i);
			if (eol_case(format[i], prse_rslt))
				return (n_char);
		}
		n_char += printf_out(format, &i, &err);
	}
	free(prse_rslt);
	va_end(arg_list);
	return (n_char);
}
