# **************************************************************************** #
#                                                                              #
#                                                          ::::::::            #
#    Makefile                                            :+:    :+:            #
#                                                       +:+                    #
#    By: selcyilm <marvin@42.fr>                       +#+                     #
#                                                     +#+                      #
#    Created: 2024/10/08 14:20:15 by selcyilm       #+#    #+#                 #
#    Updated: 2024/10/08 14:20:17 by selcyilm       ########   odam.nl         #
#                                                                              #
# **************************************************************************** #

SRCS		=	./stdlib/ft_atoi.c\
			./stdlib/ft_calloc.c\
			./stdlib/ft_atol.c\
			./stdlib/ft_atoll.c\
			./stdlib/ft_atof.c\
			./ctype/ft_isalnum.c\
			./ctype/ft_isalpha.c\
			./ctype/ft_isascii.c\
			./ctype/ft_isdigit.c\
			./ctype/ft_isprint.c\
			./ctype/ft_tolower.c\
			./ctype/ft_toupper.c\
			./ctype/ft_isspace.c\
			./mem/ft_bzero.c\
			./mem/ft_memchr.c\
			./mem/ft_memcmp.c\
			./mem/ft_memcpy.c\
			./mem/ft_memmove.c\
			./mem/ft_memset.c\
			./put/ft_putchar_fd.c\
			./put/ft_putendl_fd.c\
			./put/ft_putnbr_fd.c\
			./put/ft_putstr_fd.c\
			./string/ft_itoa.c\
			./string/ft_split.c\
			./string/ft_striteri.c\
			./string/ft_strchr.c\
			./string/ft_strdup.c\
			./string/ft_strjoin.c\
			./string/ft_strlcat.c\
			./string/ft_strlcpy.c\
			./string/ft_strlen.c\
			./string/ft_strmapi.c\
			./string/ft_strncmp.c\
			./string/ft_strnstr.c\
			./string/ft_strrchr.c\
			./string/ft_strtrim.c\
			./string/ft_substr.c\
			./get_next_line/get_next_line.c\
			./get_next_line/get_next_line_utils.c\


SRCS_BONUS	= ./linked_list/ft_lstadd_back_bonus.c\
			./linked_list/ft_lstadd_front_bonus.c\
			./linked_list/ft_lstclear_bonus.c\
			./linked_list/ft_lstdelone_bonus.c\
			./linked_list/ft_lstlast_bonus.c\
			./linked_list/ft_lstnew_bonus.c\
			./linked_list/ft_lstsize_bonus.c\
			./linked_list/ft_lstiter_bonus.c\
			./linked_list/ft_lstmap_bonus.c

OBJS		=	$(SRCS:.c=.o)
OBJS_BONUS	=	$(SRCS_BONUS:.c=.o)

NAME	=	libft.a
RM		=	rm -f
LIB		=	ar rcs
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

PRINTF	=	ft_printf/ft_printf.o\
			ft_printf/ft_strlen.o\
			ft_printf/print_digit.o\
			ft_printf/print_hex.o\
			ft_printf/print_ptr.o\
			ft_printf/print_str.o\
			ft_printf/print_unsigned.o

PRINTF_FD =	./ft_printf_fd/ft_printf_fd.o\
			./ft_printf_fd/ft_strlen_fd.o\
			./ft_printf_fd/print_digit_fd.o\
			./ft_printf_fd/print_hex_fd.o\
			./ft_printf_fd/print_ptr_fd.o\
			./ft_printf_fd/print_str_fd.o\
			./ft_printf_fd/print_unsigned_fd.o

COLOUR_GREEN=\033[35m
COLOUR_BLUE=\033[0;36m
COLOUR_END=\033[0m
COLOUR_ORANGE=\033[38;5;214m

ifdef WITH_BONUS
	OBJ_SWITCH = $(OBJS_BONUS) $(OBJS)
else
	OBJ_SWITCH = $(OBJS)
endif

$(NAME)		:	$(PRINTF) $(OBJ_SWITCH) $(PRINTF_FD)
			@$(LIB) $@ $^
			@echo "$(COLOUR_ORANGE)LIBFT.A IS READY TO GO$(COLOUR_END)"

$(PRINTF)	:
			@make -s -C ./ft_printf

$(PRINTF_FD):
			@make -s -C ./ft_printf_fd

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(COLOUR_GREEN)CREATING $@$(COLOUR_END)"

all			:	bonus $(NAME)

clean		:
			@$(RM) $(OBJS) $(OBJS_BONUS)
			@make -s clean -C ./ft_printf
			@make -s clean -C ./ft_printf_fd
			@echo "$(COLOUR_BLUE)CLEARING OBJECT FILES FOR LIBFT$(COLOUR_END)"

fclean		:	clean
			@$(RM) $(NAME)
			@make -s fclean -C ./ft_printf
			@make -s fclean -C ./ft_printf_fd
			@echo "$(COLOUR_BLUE)CLEANING EXECUTABLE FOR LIBFT...$(COLOUR_END)"

re		:	fclean all

bonus		:
			$(MAKE) -s WITH_BONUS=1 $(NAME)

.PHONY		:	all clean fclean re bonus
