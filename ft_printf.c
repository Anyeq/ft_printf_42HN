/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:22:55 by asando            #+#    #+#             */
/*   Updated: 2025/04/17 10:13:22 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_printf(const char *format, ...)
{
	int	i;
	size_t	n_char;
	va_list	arg_list;
	t_prse	*prse_rslt;

	i = 0;
	n_char = 0;
	va_start(arg_list, format);
	while (format[i] != '\0')
	{
		// be carefull on the case of %%
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '%')
				//then print %
			else
			{
				//this could be a proble refereing to i
				prse_rslt = parse_format(&format[i], &i);
				//CALL FORMATING FUNCTION
				fmt_specifier(format[i], arg_list);
				//CALL SPECIFIER THING
				free(prse_rslt);
			}
		}
		write(1, format[i], 1);
		i++;
	}
	va_end(arg_list);
	return (n_char);
}
