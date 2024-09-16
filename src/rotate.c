#include "../include/push_swap.h"

//rotate: shift all up elements of stact x 
//by one, the first element become the last one

static	void	rotate(t_node **stack)
{
	t_node	*last;
	int		len;

	len = size_of_stack(*stack);
	if (len == 1 || stack == NULL)
		return ;
	last = ft_lastnode(*stack);
	last->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last->next->prev = last;
	last->next->next = NULL;
}

void	ra(t_node **a)
{
	rotate(a);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_node **b)
{
	rotate(b);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_node **a, t_node **b)
{
	rotate(a);
	rotate(b);
	ft_putstr_fd("rr\n", 1);
}
