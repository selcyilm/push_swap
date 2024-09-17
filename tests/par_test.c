#include <criterion/criterion.h>
#include <criterion/parameterized.h>
#include "../include/push_swap.h"
#include <stdlib.h>

void free_strings(struct criterion_test_params *crp)
{
	char **strings = (char **) crp->params;
	for (size_t i = 0; i < crp->length; ++i) {
		cr_free(strings[i]);
	}
	cr_free(strings);
}

char *cr_strdup(const char *str)
{
	char *ptr = cr_malloc(strlen(str) + 1);
	if (ptr)
		strcpy(ptr, str);
	return ptr;
}

ParameterizedTestParameters(params, string) {
	char **strings = cr_malloc(sizeof (*strings) * 6);
	strings[0] = cr_strdup("1");
	strings[1] = cr_strdup("2");
	strings[2] = cr_strdup("0");
	strings[3] = cr_strdup("-1");
	strings[4] = cr_strdup("+1");
	strings[5] = cr_strdup("6");
	return cr_make_param_array(const char *, strings, 6, free_strings);
}

ParameterizedTest(char **str, params, string) {
	cr_assert_eq(ft_atol(*str), atol(*str));
	cr_log_warn("string: %s", *str);
}
