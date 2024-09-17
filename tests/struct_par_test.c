
#include <criterion/criterion.h>
#include <criterion/parameterized.h>
#include "../include/push_swap.h"

typedef struct s_vals
{
	long	expected;
	char	*data;
}	t_vals;

void free_t_vals(struct criterion_test_params *crp)
{
	t_vals *vals = (t_vals *) crp->params;
	for (size_t i = 0; i < crp->length; ++i) {
		cr_free(vals[i].data);
	}
	cr_free(vals);
}

char *cr_strdup(const char *str)
{
	char *ptr = cr_malloc(strlen(str) + 1);
	if (ptr)
		strcpy(ptr, str);
	return ptr;
}

ParameterizedTestParameters(params, string) {
	t_vals *val = cr_malloc(sizeof(t_vals) * 3);
	val[0] = (t_vals){1, cr_strdup("1")};
	val[1] = (t_vals){-1, cr_strdup("-1")};
	val[2] = (t_vals){3, cr_strdup("3")};

	return cr_make_param_array(t_vals, val, 3, free_t_vals);
}

ParameterizedTest(t_vals *vals, params, string) {
	cr_assert_eq(ft_atol(vals->data), vals->expected, "Expected: %li, Actual: %s", vals->expected, vals->data);
	cr_log_warn("string: %s, %li", vals->data, vals->expected);
}
