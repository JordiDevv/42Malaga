NAME = pipex
INCLUDE = pipex.h
LIBS = ft_printf/libftprintf.a
BLIBS = bonus/get_next_line/gnl.a

GREEN = \033[32m
CYAN = \033[36m
RESET = \033[0m

CFLAGS = -Wall -Werror -Wextra

SRCS = src/main.c src/executors.c src/free_exit.c src/valid_cmd.c \
utils/ft_split.c utils/mem_utils.c utils/str_utils.c utils/strmcat.c

BNS = bonus/main_bonus.c bonus/executors_bonus.c bonus/heredoc_utils_bonus.c \
src/free_exit.c src/valid_cmd.c utils/ft_split.c utils/mem_utils.c \
utils/str_utils.c utils/strmcat.c

OBJS = $(SRCS:.c=.o)
BOBJS = $(BNS:.c=.o)

all: $(NAME)

$(NAME):$(OBJS) $(INCLUDE) $(LIBS)
	cc $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

%o:%c
	cc $(CFLAGS) -g -c $< -o $@

ft_printf/libftprintf.a:
	@$(MAKE) -C ft_printf

bonus/get_next_line/gnl.a:
	@$(MAKE) -C bonus/get_next_line

bonus: $(BOBJS) $(INCLUDE) $(LIBS) $(BLIBS)
	cc $(CFLAGS) $(BOBJS) $(LIBS) $(BLIBS) -o $(NAME)

clean:
	rm -f $(OBJS) $(BOBJS)
	@$(MAKE) -C ft_printf clean
	@$(MAKE) -C bonus/get_next_line clean

fclean: clean
	rm -f $(NAME) outfile
	@$(MAKE) -C ft_printf fclean
	@$(MAKE) -C bonus/get_next_line fclean

re: fclean all

test:
	@echo "$(CYAN)./pipex notes.txt cat outfile$(RESET)"
	@./pipex notes.txt cat outfile
	@echo "$(CYAN)./pipex notes.txt c outfile$(RESET)"
	@./pipex notes.txt c outfile
	@echo "$(CYAN)./pipex not.txt c "wc -l" outfile$(RESET)"
	@./pipex not.txt c "wc -l" outfile
	@echo "$(GREEN)outfile content:\n$$(cat outfile)$(RESET)"
	@echo "$(CYAN)./pipex not.txt cat "wc -l" outfile$(RESET)"
	@./pipex not.txt cat "wc -l" outfile
	@echo "$(GREEN)outfile content:\n$$(cat outfile)$(RESET)"
	@echo "$(CYAN)./pipex not.txt cat c outfile$(RESET)"
	@./pipex not.txt cat c outfile
	@echo "$(GREEN)outfile content:\n$$(cat outfile)$(RESET)"
	@echo "$(CYAN)./pipex notes.txt cat c outfile$(RESET)"
	@./pipex notes.txt cat c outfile
	@echo "$(GREEN)outfile content:\n$$(cat outfile)$(RESET)"
	@echo "$(CYAN)./pipex notes.txt c "wc -l" outfile$(RESET)"
	@./pipex notes.txt c "wc -l" outfile
	@echo "$(GREEN)outfile content:\n$$(cat outfile)$(RESET)"
	@echo "$(CYAN)./pipex notes.txt cat c c outfile$(RESET)"
	@./pipex notes.txt cat c c outfile
	@echo "$(GREEN)outfile content:\n$$(cat outfile)$(RESET)"
	@echo "$(CYAN)./pipex notes.txt cat cat cat outfile$(RESET)"
	@./pipex notes.txt cat cat cat outfile
	@echo "$(GREEN)outfile content:\n$$(cat outfile)$(RESET)"
	@echo "$(CYAN)./pipex notes.txt cat "wc -l" outfile$(RESET)"
	@./pipex notes.txt cat "wc -l" outfile
	@echo "$(GREEN)outfile content:\n$$(cat outfile)$(RESET)"

bonus_test:
	@echo "$(CYAN)./pipex notes.txt cat "wc -l" c outfile$(RESET)"
	@./pipex notes.txt cat "wc -l" c outfile
	@echo "$(GREEN)outfile content:\n$$(cat outfile)$(RESET)"
	@echo "$(CYAN)./pipex notes.txt cat c c outfile$(RESET)"
	@./pipex notes.txt cat c c outfile
	@echo "$(GREEN)outfile content:\n$$(cat outfile)$(RESET)"
	@echo "$(CYAN)./pipex notes.txt c c c outfile$(RESET)"
	@./pipex notes.txt c c c outfile
	@echo "$(GREEN)outfile content:\n$$(cat outfile)$(RESET)"
	@echo "$(CYAN)./pipex notes.txt c "wc -l" cat outfile$(RESET)"
	@./pipex notes.txt c "wc -l" cat outfile
	@echo "$(GREEN)outfile content:\n$$(cat outfile)$(RESET)"
	@echo "$(CYAN)./pipex notes.txt cat c cat outfile$(RESET)"
	@./pipex notes.txt cat c cat outfile
	@echo "$(GREEN)outfile content:\n$$(cat outfile)$(RESET)"
	@echo "$(CYAN)./pipex notes.txt cat "wc -l" "wc -l" outfile$(RESET)"
	@./pipex notes.txt cat "wc -l" "wc -l" outfile
	@echo "$(GREEN)outfile content:\n$$(cat outfile)$(RESET)"
	@echo "$(CYAN)./pipex here_doc END c "wc -l" outfile$(RESET)"
	@./pipex here_doc END c "wc -l" outfile
	@echo "$(GREEN)outfile content:\n$$(cat outfile)$(RESET)"
	@echo "$(CYAN)./pipex here_doc END cat c outfile$(RESET)"
	@./pipex here_doc END cat c outfile
	@echo "$(GREEN)outfile content:\n$$(cat outfile)$(RESET)"
	@echo "$(CYAN)./pipex here_doc END cat "wc -l" outfile$(RESET)"
	@./pipex here_doc END cat "wc -l" outfile
	@echo "$(GREEN)outfile content:\n$$(cat outfile)$(RESET)"
	@echo "$(CYAN)./pipex here_doc END "wc -l" outfile$(RESET)"
	@./pipex here_doc END "wc -l" outfile
	@echo "$(GREEN)outfile content:\n$$(cat outfile)$(RESET)"
	@echo "$(CYAN)./pipex here_doc END c outfile$(RESET)"
	@./pipex here_doc END c outfile
	@echo "$(GREEN)outfile content:\n$$(cat outfile)$(RESET)"

.PHONY: all clean fclean re bonus
