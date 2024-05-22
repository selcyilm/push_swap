#ifndef PUSH_SWAP
#define PUSH_SWAP

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <limits.h>


bool	check_non_numeric(char **str);
bool	check_duplicate(char **str);
void	error_display(char **av);


#endif

