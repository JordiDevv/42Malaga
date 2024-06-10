NAME = libftprintf.a
INCLUDE = $(SUBD)jslib.h libftprintf.h
SUBD = jslib/

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCS = $(SUBD)ft_intlen.c $(SUBD)ft_itoa.c $(SUBD)ft_strlen.c \
       ft_ptrtohex.c ft_ulen.c ft_utohex.c printf_utils.c ft_printf.c \
       ft_stradd.c ft_utoa.c ft_hexlen.c

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
