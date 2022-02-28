# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmachado <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/17 15:15:37 by bmachado          #+#    #+#              #
#    Updated: 2021/05/05 15:55:52 by bmachado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = 	./flagcheck.c 				\
		./ft_conversions.c	 		\
		./ft_unsigned_utils.c 		\
		./ft_deal_unsigned.c 		\
		./ft_printf.c 				\
		./ft_utilsone.c 			\
		./ft_utilstwo.c				\
		./ft_utilsthree.c			\
		./ft_itoa.c					\
		./ft_u_itoa.c				\
		./ft_flags.c				\
		./ft_dot_situations.c		\
		./dot_int_utils.c			\
		./ft_dot_hexa_utils.c		\
		./ft_treat_unsigned_dot.c	\
		./ft_percent.c				\

OBJS = $(SRC:.c=.o)

HDRS = ft_printf.h

all: $(NAME)

$(NAME):
	gcc -c -Wall -Wextra -Werror -I $(HDRS) $(SRC) 
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
