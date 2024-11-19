/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   print_hex.c                                         :+:    :+:           */
/*                                                      +:+                   */
/*   By: selcyilm <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/10/11 12:41:10 by selcyilm       #+#    #+#                */
/*   Updated: 2024/10/11 12:41:31 by selcyilm       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_fd.h"

int	pf_hex_fd(int fd, unsigned int hex, const char c)
{
	return (pf_putpos_fd(fd, hex, c));
}

int	pf_putpos_fd(int fd, unsigned long int arg, const char c)
{
	int	i;
	int	len;

	len = 0;
	i = arg % 16;
	if (arg >= 16)
		len += pf_putpos_fd(fd, arg / 16, c);
	if (i < 10)
		i += 48;
	else
	{
		if (c == 'X')
			i += 55;
		else
			i += 87;
	}
	len += write(fd, &i, 1);
	return (len);
}
