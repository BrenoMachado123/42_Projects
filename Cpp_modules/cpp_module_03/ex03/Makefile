# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmachado <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/17 15:15:37 by bmachado          #+#    #+#              #
#    Updated: 2022/03/18 16:46:10 by bmachado         ###   ########.fr        #
#    Updated: 2021/10/11 17:25:10 by bmachado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

YELLOW='\033[33m'
NONE='\033[0m'
GREEN='\033[32m'
GRAY='\033[2;37m'
STYLE='\033[3m'

NAME = DiamondTrap

SRC = $(wildcard *.cpp)	

OBJS = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME):
	@echo $(STYLE)$(YELLOW) ">> Compiling $(NAME) <<"$(GRAY)
	g++ $(CFLAGS) $(SRC) -o $(NAME)
	g++ $(CPPFLAGS) -c $(SRC)
	@echo $(NONE)$(STYLE)$(GREEN) "<< $(NAME) compiled >>" $(NONE)

clean:
	@echo $(STYLE)$(YELLOW) ">> Deleting files <<"$(NONE)
	@/bin/rm -f $(OBJS)
	@echo $(STYLE)$(GREEN) "<< Files deleted >>"$(NONE)

fclean: clean
	@/bin/rm -f $(NAME)

re:
	@echo $(STYLE)$(YELLOW) ">> Recompiling $(NAME) <<" $(NONE)
	@make fclean all
