/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/22 12:41:52 by selcyilm      #+#    #+#                 */
/*   Updated: 2024/06/21 13:45:10 by selcyilm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
	printf("Stack A: Size: %d\n", size_of_stack(a));
	print_stack(a);
	
	printf("Stack B: Size: %d\n", size_of_stack(b));
	print_stack(b);

	stack_free(&a);
	stack_free(&b);
	return (0);
}
