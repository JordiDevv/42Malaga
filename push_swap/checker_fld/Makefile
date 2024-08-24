NAME = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror
PUSH_SWAP_ARCHIVE = ../push_swap.a

SRCS = checker_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c write_res_bonus.c
OBJS = $(SRCS:.c=.o)

%.o: %.c 
	$(CC) -c $(CFLAGS) $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(PUSH_SWAP_ARCHIVE) 
	$(CC) $(CFLAGS) $^ -o $(NAME)
	cp $(NAME) .. 

$(PUSH_SWAP_ARCHIVE):
	cd .. && make

clean:
	rm -f $(OBJS)

fclean: clean 
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re