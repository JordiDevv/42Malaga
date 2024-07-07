NAME = push_swap.out
INCLUDE = libft.h push_swap.h

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCS = main.c ft_atoi.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):$(OBJS) $(INCLUDE)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(INCLUDE)

%o:%c
	$(CC) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
