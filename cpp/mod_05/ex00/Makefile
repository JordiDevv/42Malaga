NAME = bureaucrat

CFLAGS = -Wall -Werror -Wextra
STD = -std=c++98

SRCS = main.cpp Bureaucrat.cpp
HEADERS = Bureaucrat.hpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME):$(OBJS)
	g++ $(CFLAGS) $(STD) $(OBJS) -o $(NAME)

%.o: %.cpp $(HEADERS)
	g++ $(CFLAGS) $(STD) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
