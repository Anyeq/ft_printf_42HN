/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 20:01:31 by asando            #+#    #+#             */
/*   Updated: 2025/04/24 09:40:51 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include "./libft/libft.h"

typedef struct s_prse
{
	int	width;
	int	precision;
	int	flag_zero;
	int	flag_dot;
	int	flag_minus;
	int	flag_plus;
	int	flag_hashtag;
	int	flag_space;
	int	no_spec;
}	t_prse;
int		parse_format(const char *fmt_str, t_prse *prse_rslt);
int		ft_putchar(unsigned int s, t_prse *prse);
int		ft_putstr(const char *s, t_prse *prse);
int		ft_putptr(void *n, t_prse *prse);
int		ft_putint(int n, t_prse *prse);
int		ft_putunint(unsigned int n, t_prse *prse);
int		ft_putnum_base(unsigned int n, int nbase, const char *base,
			t_prse *prse);
int		write_width(int width, int precision, int f_zero, int nstr);
int		write_precision(int precision, int nstr);
int		write_arg(unsigned char s, va_list arg, t_prse *prse, int *i);
int		write_sign(int flag_plus, int num, char *sign);
int		count_digit_ptr(uintptr_t n);
int		count_digit_int(int n);
int		count_digit_uint(unsigned int n);
int		count_digit_nbase(unsigned int n, int nbase);
int		ft_printf(const char *fmt, ...);

#endif
