NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g -arch arm64

MLX_PATH = ./libs/mlx_macos

MLX_LIB = $(MLX_PATH)/libmlx.a

MLX_FLAGS = -L$(MLX_PATH) -lmlx -framework OpenGL -framework AppKit -arch arm64

LIBFT_PATH = ./libs/libft

LIBFT_LIB = $(LIBFT_PATH)/libft.a


Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

CFILES = \
 		srcs/errors.c\
		srcs/draw.c\
		srcs/exit_actions.c\
		srcs/free.c\
		srcs/game_events.c\
		srcs/game_events_utils.c\
		srcs/game_init.c\
		srcs/map_init.c\
		srcs/map_init_utils.c\
		srcs/map_validate.c\
		srcs/utils.c\
		srcs/main.c\

OBJECTS = $(CFILES:.c=.o)

all: subsystems $(NAME)

%.o : %.c
	@echo $(Y)Compiling [$<]...$(X)
	@$(CC) $(CFLAGS) -Imlx -c -o $@ $<
	@printf $(UP)$(CUT)

subsystems:
	@echo $(B)
	make -C $(MLX_PATH) all
	@echo $(B)
	make -C $(LIBFT_PATH) all

$(NAME): $(OBJECTS)
	@echo $(Y)Compiling [$(CFILES)]...$(X)
	@echo $(G)Finished [$(CFILES)]$(X)
	@echo
	@echo $(Y)Compiling [$(NAME)]...$(X)
	@$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJECTS) $(MLX_LIB) $(LIBFT_LIB) -o $(NAME)
	@echo $(G)Finished [$(NAME)]$(X)

clean:
	@make -C $(MLX_PATH) clean
	@make -C $(LIBFT_PATH) clean
	@rm -f $(OBJECTS)
	@echo $(R)Removed [$(OBJECTS)]$(X)

fclean: clean
	@make -C $(MLX_PATH) fclean
	@make -C $(LIBFT_PATH) fclean
	@rm -f $(NAME)
	@echo $(R)Removed [$(NAME)]$(X)

re: fclean all

.PHONY: all clean fclean