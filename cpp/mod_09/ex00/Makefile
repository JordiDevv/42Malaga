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

INPUT_FILE = input.txt

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
	@echo "$(YELLOW)Deleting input file...$(NC)"
	@if [ ! -f .input_name ]; then \
		echo "$(RED)There was no input file$(NC)"; \
	else \
		rm -f `cat .input_name`; \
		rm -f .input_name; \
	fi

input:
	@echo "$(BLUE)Generating default input file...$(NC)"
	@echo "date | value" > $(INPUT_FILE)
	@echo "2011-01-03 | 3" >> $(INPUT_FILE)
	@echo "2011-01-03 | 2" >> $(INPUT_FILE)
	@echo "2011-01-03 | 1" >> $(INPUT_FILE)
	@echo "2011-01-03 | 1.2" >> $(INPUT_FILE)
	@echo "2011-01-09 | 1" >> $(INPUT_FILE)
	@echo "2012-01-11 | -1" >> $(INPUT_FILE)
	@echo "2001-42-42" >> $(INPUT_FILE)
	@echo "2012-01-11 | 1" >> $(INPUT_FILE)
	@echo "2012-01-11 | 2147483648" >> $(INPUT_FILE)
	@echo $(INPUT_FILE) > .input_name

re: fclean all

.PHONY: all clean fclean re
