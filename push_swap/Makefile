NAME = push_swap
INCLUDE = push_swap.h

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCS = main.c split.c init_stack.c error_free.c stack_utils.c push.c swap.c\
reverse_rotate.c rotate.c set_nodes_utils.c sort_utils.c sorting_algs.c

OBJS = $(SRCS:.c=.o)

INPUT = 0

all: $(NAME)

$(NAME): $(OBJS) $(INCLUDE)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%o: %c $(INCLUDE)
	$(CC) -c $< -o $@

deb:
	gcc -g -o $(NAME) $(SRCS)

gemartin_tester: $(NAME)
	@git clone https://github.com/gemartin99/Push-Swap-Tester.git
	@mv Push-Swap-Tester/push_swap_test_linux.sh .
	@mv Push-Swap-Tester/checker_linux .
	@bash push_swap_test_linux.sh

delete_gemartin_tester:
	@rm -f push_swap_test_linux.sh checker_linux 0 traces.txt
	@rm -rf Push-Swap-Tester

basic_check: $(NAME)
	@./$(NAME) $(INPUT) | ./checker_linux $(INPUT)

visualizer: $(NAME)
	@git clone https://github.com/o-reo/push_swap_visualizer.git
	@cd push_swap_visualizer && mkdir build
	@cd push_swap_visualizer/build && cmake ..
	@cd push_swap_visualizer/build && make
	@./push_swap_visualizer/build/bin/visualizer

ex_visualizer:
	@./push_swap_visualizer/build/bin/visualizer

delete_visualizer:
	@rm -f imgui.ini
	@rm -rf push_swap_visualizer

clean:
	rm -f $(OBJS)

fclean: clean delete_gemartin_tester delete_visualizer
	rm -f $(NAME) *.gch

re: fclean all

.PHONY: all clean fclean re bonus
