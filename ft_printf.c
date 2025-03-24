/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:22:55 by asando            #+#    #+#             */
/*   Updated: 2025/03/24 19:54:36 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//%[argument$][flags][width][.precision][length modifier]conversion
static int	parse_str(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && !ft_isalpha(str[i]))
		i++;
}

int	ft_printf(const char *str, ...)
{
	int	i;
	size_t	n_char;
	va_list	arg_list;

	i = 0;
	n_char = 0;
	va_start(arg_list, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			//function to parse what is the FS and formatting
		}
		i++;
	}
	va_end(arg_list);
	return (n_char);
}
