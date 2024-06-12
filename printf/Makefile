NAME = libftprintf.a
INCLUDE = ft_printf.h

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCS = ft_strlen.c ft_strlcpy.c ft_printf.c hex_utils.c put_input.c

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
