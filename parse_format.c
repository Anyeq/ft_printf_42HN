/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:58:26 by asando            #+#    #+#             */
/*   Updated: 2025/04/11 19:21:56 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//%[argument$][flags][width][.precision][length modifier]conversion

static int	conver_spcf(unsigned char c){}
static int	count_precision(unsigned char c){}
static int	count_width(unsigned char c){}
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

	i = 0;
	if (ft_isalnum(c[i]) || c[i] == '0')
	{
		prse->flag_dot = 1;
		//(-,0,.)
		//(#, ,+)
		i++;
	}
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
		i += set_flags(fmt_str[i], &prse_rslt);
		parse->width = count_width()
		i++;
	}
	return (i);
}
