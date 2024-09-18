/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/22 12:41:52 by selcyilm      #+#    #+#                 */
/*   Updated: 2024/09/18 19:45:44 by selcyilm      ########   odam.nl         */
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
	else if (size <= 9)
		sort_five(a, b, size);
	else if (size <= 150)
		sort_all(a, b, size);
	else if (size > 150)
		radix_sort(a, b, size);
}

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;

	if (ac < 2)
	{
		printf("Error\n");
		exit(1);
	}
	if (ac == 2)
		a = parse_av_if_two(a, av[1]);
	else
		a = parse_av_if_more(a, av);
	/*printf("-------------A Before----------\n");
	print_stack(a);*/

	if (!is_stack_sorted(&a))
		push_swap(&a, &b);
	/*printf("-------------A----------\n");
	print_stack(a);
	printf("-------------B----------\n");
	print_stack(b);*/
	stack_free(&a);
	stack_free(&b);
	return (0);
}
