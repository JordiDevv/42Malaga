NAME = btc

CFLAGS = -Wall -Werror -Wextra
STD = -std=c++98

IMPS = BitcoinExchange.cpp
IMPS_DIR = classes/
SRCS = main.cpp $(addprefix $(IMPS_DIR),$(IMPS))

DEFS = -I./classes
OBJS = $(SRCS:.cpp=.o)

GREEN=\033[0;36m
BLUE=\033[0;34m
YELLOW=\033[0;33m
RED=\033[0;31m
NC=\033[0m

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

fclean: clean delete
	@echo "$(YELLOW)Deleting program...$(NC)"
	@rm -f $(NAME)

delete:
	@echo "$(YELLOW)Deleting output file...$(NC)"
	@if [ ! -f .output_name ]; then \
		echo "$(RED)There was no output file$(NC)"; \
	else \
		rm -f `cat .output_name`; \
		rm -f .output_name; \
	fi

re: fclean all

.PHONY: all clean fclean re
