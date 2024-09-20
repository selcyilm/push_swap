# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: selcyilm <selcyilm@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2024/09/17 21:39:26 by selcyilm      #+#    #+#                  #
#    Updated: 2024/09/20 16:20:39 by selcyilm      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = $(wildcard src/*.c)
OBJS = $(SRCS:.c=.o)

CC = gcc -Wall -Werror -Wextra -g

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	$(CC) $(OBJS) ./libft/libft.a -o $(NAME)

clean:
	$(MAKE) -C ./libft fclean
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
