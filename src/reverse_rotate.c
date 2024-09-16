#include "../include/push_swap.h"

// * * * * last

static	void	reverse_rotate(t_node **stack)
{
	t_node	*last;
	int		len;

	len = size_of_stack(*stack);
	if (*stack == NULL || len == 1)
		return ;
	last = ft_lastnode(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

void	rra(t_node **a)
{
	reverse_rotate(a);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_node **b)
{
	reverse_rotate(b);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_node **a, t_node **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_putstr_fd("rrr\n", 1);
}
