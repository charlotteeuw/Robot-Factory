##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile for robot factory project
##

INCLUDE		=		-I./include/

SRC			=		$(shell find ./src/ ./my/lib/ -name "*.c")

NAME 		=		asm

TEST		=		$(shell find ./tests/ -name "*.c")

UNIT 		=		unit_tests

$(NAME) :
	gcc -g -Wall -Wextra -o $(NAME) $(SRC) $(INCLUDE)

$(UNIT) :
	gcc -o $(UNIT) $(INCLUDE) $(SRC) $(TEST) --coverage -lcriterion

all : $(NAME)

clean :
	rm -f vgcore*
	rm -f coding-style-reports.log
	rm -f *.gcno
	rm -f *.gcda

fclean : clean
	rm -f $(NAME)

tests_run : fclean $(UNIT)
		./$(UNIT)

re : fclean all
