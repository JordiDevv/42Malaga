NAME = So_Long
INCLUDE = so_long.h
LIBS = ft_printf/libftprintf.a get_next_line/gnl.a MLX42/build/libmlx42.a

FLAGS_MLX = -Iinclude -ldl -lglfw -pthread -lm -lGL
FLAGS_42 = -Wall -Werror -Wextra

SRCS = src/main.c src/game/cell_handler.c src/game/game_controller.c \
src/game/player_movement.c src/parsing/error_handler.c src/parsing/get_map.c \
src/parsing/parse_utils.c src/parsing/path_error_utils.c \
src/utils/free_utils.c src/utils/mem_utils.c src/utils/str_utils.c

BSRCS = src/main.c src/game/cell_handler.c src/game/game_controller.c \
bonus/player_movement_bonus.c bonus/error_handler_bonus.c \
src/parsing/get_map.c src/parsing/parse_utils.c \
bonus/path_error_utils_bonus.c src/utils/free_utils.c src/utils/mem_utils.c \
src/utils/str_utils.c bonus/enemies_ai.c bonus/bonus_utils.c bonus/ft_itoa.c

OBJS = $(SRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)

all: $(NAME)

$(NAME):$(OBJS) $(INCLUDE) $(LIBS)
	cc $(FLAGS_42) $(OBJS) $(INCLUDE) $(LIBS) $(FLAGS_MLX) -o $(NAME)

ft_printf/libftprintf.a:
	@$(MAKE) -C ft_printf

get_next_line/gnl.a:
	@$(MAKE) -C get_next_line

MLX42/build/libmlx42.a:
	@$(MAKE) -C MLX42

%o:%c
	cc $(FLAGS_42) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -f bonus/$(BOBJS)
	@$(MAKE) -C ft_printf clean
	@$(MAKE) -C get_next_line clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C ft_printf fclean
	@$(MAKE) -C get_next_line fclean
	@$(MAKE) -C MLX42 fclean

re: fclean all

bonus:$(BOBJS) $(INCLUDE) $(LIBS)
	cc $(FLAGS_42) $(BOBJS) $(INCLUDE) $(LIBS) $(FLAGS_MLX) -o $(NAME)

.PHONY: all clean fclean re bonus