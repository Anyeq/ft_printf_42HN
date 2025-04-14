/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 20:01:31 by asando            #+#    #+#             */
/*   Updated: 2025/04/14 16:20:01 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
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
}	t_prse;
