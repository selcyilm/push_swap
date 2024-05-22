/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_init.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/22 13:47:55 by selcyilm      #+#    #+#                 */
/*   Updated: 2024/05/22 13:47:56 by selcyilm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_node	*ft_lstlast(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_node	*insert_at_tail(t_node *head, int data)
{
	t_node	*last;
	t_node	*current;

	if (!head)
	{
		head = calloc(1, sizeof(t_node));
		head->data = data;
	}
	else
	{
		current = calloc(1, sizeof(t_node));
		last = ft_lstlast(head);
		last->next = current;
		current->prev = last;
		current->data = data;
	}
	return (head);
}

t_node	*stack_init(t_node *head, char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		head = insert_at_tail(head, atoi(av[i]));
		i++;
	}
	return (head);
}
