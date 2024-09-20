/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill_index.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/20 15:35:34 by selcyilm      #+#    #+#                 */
/*   Updated: 2024/09/20 15:43:40 by selcyilm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_node	*next_max(t_node *stack, int last_max)
{
	t_node	*next_max;

	next_max = NULL;
	while (stack)
	{
		if (stack->data < last_max && \
			(!next_max || stack->data > next_max->data))
			next_max = stack;
		stack = stack->next;
	}
	return (next_max);
}

void	fill_index(t_node *stack, int size)
{
	t_node	*tmp;

	tmp = get_max(stack);
	while (size)
	{
		tmp->index = size--;
		tmp = next_max(stack, tmp->data);
	}
}

int	get_pos(t_node *stack, int target)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->data == target)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (-1);
}
