/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/20 16:43:11 by selcyilm      #+#    #+#                 */
/*   Updated: 2024/09/20 16:44:13 by selcyilm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdbool.h>
# include <ctype.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"

typedef struct s_node
{
	int				data;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

// checker functions
bool	check_non_numeric(char **str, int start_pos);
bool	check_string(char *str);
bool	check_duplicate_limit(char **str, int start_pos);
void	error_display(t_node **a, char **av, int start_pos);
bool	check_space(char *av);

//stact init functions
t_node	*ft_lastnode(t_node *lst);
t_node	*insert_at_tail(t_node *head, int data);
t_node	*stack_init(t_node *head, char **av, int start_index);
void	stack_free(t_node **head);

// handle argv
t_node	*parse_av_if_two(t_node *stack, char *av);
t_node	*parse_av_if_more(t_node *stack, char**av);
void	free_argv(char **av);

//helper functions
int		size_of_stack(t_node *stack);
bool	is_stack_sorted(t_node **stack);
t_node	*get_min(t_node *stack);
t_node	*get_max(t_node *stack);
void	fill_index(t_node *stack, int size);
int		get_pos(t_node *stack, int target);

//operations
void	sa(t_node **stack);
void	sb(t_node **stack);
void	ss(t_node **stack_a, t_node **stack_b);
void	pa(t_node **dest, t_node **src);
void	pb(t_node **dest, t_node **src);
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);

//alg
void	sort_three(t_node **stack);
void	sort_four(t_node **a, t_node **b);
void	sort_five(t_node **a, t_node **b);
void	push_all(t_node **src, t_node **dest);
int		check_max_bits(t_node **head);
void	radix_sort(t_node **a, t_node **b);

#endif
