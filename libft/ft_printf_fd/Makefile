# **************************************************************************** #
#                                                                              #
#                                                          ::::::::            #
#    Makefile                                            :+:    :+:            #
#                                                       +:+                    #
#    By: selcyilm <marvin@42.fr>                       +#+                     #
#                                                     +#+                      #
#    Created: 2024/10/10 18:22:09 by selcyilm       #+#    #+#                 #
#    Updated: 2024/10/15 10:30:21 by selcyilm       ########   odam.nl         #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_printf_fd.c\
			ft_strlen_fd.c\
			print_digit_fd.c\
			print_hex_fd.c\
			print_ptr_fd.c\
			print_str_fd.c\
			print_unsigned_fd.c

OBJS	= $(SRCS:.c=.o)

NAME	= libftprintf_fd.a

CFLAGS	= -Wall -Werror -Wextra

HEADERS = ft_printf_fd.h

CC		= cc
RM		= rm -f

COLOUR_GREEN=\033[35m
COLOUR_BLUE=\033[0;36m
COLOUR_END=\033[0m
COLOUR_ORANGE=\033[38;5;214m

$(NAME): $(OBJS)
	@ar rcs $@ $^

%.o: %.c $(HEADERS)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(COLOUR_GREEN)CREATING $@$(COLOUR_END)"

all: $(NAME)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)


re: fclean all

.PHONY: all clean fclean re
