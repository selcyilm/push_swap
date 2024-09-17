#include <criterion/criterion.h>
#include "../include/push_swap.h"

t_node *create_node(int data);
void free_stack(t_node *stack);

// Test Case 1: Reverse rotate stack_a using rra (last element becomes the first)
Test(stack_operations, test_rra_reverse_rotate) {
    t_node *stack_a = create_node(1);
    stack_a->next = create_node(2);
    stack_a->next->prev = stack_a;
    stack_a->next->next = create_node(3);
    stack_a->next->next->prev = stack_a->next;

    rra(&stack_a);

    cr_expect_eq(stack_a->data, 3, "After rra, top of stack_a should be 3.");
    cr_expect_eq(stack_a->next->data, 1, "After rra, second element of stack_a should be 1.");
    cr_expect_eq(stack_a->next->next->data, 2, "After rra, third element of stack_a should be 2.");

    free_stack(stack_a);
}

// Test Case 2: Reverse rotate stack_b using rrb (last element becomes the first)
Test(stack_operations, test_rrb_reverse_rotate) {
    t_node *stack_b = create_node(4);
    stack_b->next = create_node(5);
    stack_b->next->prev = stack_b;
    stack_b->next->next = create_node(6);
    stack_b->next->next->prev = stack_b->next;

    rrb(&stack_b);

    cr_expect_eq(stack_b->data, 6, "After rrb, top of stack_b should be 6.");
    cr_expect_eq(stack_b->next->data, 4, "After rrb, second element of stack_b should be 4.");
    cr_expect_eq(stack_b->next->next->data, 5, "After rrb, third element of stack_b should be 5.");

    free_stack(stack_b);
}

// Test Case 3: Perform rra on a stack with only one element (should do nothing)
Test(stack_operations, test_rra_single_element) {
    t_node *stack_a = create_node(10);

    rra(&stack_a);

    cr_expect_eq(stack_a->data, 10, "After rra, top of stack_a should still be 10 (unchanged).");

    free_stack(stack_a);
}

// Test Case 4: Perform rrb on a stack with only one element (should do nothing)
Test(stack_operations, test_rrb_single_element) {
    t_node *stack_b = create_node(7);

    rrb(&stack_b);

    cr_expect_eq(stack_b->data, 7, "After rrb, top of stack_b should still be 7 (unchanged).");

    free_stack(stack_b);
}

// Test Case 5: Perform rra on an empty stack (should do nothing)
Test(stack_operations, test_rra_empty_stack) {
    t_node *stack_a = NULL;

    rra(&stack_a);

    cr_assert_null(stack_a, "After rra on an empty stack, stack_a should remain NULL.");
}

// Test Case 6: Perform rrb on an empty stack (should do nothing)
Test(stack_operations, test_rrb_empty_stack) {
    t_node *stack_b = NULL;

    rrb(&stack_b);

    cr_assert_null(stack_b, "After rrb on an empty stack, stack_b should remain NULL.");
}

// Test Case 7: Perform rrr to reverse rotate both stacks a and b
Test(stack_operations, test_rrr_reverse_rotate_both_stacks) {
    t_node *stack_a = create_node(1);
    stack_a->next = create_node(2);
    stack_a->next->prev = stack_a;
    stack_a->next->next = create_node(3);
    stack_a->next->next->prev = stack_a->next;

    t_node *stack_b = create_node(4);
    stack_b->next = create_node(5);
    stack_b->next->prev = stack_b;
    stack_b->next->next = create_node(6);
    stack_b->next->next->prev = stack_b->next;

    rrr(&stack_a, &stack_b);

    // Check stack_a after rrr
    cr_expect_eq(stack_a->data, 3, "After rrr, top of stack_a should be 3.");
    cr_expect_eq(stack_a->next->data, 1, "After rrr, second element of stack_a should be 1.");
    cr_expect_eq(stack_a->next->next->data, 2, "After rrr, third element of stack_a should be 2.");

    // Check stack_b after rrr
    cr_expect_eq(stack_b->data, 6, "After rrr, top of stack_b should be 6.");
    cr_expect_eq(stack_b->next->data, 4, "After rrr, second element of stack_b should be 4.");
    cr_expect_eq(stack_b->next->next->data, 5, "After rrr, third element of stack_b should be 5.");

    free_stack(stack_a);
    free_stack(stack_b);
}

// Test Case 8: Perform rrr on one empty and one non-empty stack (should reverse rotate the non-empty one)
Test(stack_operations, test_rrr_one_empty_stack) {
    t_node *stack_a = NULL;

    t_node *stack_b = create_node(11);
    stack_b->next = create_node(12);
    stack_b->next->prev = stack_b;

    rrr(&stack_a, &stack_b);

    cr_assert_null(stack_a, "After rrr, stack_a should remain NULL.");
    cr_expect_eq(stack_b->data, 12, "After rrr, top of stack_b should be 12.");
    cr_expect_eq(stack_b->next->data, 11, "After rrr, second element of stack_b should be 11.");

    free_stack(stack_b);
}

// Test Case 9: Perform rrr on both empty stacks (should do nothing)
Test(stack_operations, test_rrr_both_empty_stacks) {
    t_node *stack_a = NULL;
    t_node *stack_b = NULL;

    rrr(&stack_a, &stack_b);

    cr_assert_null(stack_a, "After rrr on both empty stacks, stack_a should remain NULL.");
    cr_assert_null(stack_b, "After rrr on both empty stacks, stack_b should remain NULL.");
}
