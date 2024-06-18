/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_handle.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/22 12:41:48 by selcyilm      #+#    #+#                 */
/*   Updated: 2024/06/18 15:09:35 by selcyilm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

bool	check_non_numeric(char **str, int start_pos)
{
	int	i;

	i = start_pos;
	
	while (str[i])
	{
		if (!check_string(str[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	check_string(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	check_duplicate_limit(char **str, int start_pos)
{
	int	i;
	int	j;

	i = start_pos;
	while (str[i])
	{
		if (atol(str[i]) < INT_MIN || atol(str[i]) > INT_MAX)
			return (false);
		j = i + 1;
		while (str[j])
		{
			if (atoi(str[j]) == atoi(str[i]))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

void	error_display(t_node *a, char **av, int start_pos)
{
	if (!check_duplicate_limit(av, start_pos) || !check_non_numeric(av, start_pos))
	{
		stack_free(a);
		if (start_pos == 0)
			free_argv(av);
		write(1, "Error\n", 6);
		exit(1);
	}
}
