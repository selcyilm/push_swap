#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/push_swap.h"

t_node *create_node(int data);
void free_stack(t_node *stack);

// Redirect output to capture for error messages, etc.
void redirect_all_std(void) {
    cr_redirect_stdout();
    cr_redirect_stderr();
}

// Test Case 1: Parsing a single string argument (as if two arguments)
Test(parse_arguments, test_parse_av_if_two_valid_input, .init = redirect_all_std) {
    t_node *stack = NULL;
    char *input = "3 1 2";

    stack = parse_av_if_two(stack, input);

    // Verify stack structure after parsing
    cr_expect_not_null(stack, "The stack should not be NULL after parsing valid input.");
    cr_expect_eq(stack->data, 3, "First element should be 3.");
    cr_expect_eq(stack->next->data, 1, "Second element should be 1.");
    cr_expect_eq(stack->next->next->data, 2, "Third element should be 2.");
    cr_expect_null(stack->next->next->next, "There should be no further elements after the third.");

    free_stack(stack);
}

// Test Case 2: Parsing an empty string with parse_av_if_two (should return NULL or trigger error handling)
Test(parse_arguments, test_parse_av_if_two_empty_input, .init = redirect_all_std) {
    t_node *stack = NULL;
    char *input = "";

    stack = parse_av_if_two(stack, input);

    cr_expect_null(stack, "The stack should be NULL when parsing an empty string.");
}

// Test Case 3: Parsing multiple arguments with parse_av_if_more
Test(parse_arguments, test_parse_av_if_more_valid_input, .init = redirect_all_std) {
    t_node *stack = NULL;
    char *argv[] = {"./push_swap", "5", "3", "7", "9", NULL};

    stack = parse_av_if_more(stack, argv);

    cr_expect_not_null(stack, "The stack should not be NULL after parsing valid input.");
    cr_expect_eq(stack->data, 5, "First element should be 5.");
    cr_expect_eq(stack->next->data, 3, "Second element should be 3.");
    cr_expect_eq(stack->next->next->data, 7, "Third element should be 7.");
    cr_expect_eq(stack->next->next->next->data, 9, "Fourth element should be 9.");
    cr_expect_null(stack->next->next->next->next, "There should be no further elements after the fourth.");

    free_stack(stack);
}

// Test Case 4: Parsing NULL input with parse_av_if_more (should return NULL)
Test(parse_arguments, test_parse_av_if_more_null_input, .init = redirect_all_std) {
    t_node *stack = NULL;

    stack = parse_av_if_more(stack, NULL);

    cr_expect_null(stack, "The stack should be NULL when parsing a NULL input.");
}

// Test Case 5: Freeing an argument array with free_argv
Test(memory_management, test_free_argv_valid_input) {
    char **argv = malloc(3 * sizeof(char *));
    argv[0] = strdup("3");
    argv[1] = strdup("1");
    argv[2] = NULL;

    free_argv(argv);
    // Check that the memory has been freed (argv should be NULL after free)
    cr_assert_eq(argv, NULL, "The argv pointer should be NULL after free_argv is called.");
}

// Test Case 6: Freeing NULL with free_argv (should do nothing)
Test(memory_management, test_free_argv_null_input) {
    char **argv = NULL;

    free_argv(argv);

    // No crash should occur, and since argv is NULL, nothing happens
    cr_assert_null(argv, "The argv pointer should remain NULL.");
}

// Test Case 7: Error handling function with invalid input (mock error_display)
// Assuming error_display is triggered on invalid inputs and outputs error to stderr
Test(parse_arguments, test_invalid_input_triggers_error_display, .init = redirect_all_std) {
    t_node *stack = NULL;
    char *argv[] = {"a", "b", NULL};  // Invalid input assuming non-numeric values

    stack = parse_av_if_more(stack, argv);

    cr_assert_null(stack, "The stack should be NULL due to invalid input.");
    cr_assert_stderr_eq_str("Error\n", "Expected error message 'Error' for invalid input.");
}
