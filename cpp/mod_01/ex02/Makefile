NAME = hi_this_is_brain

CFLAGS = -Wall -Werror -Wextra
98STD = -std=c++98

SRCS = main.cpp
CL_HEADS = -I./classes

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME):$(OBJS)
	g++ $(CFLAGS) $(98STD) $(OBJS) -o $(NAME)

%.o: %.cpp
	g++ $(CFLAGS) $(98STD) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
