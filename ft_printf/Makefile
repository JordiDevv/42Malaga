NAME = libftprintf.a
INCLUDE = ft_printf.h

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCS = ft_printf.c put_input.c hex_utils.c str_utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):$(OBJS) $(INCLUDE)
	ar rcs $@ $^

%o:%c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
