/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/17 21:38:48 by selcyilm      #+#    #+#                 */
/*   Updated: 2024/09/17 21:38:49 by selcyilm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//t_node: data, *next, *prev

//take the first element of the top of b and put it at the top of a
//do nothing if b is emty
void	pa(t_node **dest, t_node **src)
{
	t_node	*node_to_push;

	if (size_of_stack(*src) == 0)
		return ;
	node_to_push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	if (*dest == NULL)
	{
		*dest = node_to_push;
		node_to_push->next = NULL;
	}
	else
	{
		node_to_push->next = *dest;
		node_to_push->next->prev = node_to_push;
		*dest = node_to_push;
	}
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_node **dest, t_node **src)
{
	t_node	*node_to_push;

	if (size_of_stack(*src) == 0)
		return ;
	node_to_push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	if (*dest == NULL)
	{
		*dest = node_to_push;
		node_to_push->next = NULL;
	}
	else
	{
		node_to_push->next = *dest;
		node_to_push->next->prev = node_to_push;
		*dest = node_to_push;
	}
	ft_putstr_fd("pb\n", 1);
}
