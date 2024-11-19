/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_printf_main.c                                    :+:    :+:           */
/*                                                      +:+                   */
/*   By: selcyilm <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/10/10 18:22:30 by selcyilm       #+#    #+#                */
/*   Updated: 2024/10/10 18:22:33 by selcyilm       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_fd.h"

int	ft_printf_fd(int fd, const	char *s, ...)
{
	int		i;
	int		len;
	va_list	arg;

	i = 0;
	len = 0;
	va_start(arg, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			len += match_arg_fd(fd, arg, s[i]);
		}
		else
		{
			write(fd, &s[i], 1);
			if (s[i])
				len++;
		}
		i++;
	}
	va_end(arg);
	return (len);
}

int	match_arg_fd(int fd, va_list arg, const char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len = pf_putchar_fd(fd, va_arg(arg, int));
	if (c == 's')
		len = pf_putstr_fd(fd, va_arg(arg, char *));
	if (c == 'p')
		len = pf_putptr_fd(fd, va_arg(arg, unsigned long int));
	if (c == 'd' || c == 'i')
		len = pf_putnbr_fd(fd, va_arg(arg, int));
	if (c == 'u')
		len = pf_put_u_fd(fd, va_arg(arg, unsigned int));
	if (c == 'x' || c == 'X')
		len = pf_hex_fd(fd, va_arg(arg, unsigned int), c);
	if (c == '%')
		len = pf_putchar_fd(fd, '%');
	return (len);
}
