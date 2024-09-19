
#include <criterion/criterion.h>
#include "../include/push_swap.h"

// Function prototypes
void free_stack(t_node *stack);
t_node *create_node(int data);


// Test case setup
void setup_stack4(t_node **stack, int a, int b, int c, int d)
{
    *stack = create_node(a);
    (*stack)->next = create_node(b);
    (*stack)->next->prev = *stack;
    (*stack)->next->next = create_node(c);
    (*stack)->next->next->prev = (*stack)->next;
    (*stack)->next->next->next = create_node(d);
    (*stack)->next->next->next->prev = (*stack)->next->next;
}

Test(sort_four, already_sorted)
{
    t_node *a = NULL;
    t_node *b = NULL;
    setup_stack4(&a, 1, 2, 3, 4);

    sort_four(&a, &b);

    cr_assert_eq(a->data, 1, "Expected top element to be 1");
    cr_assert_eq(a->next->data, 2, "Expected second element to be 2");
    cr_assert_eq(a->next->next->data, 3, "Expected third element to be 3");
    cr_assert_eq(a->next->next->next->data, 4, "Expected fourth element to be 4");

    free_stack(a);
}

Test(sort_four, reversed_order)
{
    t_node *a = NULL;
    t_node *b = NULL;
    setup_stack4(&a, 4, 3, 2, 1);

    sort_four(&a, &b);
    cr_assert_eq(a->data, 1, "Expected top element to be 1");
    cr_assert_eq(a->next->data, 2, "Expected second element to be 2");
    cr_assert_eq(a->next->next->data, 3, "Expected third element to be 3");
    cr_assert_eq(a->next->next->next->data, 4, "Expected fourth element to be 4");

    free_stack(a);
}

Test(sort_four, partially_sorted)
{
    t_node *a = NULL;
    t_node *b = NULL;
    setup_stack4(&a, 2, 1, 4, 3);

    sort_four(&a, &b);

    cr_assert_eq(a->data, 1, "Expected top element to be 1");
    cr_assert_eq(a->next->data, 2, "Expected second element to be 2");
    cr_assert_eq(a->next->next->data, 3, "Expected third element to be 3");
    cr_assert_eq(a->next->next->next->data, 4, "Expected fourth element to be 4");

    free_stack(a);
}

Test(sort_four, first_two_min)
{
    t_node *a = NULL;
    t_node *b = NULL;
    setup_stack4(&a, 1, 2, 4, 3);

    sort_four(&a, &b);

    cr_assert_eq(a->data, 1, "Expected top element to be 1");
    cr_assert_eq(a->next->data, 2, "Expected second element to be 2");
    cr_assert_eq(a->next->next->data, 3, "Expected third element to be 3");
    cr_assert_eq(a->next->next->next->data, 4, "Expected fourth element to be 4");

    free_stack(a);
}

Test(sort_four, second_min)
{
    t_node *a = NULL;
    t_node *b = NULL;
    setup_stack4(&a, 4, 1, 2, 3);

    sort_four(&a, &b);

    cr_assert_eq(a->data, 1, "Expected top element to be 1");
    cr_assert_eq(a->next->data, 2, "Expected second element to be 2");
    cr_assert_eq(a->next->next->data, 3, "Expected third element to be 3");
    cr_assert_eq(a->next->next->next->data, 4, "Expected fourth element to be 4");

    free_stack(a);
}

Test(sort_four, third_min)
{
    t_node *a = NULL;
    t_node *b = NULL;
    setup_stack4(&a, 4, 3, 1, 2);

    sort_four(&a, &b);

    cr_assert_eq(a->data, 1, "Expected top element to be 1");
    cr_assert_eq(a->next->data, 2, "Expected second element to be 2");
    cr_assert_eq(a->next->next->data, 3, "Expected third element to be 3");
    cr_assert_eq(a->next->next->next->data, 4, "Expected fourth element to be 4");

    free_stack(a);
}

Test(sort_four, all_elements_same)
{
    t_node *a = NULL;
    t_node *b = NULL;
    setup_stack4(&a, 1, 1, 1, 1);

    sort_four(&a, &b);

    cr_assert_eq(a->data, 1, "Expected top element to be 1");
    cr_assert_eq(a->next->data, 1, "Expected second element to be 1");
    cr_assert_eq(a->next->next->data, 1, "Expected third element to be 1");
    cr_assert_eq(a->next->next->next->data, 1, "Expected fourth element to be 1");

    free_stack(a);
}

Test(sort_four, large_values)
{
    t_node *a = NULL;
    t_node *b = NULL;
    setup_stack4(&a, 1000000, 5000000, 2000000, 4000000);

    sort_four(&a, &b);

    cr_assert_eq(a->data, 1000000, "Expected top element to be 1000000");
    cr_assert_eq(a->next->data, 2000000, "Expected second element to be 2000000");
    cr_assert_eq(a->next->next->data, 4000000, "Expected third element to be 4000000");
    cr_assert_eq(a->next->next->next->data, 5000000, "Expected fourth element to be 5000000");

    free_stack(a);
}

Test(sort_four, negative_values)
{
    t_node *a = NULL;
    t_node *b = NULL;
    setup_stack4(&a, -1, -3, -2, -4);

    sort_four(&a, &b);

    cr_assert_eq(a->data, -4, "Expected top element to be -4");
    cr_assert_eq(a->next->data, -3, "Expected second element to be -3");
    cr_assert_eq(a->next->next->data, -2, "Expected third element to be -2");
    cr_assert_eq(a->next->next->next->data, -1, "Expected fourth element to be -1");

    free_stack(a);
}

Test(sort_four, mixed_values)
{
    t_node *a = NULL;
    t_node *b = NULL;
    setup_stack4(&a, 10, -10, 0, 5);

    sort_four(&a, &b);

    cr_assert_eq(a->data, -10, "Expected top element to be -10");
    cr_assert_eq(a->next->data, 0, "Expected second element to be 0");
    cr_assert_eq(a->next->next->data, 5, "Expected third element to be 5");
    cr_assert_eq(a->next->next->next->data, 10, "Expected fourth element to be 10");

    free_stack(a);
}