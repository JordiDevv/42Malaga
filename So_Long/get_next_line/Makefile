NAME = gnl.a
INCLUDE = get_next_line.h

COMPILE_FLAGS = cc -Wall -Werror -Wextra

SRCS = get_next_line.c get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

CC = cc

all: $(NAME)

$(NAME):$(OBJS) $(INCLUDE)
	ar rcs $@ $^

%.o: %.c $(INCLUDE)
	$(COMPILE_FLAGS) -c $< -o $@

clean: 
	rm -f $(OBJS) $(BOBJS)

fclean: clean
	rm -f $(NAME) $(BNAME)

re: fclean all

.PHONY: all clean fclean re bonus
