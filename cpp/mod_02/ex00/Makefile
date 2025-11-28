NAME = a.out

CFLAGS = -Wall -Werror -Wextra
98STD = -std=c++98

SRCS = main.cpp Fixed.cpp
DEFS = -I./defs

OBJS = $(SRCS:.cpp=.o)
INC = $(DEFS)

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
