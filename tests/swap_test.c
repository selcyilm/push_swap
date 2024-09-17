#include <criterion/criterion.h>
#include "../include/push_swap.h"

// Helper function to initialize a stack node
/*t_node *create_node(int data) {
    t_node *new_node = malloc(sizeof(t_node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

// Helper function to free the entire stack
void free_stack(t_node *stack) {
    t_node *temp;
    while (stack) {
        temp = stack;
        stack = stack->next;
        free(temp);
    }
}*/

t_node *create_node(int data);
void free_stack(t_node *stack);

// Test Case 1: Swap first two elements of stack_a using sa
Test(stack_operations, test_sa_swap) {
    t_node *stack_a = create_node(1);
    stack_a->next = create_node(2);
    stack_a->next->prev = stack_a;

    sa(stack_a);

    cr_expect_eq(stack_a->data, 2, "After sa, top of stack_a should be 2.");
    cr_expect_eq(stack_a->next->data, 1, "After sa, second element of stack_a should be 1.");

    free_stack(stack_a);
}

// Test Case 2: Swap first two elements of stack_b using sb
Test(stack_operations, test_sb_swap) {
    t_node *stack_b = create_node(5);
    stack_b->next = create_node(6);
    stack_b->next->prev = stack_b;

    sb(stack_b);

    cr_expect_eq(stack_b->data, 6, "After sb, top of stack_b should be 6.");
    cr_expect_eq(stack_b->next->data, 5, "After sb, second element of stack_b should be 5.");

    free_stack(stack_b);
}

// Test Case 3: Perform sa on a stack with only one element (should do nothing)
Test(stack_operations, test_sa_single_element) {
    t_node *stack_a = create_node(10);

    sa(stack_a);

    cr_expect_eq(stack_a->data, 10, "After sa, top of stack_a should still be 10 (unchanged).");

    free_stack(stack_a);
}

// Test Case 4: Perform sb on a stack with only one element (should do nothing)
Test(stack_operations, test_sb_single_element) {
    t_node *stack_b = create_node(8);

    sb(stack_b);

    cr_expect_eq(stack_b->data, 8, "After sb, top of stack_b should still be 8 (unchanged).");

    free_stack(stack_b);
}

// Test Case 5: Perform sa on an empty stack (should do nothing)
Test(stack_operations, test_sa_empty_stack) {
    t_node *stack_a = NULL;

    sa(stack_a);

    cr_assert_null(stack_a, "After sa on an empty stack, stack_a should remain NULL.");
}

// Test Case 6: Perform sb on an empty stack (should do nothing)
Test(stack_operations, test_sb_empty_stack) {
    t_node *stack_b = NULL;

    sb(stack_b);

    cr_assert_null(stack_b, "After sb on an empty stack, stack_b should remain NULL.");
}

// Test Case 7: Perform ss on non-empty stack_a and stack_b
Test(stack_operations, test_ss_swap_both_stacks) {
    t_node *stack_a = create_node(3);
    stack_a->next = create_node(4);
    stack_a->next->prev = stack_a;

    t_node *stack_b = create_node(7);
    stack_b->next = create_node(9);
    stack_b->next->prev = stack_b;

    ss(stack_a, stack_b);

    cr_expect_eq(stack_a->data, 4, "After ss, top of stack_a should be 4.");
    cr_expect_eq(stack_a->next->data, 3, "After ss, second element of stack_a should be 3.");
    cr_expect_eq(stack_b->data, 9, "After ss, top of stack_b should be 9.");
    cr_expect_eq(stack_b->next->data, 7, "After ss, second element of stack_b should be 7.");

    free_stack(stack_a);
    free_stack(stack_b);
}

// Test Case 8: Perform ss on one empty and one non-empty stack (should swap the non-empty one)
Test(stack_operations, test_ss_one_empty_stack) {
    t_node *stack_a = NULL;

    t_node *stack_b = create_node(10);
    stack_b->next = create_node(12);
    stack_b->next->prev = stack_b;

    ss(stack_a, stack_b);

    cr_assert_null(stack_a, "After ss, stack_a should remain NULL.");
    cr_expect_eq(stack_b->data, 12, "After ss, top of stack_b should be 12.");
    cr_expect_eq(stack_b->next->data, 10, "After ss, second element of stack_b should be 10.");

    free_stack(stack_b);
}

// Test Case 9: Perform ss on both empty stacks (should do nothing)
Test(stack_operations, test_ss_both_empty_stacks) {
    t_node *stack_a = NULL;
    t_node *stack_b = NULL;

    ss(stack_a, stack_b);

    cr_assert_null(stack_a, "After ss on both empty stacks, stack_a should remain NULL.");
    cr_assert_null(stack_b, "After ss on both empty stacks, stack_b should remain NULL.");
}
