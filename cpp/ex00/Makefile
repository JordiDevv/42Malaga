NAME = megaphone

CFLAGS = -Wall -Werror -Wextra
98STD = -std=c++98

SRCS = megaphone.cpp

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):$(OBJS)
	cc $(CFLAGS) $(98STD) $(OBJS) -o $(NAME)

test_1:
	./megaphone "shhhhh... I think the students are asleep..."

test_2:
	./megaphone Damnit " ! " "Sorry students, I thought this thing was off."

test_3:
	./megaphone

%o:%c
	g++ $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all