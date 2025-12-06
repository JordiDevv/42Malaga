NAME = harlFilter

CFLAGS = -Wall -Werror -Wextra
98STD = -std=c++98

SRCS = main.cpp Harl.cpp
DEFS = -I./defs
HEAD = -I./headers

OBJS = $(SRCS:.cpp=.o)
INC = $(DEFS) $(HEAD)

all: $(NAME)

$(NAME):$(OBJS)
	g++ $(CFLAGS) $(98STD) $(INC) $(OBJS) -o $(NAME)

%.o: %.cpp
	g++ $(CFLAGS) $(98STD) $(INC) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
