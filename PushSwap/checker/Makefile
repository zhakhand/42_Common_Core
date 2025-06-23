SRCS = srcs/actions.c srcs/actions_2.c srcs/helpers.c srcs/instructions.c \
srcs/push_swap.c srcs/stack_methods.c srcs/utils.c srcs/arg_checker.c srcs/frees.c\
  srcs/sorting.c srcs/stack_info.c srcs/cmds.c srcs/quick_sort.c srcs/rotations.c\
   checker.c gnl/get_next_line.c gnl/get_next_line_utils.c

HEAD = push_swap.h 

BONUS = checker

CC = cc

RM = rm -f

OBJS = ${SRCS:%.c=%.o}

CFLAGS = -Wall -Werror -Wextra

all: ${BONUS}

%.o:	%.c
		@echo "Compiling $<..."
		${CC} ${CFLAGS} -Ilibft -Ift_printf -c $? -o $@

${BONUS}:	checker

checker:	checker.o
		${MAKE} -s -C libft
		${MAKE} -s -C ft_printf
		${CC} ${CFLAGS} ${SRCS} -g ./libft/libft.a ./ft_printf/libftprintf.a -o checker

libft:
		make -C libft

printf:
		make -C ft_printf

clean:
		make clean -s -C libft
		make clean -s -C ft_printf
		${RM} ${OBJS}

fclean: clean
		${RM} checker

re:		fclean all

.PHONY:	all clean fclean re