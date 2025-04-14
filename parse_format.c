/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:58:26 by asando            #+#    #+#             */
/*   Updated: 2025/04/14 16:22:58 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//%[argument$][flags][width][.precision][length modifier]conversion

static int	conver_spcf(unsigned char c){}
static int	count_width_precision(const char *fmt_str, t_prse **prse)
{
	int	i;

	i = 0;
	if (fmt_str[i] == '.' && ft_isdigit(fmt_str[i]))
	{
		prse->flag_dot = 1;
		i++;
		while (ft_isdigit(fmt_str[i]))
		{
			prse->precision = 10 * prse->precision + (fmt_str[i] - '0');
			i++;
		}
		return (i);
	}
	while (ft_isdigit(fmt_str[i]))
	{
		prse->width = 10 * prse->width + (fmt_str - '0');
		i++;
	}
	return (i);
}
// 0 default or unused 1 used -1 overwrite
static t_prse	*prse_init(t_prse **prse)
{
	prse->width = 0;
	prse->precision = 0;
	prse->flag_zero = 0;
	prse->flag_dot = 0;
	prse->flag_minus = 0;
	prse->flag_space = 0;
	prse->flag_plus = 0;
	prse->flag_hashtag = 0;
}

static int set_flags(unsigned char c, t_prse **prse)
{
	int	i;

	i = 1;
	if (c[i] == '0')
		prse->flag_zero = 1;
	if (c[i] == '-')
		prse->flag_minus = 1;
	if (c[i] == '#')
		prse->flag_hashtag = 1;
	if (c[i] == ' ')
		prse->flag_space = 1;
	if (c[i] == '+')
		prse->flag_plus = 1;
	if (c[i] == '.')
		prse->flag_dot = 1;
}
//check what to return 
int	parse_format(const char *fmt_str)
{
	int	i;
	t_prse	*prse_rslt;

	prse_rslt = malloc(sizeof(t_prse));
	if (!prse_rslt)
		return (1);
	prse_init(&prse_rslt);
	i = 0;
	while (fmt_str[i] != '\0' && !ft_isalpha(fmt_str[i]))
	{
		// if there is format checking consider to remove second condition
		if ((!ft_isalnum(fmt_str[i]) && prse_rslt->width == 0 && fmt_str[i] != '.')
			i += set_flags(fmt_str[i], &prse_rslt);
		if (fmt_str[i] == '.' && ft_isdigit(fmt_str[i]))
			i += count_width_precision(&fmt_str[i], &prse_rslt);
		i++;
	}
	return (i);
}
