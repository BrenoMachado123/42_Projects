# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmachado <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/17 15:15:37 by bmachado          #+#    #+#              #
#    Updated: 2021/09/30 18:12:31 by bmachado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MLX = -lmlx -lm -framework OpenGL -framework AppKit

LEAK = -fsanitize=address -g

FLAGS = -Wall -Wextra -Werror

NAME = so_long

YELLOW='\033[33m'
NONE='\033[0m'
GREEN='\033[32m'
BLUE='\033[0;34m'
STYLE='\033[3m'

SRC = ./solong.c		\
	  ./create_map.c	\
	  ./draw.c			\
	  ./game_elements.c	\
	  ./animation.c		\
	  ./errors.c		\
	  ./init_data.c		\
	  ./utils.c			\
	  ./movement.c		\
	  ./enemy_ai.c		\
	  ./enemy_ai2.c		\
	  ./clear_game.c	\

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@make -C ./libft
	@echo $(STYLE)$(YELLOW) " >> Compiling $(NAME) <<" $(NONE)
	@gcc $(FLAGS) ./libft/libft.a $(MLX) $(SRC) -o $(NAME)
	@gcc $(FLAGS) -c $(SRC)
	@echo $(STYLE)$(GREEN) " << $(NAME) compiled >>" $(NONE)

clean:
	@/bin/rm -f $(OBJS) ./libft/libft.a
	@echo $(STYLE)$(YELLOW) " >> Deleting files <<"$(NONE)
	@make clean -C ./libft
	@echo $(STYLE)$(GREEN) " << Files deleted >>"$(NONE)

fclean: clean
	@/bin/rm -f $(NAME)
	@make clean -C ./libft

re:
	@echo $(STYLE)$(YELLOW) " >> Recompiling $(NAME) <<" $(NONE)
	@make fclean all
