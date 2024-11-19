/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   print_str.c                                         :+:    :+:           */
/*                                                      +:+                   */
/*   By: selcyilm <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/10/11 12:32:55 by selcyilm       #+#    #+#                */
/*   Updated: 2024/10/11 12:32:56 by selcyilm       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_fd.h"

int	pf_putchar_fd(int fd, int c)
{
	write(fd, &c, 1);
	return (1);
}

int	pf_putstr_fd(int fd, const char *s)
{
	if (!s)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	write(fd, s, pf_strlen_fd(s));
	return (pf_strlen_fd(s));
}
