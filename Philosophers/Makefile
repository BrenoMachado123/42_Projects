# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmachado <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/17 15:15:37 by bmachado          #+#    #+#              #
#    Updated: 2021/09/09 16:11:45 by bmachado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LEAK = -fsanitize=address

NAME = philo

SRC = 	./routine.c			\
		./errors.c			\
		./init_structs.c	\
		./msg.c				\
		./utils.c			\
		./utils2.c			\
		./philo.c			\
		./death.c			\

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror $(SRC) $(LEAK) -o $(NAME)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
