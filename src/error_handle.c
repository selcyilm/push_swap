/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_handle.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/22 12:41:48 by selcyilm      #+#    #+#                 */
/*   Updated: 2024/06/18 11:16:28 by selcyilm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

bool	check_non_numeric(char **str)
{
	int	i;
	int	j;

	i = 1;
	
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (!isdigit(str[i][j]))
				if (str[i][j] != '-' && j != 0)
					return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	check_duplicate_limit(char **str)
{
	int	i;
	int	j;

	i = 1;
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

void	error_display(char **av)
{
	if (!check_duplicate_limit(av) || !check_non_numeric(av))
	{
		write(1, "Error\n", 6);
		exit(1);
	}
}
