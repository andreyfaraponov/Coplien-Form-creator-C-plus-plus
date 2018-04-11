NAME = ft_coplien

KEYS = -Wall -Wextra -Wno-c++11-extensions -std=c++11 -pedantic

CC = clang++

SRCS = srcs

_OBJ = $(SRC:%.cpp=%.o)

SRC = 	$(SRCS)/main.cpp \
		$(SRCS)/CoplienCreator.cpp \

IDIR = ./include

SDIR = srcs

OBJS = $(SRC:.cpp=.o)

.PHONY: all clean fclean re
.NOTPARALLEL: all clean fclean re

all: $(NAME)

%.o: %.cpp
	$(CC) -I $(IDIR) -c -o $@ $< $(KEYS)

$(NAME): $(OBJS)
	$(CC) $(KEYS) -o $(NAME) $(OBJS) -fsanitize=address

clean:
	@/bin/rm -rf srcs/*.o

fclean: clean
	@/bin/rm -f $(NAME)

re : fclean all
