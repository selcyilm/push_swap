#include <criterion/criterion.h>
#include "../include/push_swap.h"

t_node *create_node(int data);
void free_stack(t_node *stack);

// Test Case 1: Rotate stack_a using ra (first element becomes the last)
Test(stack_operations, test_ra_rotate) {
    t_node *stack_a = create_node(1);
    stack_a->next = create_node(2);
    stack_a->next->prev = stack_a;
    stack_a->next->next = create_node(3);
    stack_a->next->next->prev = stack_a->next;

    ra(&stack_a);

    cr_expect_eq(stack_a->data, 2, "After ra, top of stack_a should be 2.");
    cr_expect_eq(stack_a->next->data, 3, "After ra, second element of stack_a should be 3.");
    cr_expect_eq(stack_a->next->next->data, 1, "After ra, last element of stack_a should be 1.");

    free_stack(stack_a);
}

// Test Case 2: Rotate stack_b using rb (first element becomes the last)
Test(stack_operations, test_rb_rotate) {
    t_node *stack_b = create_node(4);
    stack_b->next = create_node(5);
    stack_b->next->prev = stack_b;
    stack_b->next->next = create_node(6);
    stack_b->next->next->prev = stack_b->next;

    rb(&stack_b);

    cr_expect_eq(stack_b->data, 5, "After rb, top of stack_b should be 5.");
    cr_expect_eq(stack_b->next->data, 6, "After rb, second element of stack_b should be 6.");
    cr_expect_eq(stack_b->next->next->data, 4, "After rb, last element of stack_b should be 4.");

    free_stack(stack_b);
}

// Test Case 3: Perform ra on a stack with only one element (should do nothing)
Test(stack_operations, test_ra_single_element) {
    t_node *stack_a = create_node(10);

    ra(&stack_a);

    cr_expect_eq(stack_a->data, 10, "After ra, top of stack_a should still be 10 (unchanged).");

    free_stack(stack_a);
}

// Test Case 4: Perform rb on a stack with only one element (should do nothing)
Test(stack_operations, test_rb_single_element) {
    t_node *stack_b = create_node(7);

    rb(&stack_b);

    cr_expect_eq(stack_b->data, 7, "After rb, top of stack_b should still be 7 (unchanged).");

    free_stack(stack_b);
}

// Test Case 5: Perform ra on an empty stack (should do nothing)
Test(stack_operations, test_ra_empty_stack) {
    t_node *stack_a = NULL;

    ra(&stack_a);
    cr_assert_null(stack_a, "After ra on an empty stack, stack_a should remain NULL.");
}

// Test Case 6: Perform rb on an empty stack (should do nothing)
Test(stack_operations, test_rb_empty_stack) {
    t_node *stack_b = NULL;

    rb(&stack_b);

    cr_assert_null(stack_b, "After rb on an empty stack, stack_b should remain NULL.");
}

// Test Case 7: Perform rr to rotate both stacks a and b
Test(stack_operations, test_rr_rotate_both_stacks) {
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

    rr(&stack_a, &stack_b);

    // Check stack_a after rr
    cr_expect_eq(stack_a->data, 2, "After rr, top of stack_a should be 2.");
    cr_expect_eq(stack_a->next->data, 3, "After rr, second element of stack_a should be 3.");
    cr_expect_eq(stack_a->next->next->data, 1, "After rr, last element of stack_a should be 1.");

    // Check stack_b after rr
    cr_expect_eq(stack_b->data, 5, "After rr, top of stack_b should be 5.");
    cr_expect_eq(stack_b->next->data, 6, "After rr, second element of stack_b should be 6.");
    cr_expect_eq(stack_b->next->next->data, 4, "After rr, last element of stack_b should be 4.");

    free_stack(stack_a);
    free_stack(stack_b);
}

// Test Case 8: Perform rr on one empty and one non-empty stack (should rotate the non-empty one)
Test(stack_operations, test_rr_one_empty_stack) {
    t_node *stack_a = NULL;

    t_node *stack_b = create_node(11);
    stack_b->next = create_node(12);
    stack_b->next->prev = stack_b;

    rr(&stack_a, &stack_b);

    cr_assert_null(stack_a, "After rr, stack_a should remain NULL.");
    cr_expect_eq(stack_b->data, 12, "After rr, top of stack_b should be 12.");
    cr_expect_eq(stack_b->next->data, 11, "After rr, second element of stack_b should be 11.");

    free_stack(stack_b);
}

// Test Case 9: Perform rr on both empty stacks (should do nothing)
Test(stack_operations, test_rr_both_empty_stacks) {
    t_node *stack_a = NULL;
    t_node *stack_b = NULL;

    rr(&stack_a, &stack_b);

    cr_assert_null(stack_a, "After rr on both empty stacks, stack_a should remain NULL.");
    cr_assert_null(stack_b, "After rr on both empty stacks, stack_b should remain NULL.");
}
