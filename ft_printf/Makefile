# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fionni <fionni@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/01 20:19:50 by fionni            #+#    #+#              #
#    Updated: 2025/03/01 21:27:43 by fionni           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS = ft_printchar.c \
		ft_printf.c \
		ft_printhexalower.c \
		ft_printhexaupper.c \
		ft_printinteger.c \
		ft_printpercent.c \
		ft_printptr.c \
		ft_printstring.c \
		ft_printunsignedint.c \
		ft_printf_utils.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
