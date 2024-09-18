#include <stdio.h>

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		int	i;

		i = 1;
		while (av[i])
			printf("%s",av[i++]);
	}
}