##
## EPITECH PROJECT, 2018
## minishell1
## File description:
## compilation
##

## Colors
RED		= 	\033[31m
GREEN 	=	\033[32m
BLUE	=	\033[34m
RESET	=	\033[0m

NAME 	=	gameoflife

SRC 	=	$(wildcard src/*.c)

OBJ		=	$(SRC:.c=.o)

COMP 	=	gcc

RM 		=	rm -f -r

CFLAGS	+=	-Wall -Wextra -I./include

CFLAGS 	+= -lncurses

SFLAGS	+=	-lcsfml-system -lcsfml-graphics -lcsfml-window -lcsfml-audio

MFLAGS 	+= 	-lm

all:    	$(NAME)
			@echo "$(RED)/------------------\ $(RESET)"
			@echo "$(RED)| $(GREEN)COMPILATION DONE $(RED)|$(RESET)"
			@echo "$(RED)\------------------/$(RESET)"

debug:		CFLAGS += -g
debug:		re

$(NAME):    $(OBJ)
			$(COMP) -o $(NAME) $(OBJ) $(CFLAGS)
			rm -f $(OBJ)

clean:
			@$(RM) *~
			@$(RM) *.o
			@$(RM) vgcore.*
			@echo "$(RED)## $(GREEN)Les fichiers ~ et .o ont été supprimé $(RED)##$(RESET)"

fclean: 	clean
			@$(RM) $(NAME)
			@echo "$(RED)## $(GREEN)      Le binaire a été supprimé $(RED)      ##$(RESET)"

re: 		fclean all

.PHONY:		all debug clean fclean re