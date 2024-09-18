#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdlib.h>

Test(suite, test, .init = cr_redirect_stdout)
{
	cr_redirect_stdout();
	int status = system("./a.out 1 2 3");
	fflush(stdout);
	cr_assert_stdout_eq_str("123");
}
