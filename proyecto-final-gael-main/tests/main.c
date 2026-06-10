#include <stdio.h>

void test_stack_push_pop();
void test_stack_empty();
void test_queue_fifo();
void test_round_robin_behavior();
void test_first_fit();
void test_fifo_scheduler();

int main() {

    printf("Running tests...\n");

    test_stack_push_pop();
    test_stack_empty();
    test_queue_fifo();
    test_round_robin_behavior();
    test_first_fit();
    test_fifo_scheduler();

    printf("Tests passed!\n");

    return 0;
}