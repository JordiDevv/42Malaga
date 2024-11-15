NAME = pipex
INCLUDE = pipex.h
LIBS = ft_printf/libftprintf.a
BLIBS = bonus/get_next_line/gnl.a

CFLAGS = -Wall -Werror -Wextra

SRCS = src/main.c src/executors.c src/free_exit.c src/valid_cmd.c \
utils/ft_split.c utils/mem_utils.c utils/str_utils.c utils/strmcat.c

BNS = bonus/main_bonus.c bonus/executors_bonus.c bonus/utils_bonus.c \
src/free_exit.c src/valid_cmd.c utils/ft_split.c utils/mem_utils.c \
utils/str_utils.c utils/strmcat.c

OBJS = $(SRCS:.c=.o)
BOBJS = $(BNS:.c=.o)

all: $(NAME)

$(NAME):$(OBJS) $(INCLUDE) $(LIBS)
	cc $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

%o:%c
	cc $(CFLAGS) -g -c $< -o $@

ft_printf/libftprintf.a:
	@$(MAKE) -C ft_printf

bonus/get_next_line/gnl.a:
	@$(MAKE) -C bonus/get_next_line

bonus: $(BOBJS) $(INCLUDE) $(LIBS) $(BLIBS)
	cc $(CFLAGS) $(BOBJS) $(LIBS) $(BLIBS) -o $(NAME)

clean:
	rm -f $(OBJS) $(BOBJS)
	@$(MAKE) -C ft_printf clean
	@$(MAKE) -C bonus/get_next_line clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C ft_printf fclean
	@$(MAKE) -C bonus/get_next_line fclean

re: fclean all

.PHONY: all clean fclean re bonus
