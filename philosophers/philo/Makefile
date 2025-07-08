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

test_1:
	./philo 1 800 200 200

test_2:
	./philo 5 800 200 200

test_3:
	./philo 5 800 200 200 7

test_4:
	./philo 4 410 200 200

test_5:
	./philo 4 310 200 100

test_6:
	./philo 2 200 100 100

%o:%c
	gcc $(CFLAGS) -c $< -o $@ -pthread

last_kernel:
	$(LAST_KERNEL)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all