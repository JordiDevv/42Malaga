NAME = brainz

CFLAGS = -Wall -Werror -Wextra
98STD = -std=c++98

SRCS = main.cpp classes/Zombie.cpp utils/newZombie.cpp utils/randomChump.cpp
CL_HEADS = -I./classes
HEADERS = -I./headers

OBJS = $(SRCS:.cpp=.o)
INCLUDE = $(CL_HEADS) $(HEADERS)

all: $(NAME)

$(NAME):$(OBJS)
	g++ $(CFLAGS) $(98STD) $(INCLUDE) $(OBJS) -o $(NAME)

%.o: %.cpp
	g++ $(CFLAGS) $(98STD) $(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
