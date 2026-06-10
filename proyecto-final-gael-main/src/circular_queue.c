#include <stdlib.h>
#include "circular_queue.h"

struct CircularQueue {
    int* data;
    int front;
    int rear;
    int size;
    int capacity;
};

CircularQueue* cq_create(int capacity) {

    CircularQueue* q = malloc(sizeof(CircularQueue));

    q->data = malloc(sizeof(int) * capacity);

    q->front = 0;
    q->rear = 0;
    q->size = 0;
    q->capacity = capacity;

    return q;
}

void cq_enqueue(CircularQueue* q, int value) {

    if (q->size == q->capacity)
        return;

    q->data[q->rear] = value;

    q->rear = (q->rear + 1) % q->capacity;

    q->size++;
}

int cq_dequeue(CircularQueue* q) {

    if (q->size == 0)
        return -1;

    int value = q->data[q->front];

    q->front = (q->front + 1) % q->capacity;

    q->size--;

    return value;
}

int cq_is_empty(CircularQueue* q) {
    return q->size == 0;
}

void cq_destroy(CircularQueue* q) {
    free(q->data);
    free(q);
}