NAME = pipex
INCLUDE = pipex.h

CFLAGS = -Wall -Werror -Wextra

SRCS = main.c executors.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):$(OBJS) $(INCLUDE)
	cc $(OBJS) $(INCLUDE) -o $(NAME)

%o:%c
	cc -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
