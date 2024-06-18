/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/22 12:41:52 by selcyilm      #+#    #+#                 */
/*   Updated: 2024/06/18 13:42:46 by selcyilm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int ac, char **av)
{
	t_node	*a;
	//t_node	*b;

	a = NULL;
	//b = NULL;

	if (ac < 2)
	{
		printf("Error\n");
		exit(1);
	}
	if (ac == 2)
		a = parse_av_if_two(a, av[1]);
	else
		a = parse_av_if_more(a, av);
	print_stack(a);
	stack_free(a);
	return (0);
}
