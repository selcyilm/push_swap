/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/17 21:39:07 by selcyilm      #+#    #+#                 */
/*   Updated: 2024/09/17 23:15:27 by selcyilm      ########   odam.nl         */
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
	if (!*stack)
		return (false);
	while ((*stack)->next)
	{
		if ((*stack)->data > (*stack)->next->data)
			return (false);
		*stack = (*stack)->next;
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

static t_node	*next_max(t_node *stack, int last_max)
{
	t_node	*next_max;

	next_max = NULL;
	while (stack)
	{
		if (stack->data < last_max && (!next_max || stack->data > next_max->data))
			next_max = stack;
		stack = stack->next;
	}
	return (next_max);
}

void	fill_index(t_node *stack, int size)
{
	t_node *tmp;

	tmp = get_max(stack);
	while (size)
	{
		tmp->index = size--;
		tmp = next_max(stack, tmp->data);
	}
}