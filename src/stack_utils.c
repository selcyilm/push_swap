/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/17 21:39:07 by selcyilm      #+#    #+#                 */
/*   Updated: 2024/09/17 21:39:08 by selcyilm      ########   odam.nl         */
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
