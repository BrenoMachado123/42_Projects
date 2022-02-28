# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmachado <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/17 15:15:37 by bmachado          #+#    #+#              #
#    Updated: 2021/06/30 13:46:38 by bmachado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

FLAGS = -Wall -Werror -Wextra

LIB = ./libft/libft.a

CHECK = -fsanitize=address

SRC =	./rotate.c		\
		./utils.c		\
		./swap.c		\
		./Sorting.c		\
		./r_rotate.c	\
		./Push_swap.c	\
		./create_list.c	\
		./push.c		\
		./fix.c			\
		./Algo_utils.c	\
		./more_utils.c	\

OBJS = $(SRC:.c=.o)

HDRS = push_swap.h

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	gcc $(FLAGS) $(LIB) $(OBJS) -o $(NAME)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)
	$(MAKE) clean -C ./libft

re: fclean all
