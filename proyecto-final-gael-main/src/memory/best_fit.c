#include "memory/memory_block.h"
#include <stdlib.h>

MemoryBlock* best_fit(MemoryBlock* head, int size, int pid)
{
    MemoryBlock* best = NULL;

    for (MemoryBlock* current = head; current != NULL; current = current->next)
    {
        if (current->free && current->size >= size)
        {
            if (best == NULL || current->size < best->size)
            {
                best = current;
            }
        }
    }

    if (best == NULL)
        return NULL;

    if (best->size > size)
    {
        MemoryBlock* new_block =
            malloc(sizeof(MemoryBlock));

        new_block->start = best->start + size;
        new_block->size = best->size - size;
        new_block->free = 1;
        new_block->pid = -1;

        new_block->next = best->next;
        new_block->prev = best;

        if (best->next != NULL)
        {
            best->next->prev = new_block;
        }

        best->next = new_block;
        best->size = size;
    }

    best->free = 0;
    best->pid = pid;

    return best;
}