#!/bin/bash

# Check i a command-line argument was provided
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <command>"
    exit 1
fi

COMMAND=$1

TEST_FILE_ATOL="atol_test.c"
FT_ATOL_SRC="../src/ft_atol.c"
PUSH_SWAP_HEADER="../include/push_swap.h"
LIBFT="../libft/libft.a"
ALL_SRC_FILES="$(find ../src -type f -name "*.c" ! -name "main.c")"
OUTPUT="test"

if [ "$COMMAND" == "atol" ]; then
    echo "Compiling and running atol tests..."

    gcc -o $OUTPUT -lcriterion $TEST_FILE_ATOL $FT_ATOL_SRC $PUSH_SWAP_HEADER $LIBFT

    if [ $? -eq 0 ]; then
        echo "Compilation successful, running tests..."

        ./$OUTPUT
    else
        echo "Compilation failed."
    fi
elif [ "$COMMAND" == "error" ]; then
    echo "Compiling and running error handle tests..."

    gcc -o $OUTPUT -lcriterion error_handle_test.c $ALL_SRC_FILES $PUSH_SWAP_HEADER $LIBFT 

    if [ $? -eq 0 ]; then
        echo "Compilation successful, running tests..."
       ./$OUTPUT
    else
        echo "Compilation failed."
    fi
else
    echo "Unknown command: $COMMAND"
    echo "Usage: $0 <atol>"
    exit 1
fi
