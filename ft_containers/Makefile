NAME = containersTester

CC = c++

INC = -I inc

CPPFLAGS = -Wall -Wextra -Werror -std=c++98 #-fsanitize=leak

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

STD_OBJS_DIR = std_objs

STD_OBJ =  $(SRC:tests/%.cpp=std_objs/%.o)


FT_OBJS_DIR = ft_objs

FT_OBJ = $(SRC:tests/%.cpp=ft_objs/%.o)

DEL = rm -rf

YELLOW='\033[33m'
NONE='\033[0m'
GREEN='\033[32m'
GRAY='\033[2;37m'
STYLE='\033[3m'


all: compile_ft compile_std

compile_std : $(STD_OBJ)
	@echo $(STYLE)$(YELLOW) ">> Compiling std_$(NAME) <<"$(GRAY)
	$(CC) $(CPPFLAGS) $(STD_OBJ) -o std_$(NAME)
	@echo $(NONE)$(STYLE)$(GREEN) "<< std_ $(NAME) compiled >>" $(NONE)


compile_ft : $(FT_OBJ)
	@echo $(STYLE)$(YELLOW) ">> Compiling ft_$(NAME) <<"$(GRAY)
	$(CC) $(CPPFLAGS) $(FT_OBJ) -o ft_$(NAME)
	@echo $(NONE)$(STYLE)$(GREEN) "<< ft_$(NAME) compiled >>" $(NONE)

$(FT_OBJS_DIR)/%.o:tests/%.cpp
	@mkdir -pv $(FT_OBJS_DIR)
	$(CC)	$(CPPFLAGS) -D FT=42 $(INC) -c $< -o $@
	
$(STD_OBJS_DIR)/%.o:tests/%.cpp
	@mkdir -pv $(STD_OBJS_DIR)
	$(CC)	$(CPPFLAGS) $(INC) -c $< -o $@

clean:
	@echo $(STYLE)$(YELLOW) ">> Deleting files <<"$(NONE)
	$(DEL) $(STD_OBJS_DIR) $(FT_OBJS_DIR)
	@echo $(STYLE)$(GREEN) "<< Files deleted >>"$(NONE)

fclean: clean
	$(DEL) ft_$(NAME) std_$(NAME)

re:
	@echo $(STYLE)$(YELLOW) ">> Recompiling ft_$(NAME) <<" $(NONE)
	@echo $(STYLE)$(YELLOW) ">> Recompiling std_$(NAME) <<" $(NONE)
	@make fclean all

.PHONY : all re compile_std compile_ft clean fclean
