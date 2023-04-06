# ANSI color codes for output formatting
RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[0;33m
BLUE=\033[0;34m
MAGENTA=\033[0;35m
CYAN=\033[0;36m
RESET=\033[0m

SRCS	= 	main.c \
			parsing/parse_map.c\
			parsing/parse_ext.c \
			parsing/parse_utils.c \
			parsing/parse_colors.c \
			parsing/parse_mapfile.c \
			parsing/parse_validate.c \
			parsing/parse_initializer.c \
			parsing/libft_utils/ft_split.c \
			parsing/libft_utils/gnl.c \
			parsing/libft_utils/utils1.c \
			parsing/libft_utils/utils2.c \
			raycasting/utils.c \
			raycasting/key_handles.c \
			raycasting/line_drawing.c \
			raycasting/drawing_utils.c \
			raycasting/raycasting.c \
			


OBJS	= $(SRCS:.c=.o)
FLAGS	= -crs
mlx		= ./mlx/libmlx.a
#LIBFT	= cd libft && make
#LIB		= libft/libft.a
CC		= gcc -g3
RM		= rm -rf
CFLAGS	= -Wall -Wextra -Werror -Ofast -march=native
NAME	= cub

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(CYAN)Compiling $(NAME)...\n$(RESET)"
	@make -C ./mlx
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(mlx) -framework OpenGL -framework AppKit
	@echo "$(GREEN)Compilation completed.$(RESET)"

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<
	@echo "$(MAGENTA)Compiled $< into $@.$(RESET)"

clean:
	@$(RM) $(OBJS)
	@make clean -C ./mlx && rm -rf *.dSYM
	@echo "$(YELLOW)Removed object files.$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@make clean -C ./mlx && rm -rf *.dSYM
	@echo "$(YELLOW)Removed executable.$(RESET)"

re: fclean all
		make clean

exec: fclean all
		./cub map.cub

.PHONY: all clean fclean re


