NAME = libftprintf.a
# INCLUDE =

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCS = $(wildcard *.c)

# BSRCS =

OBJS = $(SRCS:.c=.o)

# BOBJS = $(BSRCS:.c=.o)

all: $(NAME)

$(NAME):$(OBJS) # $(INCLUDE)
	ar rcs $@ $^

%o:%c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) # $(BOBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

# bonus: $(OBJS) $(BOBJS) $(INCLUDE)
	# ar rcs $(NAME) $^

.PHONY: all clean fclean re # bonus
