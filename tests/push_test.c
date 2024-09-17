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

// Test Case 1: Move the top element from non-empty b to empty a using pa
Test(stack_operations, test_pa_move_to_empty_a) {
    t_node *stack_a = NULL;
    t_node *stack_b = create_node(3);
    stack_b->next = create_node(2);
    stack_b->next->prev = stack_b;
    stack_b->next->next = create_node(1);
    stack_b->next->next->prev = stack_b->next;

    pa(&stack_a, &stack_b);

    cr_expect_eq(stack_a->data, 3, "Top of stack_a should be 3.");
    cr_expect_eq(stack_b->data, 2, "Top of stack_b should now be 2.");
    cr_expect_null(stack_b->prev, "The previous pointer of the top of stack_b should be NULL.");

    free_stack(stack_a);
    free_stack(stack_b);
}

// Test Case 2: Move the top element from non-empty a to empty b using pb
Test(stack_operations, test_pb_move_to_empty_b) {
    t_node *stack_a = create_node(5);
    stack_a->next = create_node(4);
    stack_a->next->prev = stack_a;
    t_node *stack_b = NULL;

    pb(&stack_b, &stack_a);

    cr_expect_eq(stack_b->data, 5, "Top of stack_b should be 5.");
    cr_expect_eq(stack_a->data, 4, "Top of stack_a should now be 4.");
    cr_expect_null(stack_a->prev, "The previous pointer of the top of stack_a should be NULL.");

    free_stack(stack_a);
    free_stack(stack_b);
}

// Test Case 3: Move the top element from non-empty b to non-empty a using pa
Test(stack_operations, test_pa_move_to_non_empty_a) {
    t_node *stack_a = create_node(7);
    stack_a->next = create_node(6);
    stack_a->next->prev = stack_a;

    t_node *stack_b = create_node(3);
    stack_b->next = create_node(2);
    stack_b->next->prev = stack_b;

    pa(&stack_a, &stack_b);

    cr_expect_eq(stack_a->data, 3, "Top of stack_a should be 3.");
    cr_expect_eq(stack_b->data, 2, "Top of stack_b should now be 2.");
    cr_expect_eq(stack_a->next->data, 7, "Second element of stack_a should be 7.");

    free_stack(stack_a);
    free_stack(stack_b);
}

// Test Case 4: Move the top element from non-empty a to non-empty b using pb
Test(stack_operations, test_pb_move_to_non_empty_b) {
    t_node *stack_a = create_node(10);
    stack_a->next = create_node(9);
    stack_a->next->prev = stack_a;

    t_node *stack_b = create_node(8);
    stack_b->next = create_node(7);
    stack_b->next->prev = stack_b;

    pb(&stack_b, &stack_a);

    cr_expect_eq(stack_b->data, 10, "Top of stack_b should be 10.");
    cr_expect_eq(stack_a->data, 9, "Top of stack_a should now be 9.");
    cr_expect_eq(stack_b->next->data, 8, "Second element of stack_b should be 8.");

    free_stack(stack_a);
    free_stack(stack_b);
}

// Test Case 5: Call pa with empty b and non-empty a (should do nothing)
Test(stack_operations, test_pa_with_empty_b) {
    t_node *stack_a = create_node(2);
    stack_a->next = create_node(1);
    stack_a->next->prev = stack_a;
    t_node *stack_b = NULL;

    pa(&stack_a, &stack_b);

    cr_expect_eq(stack_a->data, 2, "Stack_a should remain unchanged (top = 2).");
    cr_expect_null(stack_b, "Stack_b should remain empty.");

    free_stack(stack_a);
}

// Test Case 6: Call pb with empty a and non-empty b (should do nothing)
Test(stack_operations, test_pb_with_empty_a) {
    t_node *stack_a = NULL;
    t_node *stack_b = create_node(5);
    stack_b->next = create_node(4);
    stack_b->next->prev = stack_b;

    pb(&stack_b, &stack_a);

    cr_expect_eq(stack_b->data, 5, "Stack_b should remain unchanged (top = 5).");
    cr_expect_null(stack_a, "Stack_a should remain empty.");

    free_stack(stack_b);
}

// Test Case 7: Move the last element from b to a using pa
Test(stack_operations, test_pa_move_last_element) {
    t_node *stack_a = create_node(9);
    t_node *stack_b = create_node(1);

    pa(&stack_a, &stack_b);

    cr_expect_eq(stack_a->data, 1, "Top of stack_a should be 1.");
    cr_expect_eq(stack_a->next->data, 9, "Second element of stack_a should be 9.");
    cr_expect_null(stack_b, "Stack_b should be empty.");

    free_stack(stack_a);
}

// Test Case 8: Move the last element from a to b using pb
Test(stack_operations, test_pb_move_last_element) {
    t_node *stack_a = create_node(8);
    t_node *stack_b = create_node(3);
    stack_b->next = create_node(2);
    stack_b->next->prev = stack_b;

    pb(&stack_b, &stack_a);

    cr_expect_eq(stack_b->data, 8, "Top of stack_b should be 8.");
    cr_expect_eq(stack_b->next->data, 3, "Second element of stack_b should be 3.");
    cr_expect_null(stack_a, "Stack_a should be empty.");

    free_stack(stack_b);
}
