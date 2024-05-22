/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/22 12:41:52 by selcyilm      #+#    #+#                 */
/*   Updated: 2024/05/22 12:41:53 by selcyilm      ########   odam.nl         */
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
	error_display(av);
	a = stack_init(a, av);

	while (a != NULL)
	{
		printf("%d\n", a->data);
		a = a->next;
	}
	return (0);
}
