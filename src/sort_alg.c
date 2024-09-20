/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_alg.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/18 10:56:19 by selcyilm      #+#    #+#                 */
/*   Updated: 2024/09/20 15:34:35 by selcyilm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_three(t_node **stack)
{
	t_node	*bigest_node;

	bigest_node = get_max(*stack);
	if (bigest_node == *stack)
		ra(stack);
	else if ((*stack)->next == bigest_node)
		rra(stack);
	if ((*stack)->data > (*stack)->next->data)
		sa(stack);
}

void	sort_four(t_node **a, t_node **b)
{
	t_node	*min_node;

	min_node = get_min(*a);
	if ((*a)->next == min_node)
		sa(a);
	else if ((*a)->next->next == min_node)
	{
		rra(a);
		rra(a);
	}
	else if ((*a)->next->next->next == min_node)
		rra(a);
	pb(b, a);
	sort_three(a);
	pa(a, b);
}

void	sort_five(t_node **a, t_node **b)
{
	t_node	*min_node;

	min_node = get_min(*a);
	if ((*a)->next == min_node)
		sa(a);
	else if ((*a)->next->next == min_node)
	{
		ra(a);
		ra(a);
	}
	else if ((*a)->next->next->next == min_node)
	{
		rra(a);
		rra(a);
	}
	else if ((*a)->next->next->next->next == min_node)
		rra(a);
	pb(b, a);
	sort_four(a, b);
	pa(a, b);
}

int	check_max_bits(t_node **head)
{
	t_node	*a;
	int		max_bits;
	size_t	tmp_index;

	a = get_max(*head);
	max_bits = 0;
	tmp_index = a->index;
	while (tmp_index != 0)
	{
		tmp_index = tmp_index >> 1;
		max_bits++;
	}
	return (max_bits);
}

void	push_all(t_node **src, t_node **dest)
{
	int	src_len;

	src_len = size_of_stack(*src);
	while (src_len--)
	{
		pa(dest, src);
	}
}
