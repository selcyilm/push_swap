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
HELPER="helper_stack_utils.c"
CC="gcc -Wall -Werror -Wextra -o"
CRI="-lcriterion"


if [ "$COMMAND" == "atol" ]; then
    echo "Compiling and running atol tests..."

    $CC $OUTPUT $CRI $TEST_FILE_ATOL $FT_ATOL_SRC $PUSH_SWAP_HEADER $LIBFT

    if [ $? -eq 0 ]; then
        echo "Compilation successful, running tests..."

        ./$OUTPUT
    else
        echo "Compilation failed."
    fi
elif [ "$COMMAND" == "error" ]; then
    echo "Compiling and running error handle tests..."

    $CC $OUTPUT $CRI error_handle_test.c $ALL_SRC_FILES $PUSH_SWAP_HEADER $LIBFT 

    if [ $? -eq 0 ]; then
        echo "Compilation successful, running tests..."
       ./$OUTPUT
    else
        echo "Compilation failed."
    fi
elif [ "$COMMAND" == "push" ]; then
    echo "Compiling and running push tests..."

    $CC $OUTPUT $CRI push_test.c $HELPER $ALL_SRC_FILES $PUSH_SWAP_HEADER $LIBFT 

    if [ $? -eq 0 ]; then
        echo "Compilation successful, running tests..."
       ./$OUTPUT
    else
        echo "Compilation failed."
    fi
elif [ "$COMMAND" == "swap" ]; then
    echo "Compiling and running swap tests..."

    $CC $OUTPUT $CRI swap_test.c $HELPER $ALL_SRC_FILES $PUSH_SWAP_HEADER $LIBFT 

    if [ $? -eq 0 ]; then
        echo "Compilation successful, running tests..."
       ./$OUTPUT
    else
        echo "Compilation failed."
    fi
elif [ "$COMMAND" == "rotate" ]; then
    echo "Compiling and running rotate tests..."

    $CC $OUTPUT $CRI rotate_test.c $HELPER $ALL_SRC_FILES $PUSH_SWAP_HEADER $LIBFT 

    if [ $? -eq 0 ]; then
        echo "Compilation successful, running tests..."
       ./$OUTPUT
    else
        echo "Compilation failed."
    fi
elif [ "$COMMAND" == "rev_rot" ]; then
    echo "Compiling and running reverse rotate tests..."

    $CC $OUTPUT $CRI rev_rot_test.c $HELPER $ALL_SRC_FILES $PUSH_SWAP_HEADER $LIBFT 

    if [ $? -eq 0 ]; then
        echo "Compilation successful, running tests..."
       ./$OUTPUT
    else
        echo "Compilation failed."
    fi
elif [ "$COMMAND" == "handle_av" ]; then
    echo "Compiling and running handle argv tests..."

    $CC $OUTPUT $CRI handle_av_test.c $HELPER $ALL_SRC_FILES $PUSH_SWAP_HEADER $LIBFT 

    if [ $? -eq 0 ]; then
        echo "Compilation successful, running tests..."
       ./$OUTPUT
    else
        echo "Compilation failed."
    fi
elif [ "$COMMAND" == "all" ]; then
    echo "Compiling and running all tests..."

    $CC $OUTPUT $CRI *.c $ALL_SRC_FILES $PUSH_SWAP_HEADER $LIBFT 

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
