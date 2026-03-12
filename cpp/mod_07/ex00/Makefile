NAME = few_functions

CFLAGS = -Wall -Werror -Wextra
STD = -std=c++98

SRCS = main.cpp
INC = -I./templates
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME):$(OBJS)
	g++ $(CFLAGS) $(STD) $(DEFS) $(OBJS) -o $(NAME)

%.o: %.cpp
	g++ $(CFLAGS) $(STD) $(DEFS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
