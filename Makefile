
# ANSI color codes for output formatting
RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[0;33m
BLUE=\033[0;34m
MAGENTA=\033[0;35m
CYAN=\033[0;36m
RESET=\033[0m

SRCS	= 	main.c \
			parsing/parse_ext.c \
			parsing/parse_colors.c \
			parsing/parse_mapfile.c \
			parsing/parse_validate.c \
			parsing/parse_initializer.c \
			parsing/check_walls.c \
			parsing/print_funcs.c \
			parsing/parse_textures.c \
			parsing/create_rectangle_map.c \
			parsing/parse_utils1.c \
			parsing/parse_utils2.c \
			parsing/parse_utils3.c \
			parsing/parse_utils4.c \
			parsing/parse_utils5.c \
			parsing/parse_utils6.c \
			parsing/parse_map1.c \
			parsing/parse_utils7.c \
			parsing/parse_utils8.c \
			parsing/parse_utils9.c \
			raycasting/utils.c \
			raycasting/bressen_line.c \
			raycasting/drawing_utils.c \
			raycasting/raycasting.c \
			raycasting/map.c \
			raycasting/raycasting_utils.c \
			raycasting/render_walls.c \
			raycasting/player_set.c \
			raycasting/raycasting_utils2.c \
			raycasting/ray.c \
			raycasting/player_move.c \
			key_handles/key_handles.c \
			key_handles/mouse.c \
			key_handles/key_checks_one.c \
			key_handles/key_checks_two.c \
			key_handles/key_checks_three.c \



OBJS	= $(SRCS:.c=.o)
FLAGS	= -crs
mlx		= ./mlx/libmlx.a

CC		= gcc -g3
RM		= rm -rf
CFLAGS	= -Wall -Wextra -Werror -g3 -Ofast -march=native
NAME	= cub3d

MAKELIB	=	@make -C libft
LIBFT	=	libft/libft.a
CLNLIB	=	@make clean -C libft
FCLNLIB	=	@make fclean -C libft

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKELIB)
	@echo "$(CYAN)Compiling $(NAME)...\n$(RESET)"
	@make -C ./mlx
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(mlx) -framework OpenGL -framework AppKit
	@echo "$(GREEN)Compilation completed.$(RESET)"

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<
	@echo "$(MAGENTA)Compiled $< into $@.$(RESET)"

clean:
	$(CLNLIB)
	@$(RM) $(OBJS)
	@make clean -C ./mlx && rm -rf *.dSYM
	@echo "$(YELLOW)Removed object files.$(RESET)"

fclean: clean
	$(FCLNLIB)
	@$(RM) $(NAME)
	@make clean -C ./mlx && rm -rf *.dSYM
	@echo "$(YELLOW)Removed executable.$(RESET)"

re: fclean all
		make clean

exec: fclean all
		./cub3d map.cub

.PHONY: all clean fclean re
