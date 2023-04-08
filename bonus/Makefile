
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
			raycasting/utils.c \
			raycasting/key_handles.c \
			raycasting/line_drawing.c \
			raycasting/drawing_utils.c \
			raycasting/raycasting.c \
			


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
	@echo "$(YELLOW)Removed object files.$(RESET)"

fclean: clean
	$(FCLNLIB)
	@$(RM) $(NAME)
	@$(RM) $(BONUSNAME)
	@make clean -C ./mlx && rm -rf *.dSYM
	@echo "$(YELLOW)Removed executable.$(RESET)"

re: fclean all
		make clean

exec: fclean all
		./cub3d map.cub

.PHONY: all clean fclean re