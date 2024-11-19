/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/22 12:41:52 by selcyilm      #+#    #+#                 */
/*   Updated: 2024/09/20 16:38:43 by selcyilm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_swap(t_node **a, t_node **b)
{
	int	size;

	size = size_of_stack(*a);
	if (size == 2)
		sa(a);
	else if (size == 3)
		sort_three(a);
	else if (size == 4)
		sort_four(a, b);
	else if (size == 5)
		sort_five(a, b);
	else
		radix_sort(a, b);
}

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (ac < 2)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	if (ac == 2)
	{
		if (!check_space(av[1]) || ft_strlen(av[1]) == 0)
			return (0);
		a = parse_av_if_two(a, av[1]);
	}
	else
		a = parse_av_if_more(a, av);
	fill_index(a, size_of_stack(a));
	if (!is_stack_sorted(&a))
		push_swap(&a, &b);
	stack_free(&a);
	stack_free(&b);
	return (0);
}
