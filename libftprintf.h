/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 20:01:31 by asando            #+#    #+#             */
/*   Updated: 2025/04/21 14:44:01 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <stdarg.h>
typedef struct	s_prse
{
	size_t	width;
	size_t	precision;
	int		flag_zero;
	int		flag_dot;
	int		flag_minus;
	int		flag_plus;
	int		flag_hashtag;
	int		flag_space;
	int		num_min;
}	t_prse;
t_prse	*parse_format(const char *fmt_str, int *iter);
int	ft_putint(int n);
int	ft_putunint(unsigned int n);
int	ft_putnum_base(unsigned int n, int nbase, const char *base);
int	ft_putptr(void *n);
int	ft_putstr(const char *s, int precision);
int	ft_putchar(unsigned int s);
int	write_conversion(unsigned char s, va_list arg, t_prse *prse);
int	ft_printf(const char *fmt, ...);
