SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c\
 ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
 ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
 ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
 ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_free.c #get_next_line.c get_next_line_utils.c

BONUS_SRCS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c 

OBJ = $(SRCS:.c=.o)

BONUS_OBJ = $(BONUS_SRCS:.c=.o)

HEAD = ./libft.h

NAME = libft.a

AR = ar rcs

RM = rm -f

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

.c.o:  $(HEAD)	
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJ)
		 $(AR) $(NAME) $(OBJ)

bonus: $(BONUS_OBJ) $(OBJ)
	$(AR) $(NAME) $^

clean: 
		$(RM) $(OBJ) $(BONUS_OBJ)

fclean:	clean
		$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re bonus
