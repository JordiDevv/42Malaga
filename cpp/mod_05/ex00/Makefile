NAME = a.out

CFLAGS = -Wall -Werror -Wextra
98STD = -std=c++98

SRCS = main.cpp Bureaucrat.cpp
HEADERS = Bureaucrat.hpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME):$(OBJS)
	g++ $(CFLAGS) $(98STD) $(HEADERS) $(OBJS) -o $(NAME)

%.o: %.cpp
	g++ $(CFLAGS) $(98STD) $(HEADERS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
