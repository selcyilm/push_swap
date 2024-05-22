#include "../include/push_swap.h"

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		printf("Error\n");
		exit(1);
	}
	error_display(av);
	return (0);
}
