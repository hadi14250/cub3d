
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
			raycasting/utils.c \
			raycasting/key_handles.c \
			raycasting/line_drawing.c \
			raycasting/drawing_utils.c \
			raycasting/raycasting.c \
			raycasting/map.c
			
BONUSSRCS	=	bonus/main.c \
			bonus/parsing/parse_ext.c \
			bonus/parsing/parse_utils.c \
			bonus/parsing/parse_colors.c \
			bonus/parsing/parse_mapfile.c \
			bonus/parsing/parse_validate.c \
			bonus/parsing/parse_initializer.c \
			bonus/raycasting/utils.c \
			bonus/raycasting/key_handles.c \
			bonus/raycasting/line_drawing.c \
			bonus/raycasting/drawing_utils.c \
			bonus/raycasting/raycasting.c \


BONUSOBJS	=	$(BONUSSRCS:.c=.o)
BONUSNAME	=	cub3d_bonus

OBJS	= $(SRCS:.c=.o)
FLAGS	= -crs
mlx		= ./mlx/libmlx.a

CC		= gcc -g3
RM		= rm -rf
CFLAGS	= -Wall -Wextra -Werror -Ofast -march=native
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
	# @make clean -C ./bonus
	@echo "$(YELLOW)Removed object files.$(RESET)"

fclean: clean
	$(FCLNLIB)
	@$(RM) $(NAME)
	# @$(RM) $(BONUSNAME)
	@make clean -C ./mlx && rm -rf *.dSYM
	@echo "$(YELLOW)Removed executable.$(RESET)"

re: fclean all
		make clean

bonus: $(BONUSNAME)
$(BONUSNAME): $(BONUSOBJS)
	$(MAKELIB)
	@echo "$(CYAN)Compiling $(BONUSNAME)...\n$(RESET)"
	@make -C ./mlx
	@$(CC) $(CFLAGS) -o $(BONUSNAME) $(BONUSOBJS) $(LIBFT) $(mlx) -framework OpenGL -framework AppKit
	@echo "$(GREEN)Compilation completed.$(RESET)"

exec: fclean all
		./cub3d map.cub

execb: fclean bonus
		./cub3d_bonus map.cub

.PHONY: all clean fclean re bonus
