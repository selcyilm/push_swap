#include <criterion/criterion.h>
#include "../include/push_swap.h"


// Function prototypes
void free_stack(t_node *stack);
t_node *create_node(int data);

// Test case setup
void setup_stack5(t_node **stack, int a, int b, int c, int d, int e)
{
    *stack = create_node(a);
    (*stack)->next = create_node(b);
    (*stack)->next->prev = *stack;
    (*stack)->next->next = create_node(c);
    (*stack)->next->next->prev = (*stack)->next;
    (*stack)->next->next->next = create_node(d);
    (*stack)->next->next->next->prev = (*stack)->next->next;
    (*stack)->next->next->next->next = create_node(e);
    (*stack)->next->next->next->next->prev = (*stack)->next->next->next;
}

Test(sort_five, already_sorted)
{
    t_node *a = NULL;
    t_node *b = NULL;
    setup_stack5(&a, 1, 2, 3, 4, 5);

    sort_five(&a, &b);

    cr_assert_eq(a->data, 1, "Expected top element to be 1");
    cr_assert_eq(a->next->data, 2, "Expected second element to be 2");
    cr_assert_eq(a->next->next->data, 3, "Expected third element to be 3");
    cr_assert_eq(a->next->next->next->data, 4, "Expected fourth element to be 4");
    cr_assert_eq(a->next->next->next->next->data, 5, "Expected fifth element to be 5");

    free_stack(a);
}

Test(sort_five, reversed_order)
{
    t_node *a = NULL;
    t_node *b = NULL;
    setup_stack5(&a, 5, 4, 3, 2, 1);

    sort_five(&a, &b);

    cr_assert_eq(a->data, 1, "Expected top element to be 1");
    cr_assert_eq(a->next->data, 2, "Expected second element to be 2");
    cr_assert_eq(a->next->next->data, 3, "Expected third element to be 3");
    cr_assert_eq(a->next->next->next->data, 4, "Expected fourth element to be 4");
    cr_assert_eq(a->next->next->next->next->data, 5, "Expected fifth element to be 5");

    free_stack(a);
}

Test(sort_five, partially_sorted)
{
    t_node *a = NULL;
    t_node *b = NULL;
    setup_stack5(&a, 2, 1, 5, 4, 3);

    sort_five(&a, &b);

    cr_assert_eq(a->data, 1, "Expected top element to be 1");
    cr_assert_eq(a->next->data, 2, "Expected second element to be 2");
    cr_assert_eq(a->next->next->data, 3, "Expected third element to be 3");
    cr_assert_eq(a->next->next->next->data, 4, "Expected fourth element to be 4");
    cr_assert_eq(a->next->next->next->next->data, 5, "Expected fifth element to be 5");

    free_stack(a);
}

Test(sort_five, first_min)
{
    t_node *a = NULL;
    t_node *b = NULL;
    setup_stack5(&a, 1, 3, 5, 4, 2);

    sort_five(&a, &b);

    cr_assert_eq(a->data, 1, "Expected top element to be 1");
    cr_assert_eq(a->next->data, 2, "Expected second element to be 2");
    cr_assert_eq(a->next->next->data, 3, "Expected third element to be 3");
    cr_assert_eq(a->next->next->next->data, 4, "Expected fourth element to be 4");
    cr_assert_eq(a->next->next->next->next->data, 5, "Expected fifth element to be 5");

    free_stack(a);
}

Test(sort_five, second_min)
{
    t_node *a = NULL;
    t_node *b = NULL;
    setup_stack5(&a, 5, 1, 2, 4, 3);

    sort_five(&a, &b);

    cr_assert_eq(a->data, 1, "Expected top element to be 1");
    cr_assert_eq(a->next->data, 2, "Expected second element to be 2");
    cr_assert_eq(a->next->next->data, 3, "Expected third element to be 3");
    cr_assert_eq(a->next->next->next->data, 4, "Expected fourth element to be 4");
    cr_assert_eq(a->next->next->next->next->data, 5, "Expected fifth element to be 5");

    free_stack(a);
}

Test(sort_five, third_min)
{
    t_node *a = NULL;
    t_node *b = NULL;
    setup_stack5(&a, 5, 4, 1, 2, 3);

    sort_five(&a, &b);

    cr_assert_eq(a->data, 1, "Expected top element to be 1");
    cr_assert_eq(a->next->data, 2, "Expected second element to be 2");
    cr_assert_eq(a->next->next->data, 3, "Expected third element to be 3");
    cr_assert_eq(a->next->next->next->data, 4, "Expected fourth element to be 4");
    cr_assert_eq(a->next->next->next->next->data, 5, "Expected fifth element to be 5");

    free_stack(a);
}

Test(sort_five, fourth_min)
{
    t_node *a = NULL;
    t_node *b = NULL;
    setup_stack5(&a, 5, 4, 3, 1, 2);

    sort_five(&a, &b);

    cr_assert_eq(a->data, 1, "Expected top element to be 1");
    cr_assert_eq(a->next->data, 2, "Expected second element to be 2");
    cr_assert_eq(a->next->next->data, 3, "Expected third element to be 3");
    cr_assert_eq(a->next->next->next->data, 4, "Expected fourth element to be 4");
    cr_assert_eq(a->next->next->next->next->data, 5, "Expected fifth element to be 5");

    free_stack(a);
}

Test(sort_five, large_values)
{
    t_node *a = NULL;
    t_node *b = NULL;
    setup_stack5(&a, 1000000, 5000000, 2000000, 4000000, 3000000);

    sort_five(&a, &b);

    cr_assert_eq(a->data, 1000000, "Expected top element to be 1000000");
    cr_assert_eq(a->next->data, 2000000, "Expected second element to be 2000000");
    cr_assert_eq(a->next->next->data, 3000000, "Expected third element to be 3000000");
    cr_assert_eq(a->next->next->next->data, 4000000, "Expected fourth element to be 4000000");
    cr_assert_eq(a->next->next->next->next->data, 5000000, "Expected fifth element to be 5000000");

    free_stack(a);
}

Test(sort_five, negative_values)
{
    t_node *a = NULL;
    t_node *b = NULL;
    setup_stack5(&a, -5, -4, -3, -2, -1);

    sort_five(&a, &b);

    cr_assert_eq(a->data, -5, "Expected top element to be -5");
    cr_assert_eq(a->next->data, -4, "Expected second element to be -4");
    cr_assert_eq(a->next->next->data, -3, "Expected third element to be -3");
    cr_assert_eq(a->next->next->next->data, -2, "Expected fourth element to be -2");
    cr_assert_eq(a->next->next->next->next->data, -1, "Expected fifth element to be -1");

    free_stack(a);
}
