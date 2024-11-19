/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   print_digit.c                                       :+:    :+:           */
/*                                                      +:+                   */
/*   By: selcyilm <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/10/11 12:37:23 by selcyilm       #+#    #+#                */
/*   Updated: 2024/10/11 12:37:38 by selcyilm       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_fd.h"

int	pf_putnbr_fd(int fd, int nb)
{
	int	i;
	int	n;

	i = 0;
	if (nb == -2147483648)
		return (pf_putstr_fd(fd, "-2147483648"));
	if (nb < 0)
	{
		i += write(fd, "-", 1);
		nb *= -1;
	}
	if (nb >= 10)
	{
		i += pf_putnbr_fd(fd, nb / 10);
	}
	n = nb % 10 + 48;
	i += write(fd, &n, 1);
	return (i);
}
