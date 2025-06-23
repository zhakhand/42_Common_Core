GREEN=\033[32m
YELLOW=\033[33m
RED=\033[31m
BLUE=\033[34m
BACK=\033[42m
BOLD=\033[1m
RESET=\033[0m

SRCS = main.cpp Contact.cpp Phonebook.cpp 

NAME = phonebook

CXX = c++

RM = rm -f

OBJS = ${SRCS:.cpp=.o}

CXXFLAGS = -Wall -Werror -Wextra -std=c++98

all: ${NAME}

%.o:	%.cpp
		@echo "${BLUE}${BOLD}Compiling $<${RESET}"
		@${CXX} ${CXXFLAGS} -c $< -o $@

${NAME}: $(OBJS)
		@${CXX} ${CXXFLAGS} ${OBJS} -o $@
		@echo "${BACK}${RED}${BOLD} Successfuly built ${NAME} ${RESET}"

clean:
		@echo "${YELLOW}${BOLD}Deleting object files${RESET}" 
		@${RM} ${OBJS}

fclean: clean
		@echo "${RED}${BOLD}Deleting executable${RESET}"
		@${RM} phonebook

re:		fclean all

.PHONY:	all clean fclean re