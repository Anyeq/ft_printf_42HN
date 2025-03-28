/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:22:55 by asando            #+#    #+#             */
/*   Updated: 2025/03/24 20:17:45 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_printf(const char *format, ...)
{
	int	i;
	size_t	n_char;
	va_list	arg_list;

	i = 0;
	n_char = 0;
	va_start(arg_list, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			//function to parse what is the FS and formatting
		}
		i++;
	}
	va_end(arg_list);
	return (n_char);
}
