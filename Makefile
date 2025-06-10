# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asando <asando@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/23 22:07:48 by asando            #+#    #+#              #
#    Updated: 2025/06/10 12:45:33 by asando           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
COMP = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_count_digit_utils.c ft_parse.c ft_printf.c ft_putchar.c ft_putint.c \
	   ft_putnum_base.c ft_putptr.c ft_putstr.c ft_putunint.c \
	   ft_width_precision_utils.c ft_write_arg.c ft_printchar.c

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

LIBFT_DIR = ./libft

LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

bonus: all

$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	ar crs $@ $^

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) all

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus
