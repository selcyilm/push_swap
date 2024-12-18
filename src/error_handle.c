/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_handle.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/20 15:37:52 by selcyilm      #+#    #+#                 */
/*   Updated: 2024/09/20 16:39:50 by selcyilm      ########   odam.nl         */
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
	if (!str || ft_strlen(str) == 0)
		return (true);
	if ((str[i] == '-' || str[i] == '+') && ft_strlen(str) != 1)
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
		if (ft_atol(str[i]) < INT_MIN || ft_atol(str[i]) > INT_MAX)
			return (false);
		j = i + 1;
		while (str[j])
		{
			if (ft_atoi(str[j]) == ft_atoi(str[i]))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

void	error_display(t_node **a, char **av, int start_pos)
{
	if (!check_duplicate_limit(av, start_pos) \
		|| !check_non_numeric(av, start_pos))
	{
		if (start_pos == 0)
		{
			stack_free(a);
			free_argv(av);
		}
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
}

bool	check_space(char *av)
{
	int		i;
	bool	flag;

	flag = true;
	i = 0;
	if (!av)
		return (false);
	while (av[i] == ' ')
	{
		flag = false;
		i++;
	}
	return (flag);
}
