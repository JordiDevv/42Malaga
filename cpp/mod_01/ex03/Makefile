NAME = unnecesary_violence

CFLAGS = -Wall -Werror -Wextra
98STD = -std=c++98

SRCS = main.cpp classes/imps/Weapon.cpp classes/imps/HumanA.cpp classes/imps/HumanB.cpp
DEFS = -I./classes/defs

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME):$(OBJS)
	g++ $(CFLAGS) $(98STD) $(DEFS) $(OBJS) -o $(NAME)

%.o: %.cpp
	g++ $(CFLAGS) $(98STD) $(DEFS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
