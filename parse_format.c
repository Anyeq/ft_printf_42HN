/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:58:26 by asando            #+#    #+#             */
/*   Updated: 2025/03/25 09:00:26 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//%[argument$][flags][width][.precision][length modifier]conversion

static int	conver_spcf(unsigned char c){}
static int	count_precision(unsigned char c){}
static int	count_width(unsigned char c){}
static size_t	find_flags(unsigned char c)
{
	int	i;

	i = 0;
	while (ft_isalnum(c[i]) || c[i] == '0')
	{
		//(-,0,.)
		//(#, ,+)
		i++;
	}
}
int	parse_format(const char *fmt_str, t_prse parse)
{
	int	i;

	i = 0;
	while (fmt_str[i] != '\0' && !ft_isalpha(fmt_str[i]))
	{
		parse->flags = find_flags(fmt_str[i]);
		parse->width = count_width()
		i++;
	}
	return (i);
}
