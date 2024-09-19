#include <criterion/criterion.h>
#include "../include/push_swap.h"

void free_stack(t_node *stack);
t_node *create_node(int data);

// Test case setup
void setup_stack(t_node **stack, int a, int b, int c)
{
    *stack = create_node(a);
    (*stack)->next = create_node(b);
    (*stack)->next->prev = *stack;
    (*stack)->next->next = create_node(c);
    (*stack)->next->next->prev = (*stack)->next;
}

// Test cases
Test(sort_three, already_sorted)
{
    t_node *stack = NULL;
    setup_stack(&stack, 1, 2, 3);

    sort_three(&stack);

    cr_assert_eq(stack->data, 1, "Expected top element to be 1");
    cr_assert_eq(stack->next->data, 2, "Expected second element to be 2");
    cr_assert_eq(stack->next->next->data, 3, "Expected third element to be 3");

	free_stack(stack);
}

Test(sort_three, reversed_order)
{
    t_node *stack = NULL;
    setup_stack(&stack, 3, 2, 1);

    sort_three(&stack);

    cr_assert_eq(stack->data, 1, "Expected top element to be 1");
    cr_assert_eq(stack->next->data, 2, "Expected second element to be 2");
    cr_assert_eq(stack->next->next->data, 3, "Expected third element to be 3");
	free_stack(stack);
}

Test(sort_three, partially_sorted)
{
    t_node *stack = NULL;
    setup_stack(&stack, 2, 1, 3);

    sort_three(&stack);

    cr_assert_eq(stack->data, 1, "Expected top element to be 1");
    cr_assert_eq(stack->next->data, 2, "Expected second element to be 2");
    cr_assert_eq(stack->next->next->data, 3, "Expected third element to be 3");
	free_stack(stack);
}

Test(sort_three, another_configuration)
{
    t_node *stack = NULL;
    setup_stack(&stack, 2, 3, 1);

    sort_three(&stack);

    cr_assert_eq(stack->data, 1, "Expected top element to be 1");
    cr_assert_eq(stack->next->data, 2, "Expected second element to be 2");
    cr_assert_eq(stack->next->next->data, 3, "Expected third element to be 3");
	free_stack(stack);
}