#include "../include/push_swap.h"

t_node *create_node(int data) {
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
}