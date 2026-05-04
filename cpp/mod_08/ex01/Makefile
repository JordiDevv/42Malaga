NAME = span

CFLAGS = -Wall -Werror -Wextra
STD = -std=c++98

IMPS = Span.cpp
IMPS_DIR = classes/
SRCS = main.cpp $(addprefix $(IMPS_DIR),$(IMPS))

DEFS = -I./classes
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
