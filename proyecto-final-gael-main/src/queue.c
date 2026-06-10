#include <stdlib.h>
#include "queue.h"

struct Node {
    int value;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

Queue* queue_create() {

    Queue* queue = malloc(sizeof(Queue));

    queue->front = NULL;
    queue->rear = NULL;

    return queue;
}

void enqueue(
    Queue* queue,
    int value
) {

    struct Node* newNode =
        malloc(sizeof(struct Node));

    newNode->value = value;
    newNode->next = NULL;

    if (queue->rear == NULL) {

        queue->front = newNode;
        queue->rear = newNode;

        return;
    }

    queue->rear->next = newNode;
    queue->rear = newNode;
}

int dequeue(
    Queue* queue
) {

    if (queue->front == NULL)
        return -1;

    struct Node* temp =
        queue->front;

    int value =
        temp->value;

    queue->front =
        temp->next;

    if (queue->front == NULL)
        queue->rear = NULL;

    free(temp);

    return value;
}

int queue_is_empty(
    Queue* queue
) {

    return queue->front == NULL;
}

void queue_destroy(
    Queue* queue
) {

    while (!queue_is_empty(queue))
        dequeue(queue);

    free(queue);
}