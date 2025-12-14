NAME = a.out

CFLAGS = -Wall -Werror -Wextra
98STD = -std=c++98

IMPS = ClapTrap.cpp ScavTrap.cpp FragTrap.cpp
IMPS_DIR = classes/imps/
SRCS = main.cpp $(addprefix $(IMPS_DIR),$(IMPS))

DEFS = -I./classes/defs
HEADERS = -I./headers

OBJS = $(SRCS:.cpp=.o)
INC = $(DEFS) $(HEADERS)

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
