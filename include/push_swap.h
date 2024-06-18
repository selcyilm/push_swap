#ifndef PUSH_SWAP
#define PUSH_SWAP

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <limits.h>

typedef struct s_node
{
	int				data;
	struct	s_node	*next;
	struct	s_node	*prev;
}	t_node;

// checker functions
bool	check_non_numeric(char **str);
bool	check_duplicate(char **str);
void	error_display(char **av);

//stact init functions
t_node	*ft_lstlast(t_node *lst);
t_node	*insert_at_tail(t_node *head, int data);
t_node	*stack_init(t_node *head, char **av);
void	stack_free(t_node *head);

#endif
