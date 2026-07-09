# DEFINITIONS

NAME = PmergeMe

CFLAGS = -Wall -Werror -Wextra
STD = -std=c++98

IMPS = PmergeMe.cpp
IMPS_DIR = classes/
SRCS = main.cpp $(addprefix $(IMPS_DIR),$(IMPS))

DEFS = -I./classes
OBJS = $(SRCS:.cpp=.o)

GREEN=\033[0;36m
BLUE=\033[0;34m
YELLOW=\033[0;33m
NC=\033[0m

# BASIC RULES

all: $(NAME)

$(NAME):$(OBJS)
	@echo "$(BLUE)Compiling source code...$(NC)"
	@echo "$(BLUE)Compiling program...$(NC)"
	@g++ $(CFLAGS) $(STD) $(DEFS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)Program compiled!$(NC)"

%.o: %.cpp
	@g++ $(CFLAGS) $(STD) $(DEFS) -c $< -o $@

clean:
	@echo "$(YELLOW)Deleting objects...$(NC)"
	@rm -f $(OBJS)

fclean: clean
	@echo "$(YELLOW)Deleting program...$(NC)"
	@rm -f $(NAME)

re: fclean all

# RESERVED WORDS

.PHONY: all clean fclean re
