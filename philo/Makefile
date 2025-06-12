NAME = philo
INCLUDE = philosophers.h

GREEN = \033[32m
CYAN = \033[36m
RESET = \033[0m

CFLAGS = -Wall -Werror -Wextra

SRCS = main.c parser.c utils.c str_utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):$(OBJS) $(INCLUDE)
	cc $(CFLAGS) $(OBJS) -o $(NAME) -pthread

%o:%c
	cc $(CFLAGS) -g -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all