/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 20:01:31 by asando            #+#    #+#             */
/*   Updated: 2025/04/23 10:58:28 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <stdarg.h>
#include <limits.h>

typedef struct	s_prse
{
	int	width;
	int	precision;
	int	flag_zero;
	int	flag_dot;
	int	flag_minus;
	int	flag_plus;
	int	flag_hashtag;
	int	flag_space;
	int	num_min;
}	t_prse;
t_prse	*parse_format(const char *fmt_str, int *iter);
int	ft_putchar(unsigned int s, t_prse *prse);
int	ft_putstr(const char *s, t_prse *prse);
int	ft_putptr(void *n, t_prse *prse);
int	ft_putint(int n, t_prse *prse);
int	ft_putunint(unsigned int n);
int	ft_putnum_base(unsigned int n, int nbase, const char *base);
int	write_width(int width, int precision, int f_zero, int nstr);
int	write_precision(int precision, int nstr);
int	write_arg(unsigned char s, va_list arg, t_prse *prse);
int	write_sign(int flag_plus, int num, char *sign);
int	ft_printf(const char *fmt, ...);
