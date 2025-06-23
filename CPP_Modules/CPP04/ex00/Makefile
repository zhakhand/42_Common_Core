GREEN=\033[32m
YELLOW=\033[33m
RED=\033[31m
BLUE=\033[34m
BACK=\033[42m
BOLD=\033[1m
RESET=\033[0m

SRCS = Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp main.cpp

NAME = main

CPP = c++

RM = rm -f

OBJS = ${SRCS:.cpp=.o}

HEADERS = Animal.hpp Cat.hpp Dog.hpp WrongAnimal.hpp WrongCat.hpp

CPPFLAGS = -Wall -Werror -Wextra -std=c++98

all: ${NAME}

%.o:	%.cpp ${HEADERS}
		@echo "${BLUE}${BOLD}Compiling $<${RESET}"
		@${CPP} ${CPPFLAGS} -c $< -o $@

${NAME}: $(OBJS)
		@${CPP} ${CPPFLAGS} ${OBJS} -o $@
		@echo "${BACK}${RED}${BOLD} Successfuly built ${NAME} ${RESET}"

clean:
		@echo "${YELLOW}${BOLD}Deleting object files${RESET}" 
		@${RM} ${OBJS}

fclean: clean
		@echo "${RED}${BOLD}Deleting executable${RESET}"
		@${RM}	${NAME}

re:		fclean all

.PHONY:	all clean fclean re