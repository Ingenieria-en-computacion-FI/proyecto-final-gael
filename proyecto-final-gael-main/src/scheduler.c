#include "scheduler.h"
#include "process.h"
#include <stdlib.h>

typedef struct Node {
    Process process;
    struct Node* next;
} Node;

struct Scheduler {
    Node* head;
    Node* tail;
};

Scheduler* scheduler_create_fifo()
{
    Scheduler* s = malloc(sizeof(Scheduler));
    s->head = NULL;
    s->tail = NULL;
    return s;
}

void scheduler_add_process(Scheduler* scheduler, Process p)
{
    Node* n = malloc(sizeof(Node));
    n->process = p;
    n->next = NULL;

    if (scheduler->head == NULL)
    {
        scheduler->head = n;
        scheduler->tail = n;
        return;
    }

    scheduler->tail->next = n;
    scheduler->tail = n;
}

Process* scheduler_next(Scheduler* scheduler)
{
    if (scheduler->head == NULL)
        return NULL;

    Node* n = scheduler->head;

    Process* p = malloc(sizeof(Process));
    *p = n->process;

    scheduler->head = n->next;

    if (scheduler->head == NULL)
        scheduler->tail = NULL;

    free(n);


    return p;
}

Process* scheduler_next_rr(Scheduler* scheduler, int quantum)
{
    if (scheduler->head == NULL)
        return NULL;

    Node* n = scheduler->head;

    Process* p = malloc(sizeof(Process));
    *p = n->process;

    int exec =
        (p->remaining_time < quantum)
        ? p->remaining_time
        : quantum;

    p->remaining_time -= exec;

    scheduler->head = n->next;

    if (p->remaining_time <= 0)
    {
        p->state = FINISHED;

        if (scheduler->head == NULL)
            scheduler->tail = NULL;

        free(n);
    }
    else
    {
        p->state = READY;

        n->process = *p;
        n->next = NULL;

        if (scheduler->head == NULL)
        {
            scheduler->head = n;
            scheduler->tail = n;
        }
        else
        {
            scheduler->tail->next = n;
            scheduler->tail = n;
        }
    }

    return p;
}
Process* scheduler_next_sjf(Scheduler* scheduler)
{
    if (scheduler->head == NULL)
        return NULL;

    Node *current = scheduler->head;
    Node *best = scheduler->head;
    Node *prev = NULL;
    Node *best_prev = NULL;

    while (current != NULL)
    {
        if (current->process.burst_time < best->process.burst_time)
        {
            best = current;
            best_prev = prev;
        }

        prev = current;
        current = current->next;
    }

    if (best_prev == NULL)
    {
        scheduler->head = best->next;
    }
    else
    {
        best_prev->next = best->next;
    }

    if (best == scheduler->tail)
    {
        scheduler->tail = best_prev;
    }

    Process* p = malloc(sizeof(Process));
    *p = best->process;
    p->state = RUNNING;

    free(best);

    return p;
}

void scheduler_destroy(Scheduler* scheduler)
{
    Node* current = scheduler->head;

    while (current != NULL)
    {
        Node* next = current->next;
        free(current);
        current = next;
    }

    free(scheduler);
}