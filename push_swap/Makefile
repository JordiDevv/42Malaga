NAME = push_swap
INCLUDE = libft.h push_swap.h

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCS = main.c ft_atoi.c nodes.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(INCLUDE)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%o: %c $(INCLUDE)
	$(CC) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) *.gch

re: fclean all

.PHONY: all clean fclean re bonus
