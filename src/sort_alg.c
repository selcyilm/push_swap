/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_alg.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/18 10:56:19 by selcyilm      #+#    #+#                 */
/*   Updated: 2024/09/18 14:08:26 by selcyilm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_three(t_node **stack)
{
	int	max;

	max = get_max(*stack)->data;
	if ((*stack)->data == max)
		ra(stack);
	else if ((*stack)->next->data == max)
		rra(stack);
	if ((*stack)->data > (*stack)->next->data)
		sa(stack);
}

void	sort_five(t_node **a, t_node **b, int size)
{
	int	min;
	int	i;
	int	pushed;

	pushed = 0;
	while (size > 3)
	{
		min = get_min(*a)->data;
		i = get_pos(*a, min);
		if (i <= size-- / 2)
			while ((*a)->data != min)
				ra(a);
		else
			while ((*a)->data != min)
				rra(a);
		pb(b, a);
		pushed++;
	}
	sort_three(a);
	while (pushed--)
		pa(a, b);
}

void	sort_b(t_node **a, t_node **b, int size)
{
	int	max;
	int	i;

	while (size > 1)
	{
		max = get_max(*b)->data;
		i = get_pos(*b, max);
		if (i <= size-- / 2)
			while ((*b)->data != max)
				rb(b);
		else
			while ((*b)->data != max)
				rrb(b);
		pa(a, b);
	}
	pa(a, b);
}

void	sort_all(t_node **a, t_node **b, int size)
{
	int	half;
	int	b_size;
	int	i;

	fill_index(*a, size);
	half = size / 2;
	i = 0;
	if (size % 2)
		i = 1;
	while (size > half)
	{
		if ((*a)->index > half + i)
			ra(a);
		else
		{
			pb(b, a);
			size--;
		}
	}
	b_size = size_of_stack(*b);
	sort_five(a, b, size);
	sort_b(a, b, b_size);
}

void	radix_sort(t_node **a, t_node **b, int size)
{
	int	i;
	int	j;
	int	size_b;
	int	max_bit;

	i = 0;
	max_bit = 0;
	fill_index(*a, size);
	while ((size >> max_bit) != 0)
		max_bit++;
	while (max_bit > 1)
	{
		j = 0;
		while (j++ < size)
		{
			if ((*a)->index >> i & 1)
				ra(a);
			else
				pb(b, a);
		}
		size_b = size_of_stack(*b);
		while (size_b--)
			pa(a, b);
		i++;
	}
}