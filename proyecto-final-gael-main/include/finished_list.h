#ifndef FINISHED_LIST_H
#define FINISHED_LIST_H

#include "process.h"

typedef struct FinishedNode
{
    Process process;
    struct FinishedNode* next;
} FinishedNode;

void finished_insert(FinishedNode** head, Process p);

void finished_print(FinishedNode* head);

void finished_destroy(FinishedNode* head);

#endif