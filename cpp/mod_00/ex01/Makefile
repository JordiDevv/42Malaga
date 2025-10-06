NAME = phonebook

CFLAGS = -Wall -Werror -Wextra
98STD = -std=c++98

SRCS = main.cpp Contact.cpp PhoneBook.cpp ft_add.cpp ft_search.cpp
CL_HEADS = Contact.hpp PhoneBook.hpp
HEADERS = msgs.h utils.h

OBJS = $(SRCS:.cpp=.o)
INCLUDE = $(CL_HEADS) $(HEADERS)

all: $(NAME)

$(NAME):$(OBJS)
	g++ $(CFLAGS) $(98STD) $(INCLUDE) $(OBJS) -o $(NAME)

%o:%c
	g++ $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all