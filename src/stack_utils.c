#include "../include/push_swap.h"

int	size_of_stack(t_node *node)
{
	int	i;

	i = 0;
	while (node != 0)
	{
		i++;
		node = node->next;
	}
	return (i);
}
