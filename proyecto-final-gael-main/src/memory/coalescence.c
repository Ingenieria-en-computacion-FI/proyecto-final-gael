#include "memory/memory_block.h"
#include <stdlib.h>

void coalesce(MemoryBlock* head)
{
    MemoryBlock* current = head;

    while (current != NULL && current->next != NULL)
    {
        if (current->free && current->next->free)
        {
            MemoryBlock* temp = current->next;

            current->size += temp->size;
            current->next = temp->next;

            if (temp->next != NULL)
                temp->next->prev = current;

            free(temp);
        }
        else
        {
            current = current->next;
        }
    }
}