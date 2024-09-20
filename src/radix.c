/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radix.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/20 15:33:53 by selcyilm      #+#    #+#                 */
/*   Updated: 2024/09/20 15:34:24 by selcyilm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	radix_sort(t_node **a, t_node **b)
{
	int	max_bits;
	int	current_bit;
	int	current_element;
	int	a_len;

	current_bit = 0;
	current_element = 0;
	a_len = size_of_stack(*a);
	max_bits = check_max_bits(a);
	while (current_bit < max_bits)
	{
		while (current_element < a_len)
		{
			if (!(((*a)->index) >> current_bit & 1))
				pb(b, a);
			else
				ra(a);
			current_element++;
		}
		current_element = 0;
		push_all(b, a);
		current_bit++;
	}
}
