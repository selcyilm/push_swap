#ifndef PUSH_SWAP
# define PUSH_SWAP

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdbool.h>
# include <ctype.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

// checker functions
bool	check_non_numeric(char **str, int start_pos);
bool	check_string(char *str);
bool	check_duplicate_limit(char **str, int start_pos);
void	error_display(t_node **a, char **av, int start_pos);

//stact init functions
t_node	*ft_lastnode(t_node *lst);
t_node	*insert_at_tail(t_node *head, int data);
t_node	*stack_init(t_node *head, char **av, int start_index);
void	stack_free(t_node **head);

// for debug and printing functions
void	print_stack(t_node *stack);

// handle argv
t_node	*parse_av_if_two(t_node *stack, char *av);
t_node	*parse_av_if_more(t_node *stack, char**av);
void	free_argv(char **av);

//helper functions
long	ft_atol(char *str);
int		size_of_stack(t_node *stack);

//alg
void	sa(t_node *stack);
void	sb(t_node *stack);
void	ss(t_node *stack_a, t_node *stack_b);
void	pa(t_node **dest, t_node **src);
void	pb(t_node **dest, t_node **src);
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);

#endif
