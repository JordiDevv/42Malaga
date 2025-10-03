NAME = phonebook

CFLAGS = -Wall -Werror -Wextra
98STD = -std=c++98

SRCS = 

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME):$(OBJS)
	g++ $(CFLAGS) $(98STD) $(OBJS) -o $(NAME)

test_1:
	

test_2:
	

test_3:
	

%o:%c
	g++ $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all