NAME = pipex
INCLUDE = pipex.h
LIBS = ft_printf/libftprintf.a

CFLAGS = -Wall -Werror -Wextra

SRCS = src/main.c src/executors.c src/free_exit.c src/valid_cmd.c \
utils/ft_split.c utils/mem_utils.c utils/str_utils.c utils/strmcat.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):$(OBJS) $(INCLUDE) $(LIBS)
	cc $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

%o:%c
	cc $(CFLAGS) -g -c $< -o $@

ft_printf/libftprintf.a:
	@$(MAKE) -C ft_printf

clean:
	rm -f $(OBJS)
	@$(MAKE) -C ft_printf clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C ft_printf fclean

re: fclean all

.PHONY: all clean fclean re bonus
