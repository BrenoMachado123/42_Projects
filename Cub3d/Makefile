# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmachado <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/17 15:15:37 by bmachado          #+#    #+#              #
#    Updated: 2021/10/27 13:40:05 by bmachado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MLX = -lmlx -lm -framework OpenGL -framework AppKit

LEAK = -fsanitize=address

NAME = cub3D

SRC = 	./cub3d.c					\
		./Parsing/ft_open.c			\
		./Parsing/ft_path.c			\
		./Maping/handle_map.c		\
		./Maping/raycasting.c		\
		./Maping/raycasting2.c		\
		./Maping/texture.c			\
		./utils.c					\
		./utils2.c					\
		./cubdata.c   				\
		./Data.c					\
		./free.c					\
		./Player/Movement.c			\
		./Player/player.c			\
		./cub_errors.c				\
		./Parsing/map_issue.c		\

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	$(MAKE) -C ./libft
	gcc -O3 -Wall -Wextra -Werror ./libft/libft.a $(MLX) $(SRC) $(LEAK) -o $(NAME)

clean:
	/bin/rm -f $(OBJS)
	$(MAKE) clean -C ./libft

fclean: clean
	/bin/rm -f $(NAME)
	$(MAKE) clean -C ./libft

re: fclean all
