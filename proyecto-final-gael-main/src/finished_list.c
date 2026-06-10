#include <stdio.h>
#include <stdlib.h>
#include "finished_list.h"

void finished_insert(FinishedNode** head, Process p)
{
    FinishedNode* newNode =
        malloc(sizeof(FinishedNode));

    newNode->process = p;
    newNode->next = NULL;

    if (*head == NULL ||
        p.pid < (*head)->process.pid)
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    FinishedNode* current = *head;

    while (current->next != NULL &&
           current->next->process.pid < p.pid)
    {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void finished_print(FinishedNode* head)
{
    printf("\n--- PROCESOS TERMINADOS ---\n");

    while (head != NULL)
    {
        printf("PID %d\n",
               head->process.pid);

        head = head->next;
    }
}

void finished_destroy(FinishedNode* head)
{
    while (head != NULL)
    {
        FinishedNode* temp = head;
        head = head->next;
        free(temp);
    }
}