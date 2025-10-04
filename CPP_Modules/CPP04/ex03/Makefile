GREEN=\033[32m
YELLOW=\033[33m
RED=\033[31m
BLUE=\033[34m
BACK=\033[42m
BOLD=\033[1m
RESET=\033[0m

SRCS = AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp\
	   main.cpp

NAME = main

CPP = c++

RM = rm -f

OBJS = ${SRCS:.cpp=.o}

HEADERS = AMateria.hpp Character.hpp Cure.hpp Ice.hpp MateriaSource.hpp\
		  ICharacter.hpp IMateriaSource.hpp

CPPFLAGS = -Wall -Werror -Wextra -std=c++98 -g

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