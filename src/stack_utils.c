/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/17 21:39:07 by selcyilm      #+#    #+#                 */
/*   Updated: 2024/09/20 15:43:34 by selcyilm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	size_of_stack(t_node *node)
{
	int	i;

	i = 0;
	while (node != 0)
	{
		i++;
		node = node->next;
	}
	return (i);
}

bool	is_stack_sorted(t_node **stack)
{
	t_node	*current;

	if (!*stack || !stack)
		return (false);
	current = *stack;
	while (current->next)
	{
		if (current->data > current->next->data)
			return (false);
		current = current->next;
	}
	return (true);
}

t_node	*get_min(t_node *stack)
{
	t_node	*min;

	min = stack;
	while (stack)
	{
		if (min->data > stack->data)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

t_node	*get_max(t_node *stack)
{
	t_node	*max;

	max = stack;
	while (stack)
	{
		if (max->data < stack->data)
			max = stack;
		stack = stack->next;
	}
	return (max);
}
