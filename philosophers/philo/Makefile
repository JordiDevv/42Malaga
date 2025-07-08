NAME = philo
C_NAME = philo
INCLUDE = philosophers.h

GREEN = \033[32m
CYAN = \033[36m
RESET = \033[0m

CFLAGS = -Wall -Werror -Wextra
SANI_THREAD = -fsanitize=thread
LAST_KERNEL = setarch $(uname -m) -R $SHELL

SRCS = init_data.c main.c parser.c str_utils.c philo_behavior.c checker_behavior.c utils.c close.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):$(OBJS) $(INCLUDE)
	cc $(CFLAGS) $(OBJS) -o $(NAME)

sani_thread:$(OBJS) $(INCLUDE)
	cc $(CFLAGS) $(SANI_THREAD) $(OBJS) -o $(C_NAME)

%o:%c
	gcc $(CFLAGS) -c $< -o $@ -pthread

last_kernel:
	$(LAST_KERNEL)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all