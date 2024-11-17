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

SRCS = ./src/debug.c \
		./src/error_handle.c \
		./src/fill_index.c \
		./src/handle_argv.c \
		./src/push.c \
		./src/radix.c \
		./src/reverse_rotate.c \
		./src/rotate.c \
		./src/sort_alg.c \
		./src/stack_free.c \
		./src/stack_init.c \
		./src/stack_utils.c \
		./src/swap.c \
		./src/main.c \

OBJS = $(SRCS:.c=.o)
LIBFT = libft/libft.a
CC = cc -Wall -Werror -Wextra

RM = rm -rf

COLOUR_GREEN=\033[35m
COLOUR_BLUE=\033[0;36m
COLOUR_END=\033[0m
COLOUR_ORANGE=\033[38;5;214m

all: $(NAME) $(LIBFT)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(COLOUR_ORANGE)PUSH_SWAP IS READY TO GO$(COLOUR_END)"

$(LIBFT):
	@make -s -C libft/ all

%.o: %.c
	@$(CC) -c $< -o $@
	@echo "$(COLOUR_GREEN)CREATING $@$(COLOUR_END)"

clean:
	@make -s -C libft/ clean
	@$(RM) $(OBJS)
	@echo "$(COLOUR_BLUE)CLEARING OBJECT FILES FOR PUSH_SWAP$(COLOUR_END)"

fclean: clean
	@make -s -C libft/ fclean
	@$(RM) $(NAME)
	@echo "$(COLOUR_BLUE)CLEARING EXECUTABLE FOR PUSH_SWAP...$(COLOUR_END)"

re: fclean all

.PHONY: all clean fclean re
