SRCS = srcs/actions.c srcs/actions_2.c srcs/helpers.c srcs/instructions.c push_swap.c \
srcs/stack_methods.c srcs/utils.c srcs/arg_checker.c srcs/frees.c srcs/sorting.c srcs/stack_info.c \
srcs/cmds.c srcs/quick_sort.c srcs/rotations.c

HEAD = include/push_swap.h 

NAME = push_swap

CC = cc

RM = rm -f

OBJS = ${SRCS:%.c=%.o}

CFLAGS = -Wall -Werror -Wextra

all: ${NAME}

%.o:	%.c
		@echo "Compiling $<..."
		${CC} ${CFLAGS} -Ilibft -Ift_printf -c $? -o $@

${NAME}:	push_swap

push_swap:	push_swap.o
		${MAKE} -s -C libft
		${MAKE} -s -C ft_printf
		${CC} ${CFLAGS} ${SRCS} ./libft/libft.a ./ft_printf/libftprintf.a -o push_swap

libft:
		make -C libft

printf:
		make -C ft_printf

clean:
		make clean -s -C libft
		make clean -s -C ft_printf
		${RM} ${OBJS}

fclean: clean
		${RM} push_swap

re:		fclean all

.PHONY:	all clean fclean re