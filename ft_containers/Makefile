NAME = containers
FT_NAME = ft_container
STD_NAME = std_container

INC_DIR     = inc
FLAGS_INC   = -I $(INC_DIR)

CC = c++
CFLAGS = -Wall -Wextra -Werror $(FLAGS_INC) -std=c++98
DEL = rm -rf

YELLOW='\033[33m'
NONE='\033[0m'
GREEN='\033[32m'
GRAY='\033[2;37m'
STYLE='\033[3m'

SRC =	tests/VectorConstruction.cpp \
		tests/VecIterators.cpp \
		tests/VecMemberFunctions.cpp \
		tests/VecRelationalOperators.cpp \
		tests/VecSpeed.cpp \
		tests/MapConstruction.cpp \
		tests/MapMemberFunctions.cpp \
		tests/MapRelationalOperators.cpp \
		tests/MapIterators.cpp \
		tests/MapSpeed.cpp \
		tests/StackConstruction.cpp \
		tests/StackMemberFunctions.cpp \
		tests/StackRelationalOperators.cpp \
		tests/main.cpp \

STD_OBJS = $(SRC:cpp=std.o)
FT_OBJS = $(SRC:cpp=ft.o)

all: $(STD_NAME) $(FT_NAME)

$(NAME) : all

$(STD_NAME): $(STD_OBJS)
	@echo $(STYLE)$(YELLOW) ">> Compiling $(STD_NAME) <<"$(GRAY)
	$(CC) $(CFLAGS) -o $(STD_NAME) $(STD_OBJS)
	@echo $(NONE)$(STYLE)$(GREEN) "<< $(STD_NAME) compiled >>" $(NONE)

$(FT_NAME): $(FT_OBJS)
	@echo $(STYLE)$(YELLOW) ">> Compiling $(FT_NAME) <<"$(GRAY)
	$(CC) $(CFLAGS) -o $(FT_NAME) $(FT_OBJS)
	@echo $(NONE)$(STYLE)$(GREEN) "<< $(FT_NAME) compiled >>" $(NONE)

%.std.o: %.cpp
	${CC} ${CFLAGS} $(FLAGS_INC) -c $< -o $@

%.ft.o: %.cpp
	${CC} ${CFLAGS} $(FLAGS_INC) -D FT=42 -c $< -o $@

clean:
	@echo $(STYLE)$(YELLOW) ">> Deleting objects <<"$(GRAY)
	$(DEL) $(STD_OBJS) $(FT_OBJS)
	@echo $(NONE)$(STYLE)$(GREEN) "<< Objects deleted >>"$(NONE)

fclean: clean
	@$(DEL) $(STD_NAME) $(FT_NAME)

re: fclean all

compile_std: fclean $(STD_OBJS) $(STD_NAME)
compile_ft: fclean $(FT_OBJS) $(FT_NAME)
