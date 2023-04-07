# ANSI color codes for output formatting
RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[0;33m
BLUE=\033[0;34m
MAGENTA=\033[0;35m
CYAN=\033[0;36m
RESET=\033[0m

NAME	=	cub3d

CC		=	@gcc
CFLAGS	=	-g3 -Wall -Wextra -Werror #-fsanitize=address

RM		=	@rm -f
ECHO	=	@echo

MAKELIB	=	@make -C libft
LIBFT	=	libft/libft.a
CLNLIB	=	@make clean -C libft
FCLNLIB	=	@make fclean -C libft

SRCS	= 	main.c \
			parsing/parse_map.c\
			parsing/parse_ext.c \
			parsing/parse_utils.c \
			parsing/parse_colors.c \
			parsing/parse_mapfile.c \
			# parsing/parse_validate.c \
			parsing/parse_initializer.c \
			# raycasting/utils.c \
			# raycasting/key_handles.c \
			# raycasting/line_drawing.c \
			# raycasting/drawing_utils.c \
			# raycasting/raycasting.c \
			


OBJS	=	$(SRCS:.c=.o)

$(NAME):	$(OBJS)
			$(MAKELIB)
			$(ECHO) "Compiling minishell ......"
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(LRLFLAG) 

all:		$(NAME)

clean:
			$(CLNLIB)
			$(RM) $(OBJS)

fclean:		
			$(FCLNLIB)
			$(ECHO) "Removing minishell ......."
			$(RM) $(NAME) $(OBJS)

re:			fclean all clean

exec: fclean all
		./cub map.cub

.PHONY: all clean fclean re


