/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   print_unsigned.c                                    :+:    :+:           */
/*                                                      +:+                   */
/*   By: selcyilm <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/10/11 12:38:41 by selcyilm       #+#    #+#                */
/*   Updated: 2024/10/11 12:38:53 by selcyilm       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_fd.h"

int	pf_put_u_fd(int fd, unsigned int nb)
{
	int				i;
	unsigned int	n;

	i = 0;
	if (nb >= 10)
	{
		i += pf_put_u_fd(fd, nb / 10);
	}
	n = nb % 10 + 48;
	i += write(fd, &n, 1);
	return (i);
}