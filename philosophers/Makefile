NAME = philosophers
INCLUDE = philosophers.h

GREEN = \033[32m
CYAN = \033[36m
RESET = \033[0m

CFLAGS = -Wall -Werror -Wextra

SRCS = 

BNS = 

OBJS = $(SRCS:.c=.o)
BOBJS = $(BNS:.c=.o)

all: $(NAME)

$(NAME):$(OBJS) $(INCLUDE)
	cc $(CFLAGS) $(OBJS) -o $(NAME)

%o:%c
	cc $(CFLAGS) -g -c $< -o $@

bonus: $(BOBJS) $(INCLUDE)
	cc $(CFLAGS) $(BOBJS) -o $(NAME)

clean:
	rm -f $(OBJS) $(BOBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all