/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_free.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/20 16:39:56 by selcyilm      #+#    #+#                 */
/*   Updated: 2024/09/20 16:41:24 by selcyilm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	stack_free(t_node **stack)
{
	t_node	*tmp;
	t_node	*current;

	if (!*stack)
		return ;
	current = *stack;
	while (current != NULL)
	{
		tmp = current->next;
		current->data = 0;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}
