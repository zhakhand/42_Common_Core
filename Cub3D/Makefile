GREEN=\033[32m
YELLOW=\033[33m
RED=\033[31m
BLUE=\033[34m
BACK=\033[42m
BOLD=\033[1m
RESET=\033[0m

HEAD = include

NAME = cub3d

CC = cc

RM = rm -rf

OBJSDIR = objs

OBJS = $(addprefix ${OBJSDIR}/, ${SRCS:.c=.o})

DEPS = $(addprefix ${OBJSDIR}/, ${SRCS:.c=.d})

MAKEFLAGS = -j$(nproc) --no-print-directory

CFLAGS = -Wall -Werror -Wextra -g

DFLAGS = -MD -MP

IFLAGS = -I ${HEAD}

SRCS = cub3d.c \
		init/check_vars.c \
		init/load_map.c \
		init/check_map.c \
		init/init_player.c \
		init/init_mlx.c \
		init/init_textures.c \
		init/load_map_utils.c \
		init/load_map_utils_2.c \
		init/load_map_checks.c \
		init/set_textures.c \
		free/free_map.c free/close.c \
		init/init_game.c \
		movement/key_events.c movement/move_player.c movement/moving.c \
		raycasting/raycasting.c raycasting/raycasting_utils.c \
		raycasting/drawing_utils.c raycasting/draw_player.c \
		raycasting/draw_hand.c \
		utils/utils.c \
		utils/get_next_line/get_next_line.c \
		utils/get_next_line/get_next_line_utils.c

#		init/process_map.c

LIBDIR = ./libft

LIBFT = ${LIBDIR}/libft.a

all: ${NAME}

#-Lminilibx-linux -lmlx_Linux -lX11 -lXext -lm
#-lmlx -lX11 -lXext -lm
${NAME}: $(OBJS)
		@${MAKE} -s -C ${LIBDIR} all
		@${CC} ${CFLAGS} ${DFLAGS} ${IFLAGS} -o $@ $^ ${LIBFT} -lmlx -lX11 -lXext -lm
		@echo "${BACK}${RED}${BOLD} Successfuly built ${NAME} ${RESET}"

${OBJSDIR}/%.o:	%.c
		@mkdir -p $(dir $@)
		@echo "${BLUE}${BOLD}Compiling $<${RESET}"
		@${CC} ${CFLAGS} ${DFLAGS} ${IFLAGS} -c $< -o $@ 

clean:
		@echo "${YELLOW}${BOLD}Deleting object files${RESET}"
		@${MAKE} -s -C ${LIBDIR} clean
		@${RM} ${OBJSDIR}

fclean: clean
		@echo "${RED}${BOLD}Deleting executable${RESET}"
		@${MAKE} -s -C ${LIBDIR} fclean
		@${RM} ${NAME}

re:		fclean
		${MAKE} all

.PHONY:	all clean fclean re

-include ${DEPS}