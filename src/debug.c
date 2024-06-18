/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   debug.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/18 13:00:07 by selcyilm      #+#    #+#                 */
/*   Updated: 2024/06/18 13:00:42 by selcyilm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_stack(t_node *stack)
{
	t_node *current;
	if (!stack)
		return ;
	current = stack;
	while (current)
	{
		printf("%d\n", current->data);
		current = current->next;
	}
}