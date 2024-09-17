/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/17 21:39:10 by selcyilm      #+#    #+#                 */
/*   Updated: 2024/09/17 21:39:11 by selcyilm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// t_node data, *next, *prev

void	sa(t_node *stack)
{
	int	tmp;

	if (size_of_stack(stack) <= 1)
		return ;
	tmp = stack->data;
	stack->data = stack->next->data;
	stack->next->data = tmp;
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_node *stack)
{
	int	tmp;

	if (size_of_stack(stack) <= 1)
		return ;
	tmp = stack->data;
	stack->data = stack->next->data;
	stack->next->data = tmp;
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_node *stack_a, t_node *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}
