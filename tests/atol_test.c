#include <criterion/criterion.h>
#include "../include/push_swap.h"

// Test case 1: Basic positive number
Test(ft_atol, basic_positive)
{
    char *input = "12345";
    long expected = 12345;
    cr_assert_eq(ft_atol(input), expected, "Expected %ld but got %ld", expected, ft_atol(input));
}

// Test case 2: Basic negative number
Test(ft_atol, basic_negative)
{
    char *input = "-6789";
    long expected = -6789;
    cr_assert_eq(ft_atol(input), expected, "Expected %ld but got %ld", expected, ft_atol(input));
}

// Test case 3: Number with positive sign
Test(ft_atol, positive_sign)
{
    char *input = "+9876";
    long expected = 9876;
    cr_assert_eq(ft_atol(input), expected, "Expected %ld but got %ld", expected, ft_atol(input));
}

// Test case 4: Zero
Test(ft_atol, zero_value)
{
    char *input = "0";
    long expected = 0;
    cr_assert_eq(ft_atol(input), expected, "Expected %ld but got %ld", expected, ft_atol(input));
}

// Test case 5: Handle leading spaces (invalid input, should stop at the first non-numeric)
Test(ft_atol, leading_spaces)
{
    char *input = " 42";
    long expected = 0;  // Since `ft_atol` doesn't handle spaces, expect it to return 0
    cr_assert_eq(ft_atol(input), expected, "Expected %ld but got %ld", expected, ft_atol(input));
}

// Test case 6: Handle non-numeric characters at the end
Test(ft_atol, non_numeric_end)
{
    char *input = "123abc";
    long expected = 123;  // Should stop converting at 'a'
    cr_assert_eq(ft_atol(input), expected, "Expected %ld but got %ld", expected, ft_atol(input));
}

// Test case 7: Handle only non-numeric input
Test(ft_atol, non_numeric_input)
{
    char *input = "abc123";
    long expected = 0;  // No valid number at the start
    cr_assert_eq(ft_atol(input), expected, "Expected %ld but got %ld", expected, ft_atol(input));
}

// Test case 8: Long max value
Test(ft_atol, long_max_value)
{
    char *input = "9223372036854775807";  // LONG_MAX
    long expected = 9223372036854775807;
    cr_assert_eq(ft_atol(input), expected, "Expected %ld but got %ld", expected, ft_atol(input));
}

// Test case 9: Long min value
Test(ft_atol, long_min_value)
{
    char *input = "-9223372036854775808";  // LONG_MIN
    long expected = -9223372036854775807 - 1;
    cr_assert_eq(ft_atol(input), expected, "Expected %ld but got %ld", expected, ft_atol(input));
}

// Test case 10: Overflowing number (should truncate within range)
Test(ft_atol, overflow_number)
{
    char *input = "92233720368547758070";  // Larger than LONG_MAX
    long expected = 9223372036854775807;  // Depends on your implementation's behavior on overflow
    cr_assert_eq(ft_atol(input), expected, "Expected %ld but got %ld", expected, ft_atol(input));
}

// Test case 11: Underflowing number (should truncate within range)
Test(ft_atol, underflow_number)
{
    char *input = "-92233720368547758080";  // Smaller than LONG_MIN
    long expected = -9223372036854775807 - 1;  // Depends on your implementation's behavior on underflow
    cr_assert_eq(ft_atol(input), expected, "Expected %ld but got %ld", expected, ft_atol(input));
}
