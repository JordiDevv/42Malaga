# DEFINITIONS

NAME = RPN

CFLAGS = -Wall -Werror -Wextra
STD = -std=c++98

IMPS = RPN.cpp
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

# BASIC TESTS

basic_tests: test1 test2 test3 test4

test1: $(NAME)
	@echo
	@echo "===== Test 1 ====="
	./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
	@echo

test2: $(NAME)
	@echo "===== Test 2 ====="
	./RPN "7 7 * 7 -"
	@echo

test3: $(NAME)
	@echo "===== Test 3 ====="
	./RPN "1 2 * 2 / 2 * 2 4 - +"
	@echo

test4: $(NAME)
	@echo "===== Test 4 ====="
	-./RPN "(1 + 1)"
	@echo

# ADVANCED TESTS

advanced_tests: test5 test6 test7 test8 test9 test10 test11 test12 test13 test14

test5: $(NAME)
	@echo
	@echo "===== Test 5 ====="
	-./RPN "1 + 1"
	@echo

test6: $(NAME)
	@echo "===== Test 6 ====="
	-./RPN "1 1 1 +"
	@echo

test7: $(NAME)
	@echo "===== Test 7 ====="
	-./RPN "1 2 3 + *"
	@echo

test8: $(NAME)
	@echo "===== Test 8 ====="
	-./RPN "2 2 * * 2"
	@echo

test9: $(NAME)
	@echo "===== Test 9 ====="
	-./RPN "22 *"
	@echo

test10: $(NAME)
	@echo "===== Test 10 ====="
	-./RPN " 2 2 *"
	@echo

test11: $(NAME)
	@echo "===== Test 11 ====="
	-./RPN "2 2 + "
	@echo

test12: $(NAME)
	@echo "===== Test 12 ====="
	-./RPN "   2 2 +"
	@echo

test13: $(NAME)
	@echo "===== Test 13 ====="
	-./RPN "2 2 +    "
	@echo

test14: $(NAME)
	@echo "===== Test 14 ====="
	-./RPN "   2   2     +     "
	@echo

# RESERVED WORDS

.PHONY: all clean fclean re
