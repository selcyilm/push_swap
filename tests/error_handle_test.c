#include "../include/push_swap.h"
#include <criterion/criterion.h>

//for
//bool	check_non_numeric(char **str, int start_pos)

Test(error_handle, valid_pos)
{
	char	*input[] = {"123", "234", "435", "000"};
	bool	result = check_non_numeric(input, 0);
	cr_assert_eq(result, true);
}

Test(error_handle, valid_neg)
{
	char	*input[] = {"-123", "-234", "-435", "-000"};
	bool	result = check_non_numeric(input, 0);
	cr_assert_eq(result, true);
}

Test(error_handle, valid_both)
{
	char	*input[] = {"+123", "+234", "+435", "0", "+122"};
	bool	result = check_non_numeric(input, 0);
	cr_assert_eq(result, true, "Expected true but got false");
}

TestSuite(check_non_numeric_tests);

Test(check_non_numeric_tests, all_numeric_strings)
{
    char *input[] = {"123", "456", "789", NULL};
    bool result = check_non_numeric(input, 0);
    cr_assert_eq(result, true, "Expected true but got false for all numeric strings.");
}

Test(check_non_numeric_tests, some_non_numeric_strings)
{
    char *input[] = {"123", "45a", "789", NULL};
    bool result = check_non_numeric(input, 0);
    cr_assert_eq(result, false, "Expected false but got true for some non-numeric strings.");
}

Test(check_non_numeric_tests, starting_from_middle)
{
    char *input[] = {"123", "456", "78a", "910", NULL};
    bool result = check_non_numeric(input, 2);
    cr_assert_eq(result, false, "Expected false but got true when starting from middle with non-numeric string.");
}

Test(check_non_numeric_tests, empty_strings)
{
    char *input[] = {"", "", NULL};
    bool result = check_non_numeric(input, 0);
    cr_assert_eq(result, true, "Expected true but got false for empty strings.");
}

Test(check_non_numeric_tests, single_numeric_string)
{
    char *input[] = {"123", NULL};
    bool result = check_non_numeric(input, 0);
    cr_assert_eq(result, true, "Expected true but got false for a single numeric string.");
}

Test(check_non_numeric_tests, single_non_numeric_string)
{
    char *input[] = {"abc", NULL};
    bool result = check_non_numeric(input, 0);
    cr_assert_eq(result, false, "Expected false but got true for a single non-numeric string.");
}

Test(check_non_numeric_tests, mixed_start_position)
{
    char *input[] = {"123", "456", "abc", "789", NULL};
    bool result = check_non_numeric(input, 1);
    cr_assert_eq(result, false, "Expected false but got true when starting from position 1 with mixed strings.");
}

Test(check_non_numeric_tests, all_non_numeric_strings)
{
    char *input[] = {"abc", "def", "ghi", NULL};
    bool result = check_non_numeric(input, 0);
    cr_assert_eq(result, false, "Expected false but got true for all non-numeric strings.");
}

//bool	check_string(char *str)
Test(chec_string_tests, valid_numbers) {
    cr_assert_eq(check_string("123"), true);
    cr_assert_eq(check_string("-456"), true);
    cr_assert_eq(check_string("+789"), true);
    cr_assert_eq(check_string("007"), true);
}

Test(check_string_tests, invalid_numbers) {
    cr_assert_eq(check_string("a123"), false);
    cr_assert_eq(check_string("12a34"), false);
    cr_assert_eq(check_string(""), false);
    cr_assert_eq(check_string("-"), false);
    cr_assert_eq(check_string(" 123"), false);
    cr_assert_eq(check_string("12 34"), false);
}


//bool	check_duplicate_limit(char **str, int start_pos)
Test(check_duplicate_limit_tests, valid_uique_numbers) {
    char *arr[] = {"123", "456", "789", NULL};
    cr_assert_eq(check_duplicate_limit(arr, 0), true);
}

Test(check_duplicate_limit_tests, valid_numbers_with_duplicate) {
    char *arr[] = {"123", "456", "123", NULL};
    cr_assert_eq(check_duplicate_limit(arr, 0), false);
}

Test(check_duplicate_limit_tests, number_exceeding_INT_MAX) {
    char *arr[] = {"2147483648", "123", "456", NULL};
    cr_assert_eq(check_duplicate_limit(arr, 0), false);
}

Test(check_duplicate_limit_tests, number_less_than_INT_MIN) {
    char *arr[] = {"-2147483649", "123", "456", NULL};
    cr_assert_eq(check_duplicate_limit(arr, 0), false);
}

Test(check_duplicate_limit_tests, all_numbers_below_INT_MIN) {
    char *arr[] = {"-2147483649", "-2147483650", NULL};
    cr_assert_eq(check_duplicate_limit(arr, 0), false);
}

Test(check_duplicate_limit_tests, single_valid_number) {
    char *arr[] = {"123", NULL};
    cr_assert_eq(check_duplicate_limit(arr, 0), true);
}

Test(check_duplicate_limit_tests, empty_array) {
    char *arr[] = {NULL};
    cr_assert_eq(check_duplicate_limit(arr, 0), true);
}
