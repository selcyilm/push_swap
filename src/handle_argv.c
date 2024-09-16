/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_argv.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/18 13:02:46 by selcyilm      #+#    #+#                 */
/*   Updated: 2024/06/21 13:46:23 by selcyilm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_node	*parse_av_if_two(t_node *stack, char *av)
{
	char	**tmp;

	tmp = ft_split(av, ' ');
	int i = 0;
	while (tmp[i] != 0)
	{	
		printf("%d: %s\n",i, tmp[i]);
		i++;
	}
	if (!tmp)
		return (NULL);
	error_display(&stack, tmp, 1);
	stack = stack_init(stack, tmp, 1);
	free_argv(tmp);
	return (stack);
}

t_node	*parse_av_if_more(t_node *stack, char**av)
{
	error_display(&stack, av, 1);
	stack = stack_init(stack, av, 1);
	return (stack);
}

void	free_argv(char **av)
{
	int	i;

	if (!av)
		return ;
	i = 0;
	while (av[i])
		free(av[i++]);
	free(av);
	*av = NULL;
}
