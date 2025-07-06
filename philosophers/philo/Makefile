NAME = philo
INCLUDE = philosophers.h

GREEN = \033[32m
CYAN = \033[36m
RESET = \033[0m

CFLAGS = -Wall -Werror -Wextra
HELGRIND = valgrind --tool=helgrind ./philo 5 800 200 200 7
THREADS = -fsanitize=thread -g3
VALGRIND = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./philo 1 800 200 200

SRCS = init_data.c main.c parser.c str_utils.c philo_behavior.c checker_behavior.c utils.c close.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

valgrind:
	$(VALGRIND)

helgrind:
	$(HELGRIND)

$(NAME):$(OBJS) $(INCLUDE)
	cc $(CFLAGS) $(OBJS) -o $(NAME)

%o:%c
	gcc $(CFLAGS) -c $< -o $@ -pthread

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all