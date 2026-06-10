#include "memory/memory_block.h"
#include <stdlib.h>

MemoryBlock* worst_fit(MemoryBlock* head, int size, int pid)
{
    MemoryBlock* worst = NULL;

    for (MemoryBlock* current = head; current != NULL; current = current->next)
    {
        if (current->free && current->size >= size)
        {
            if (worst == NULL || current->size > worst->size)
            {
                worst = current;
            }
        }
    }

    if (worst == NULL)
        return NULL;

    if (worst->size > size)
    {
        MemoryBlock* new_block =
            malloc(sizeof(MemoryBlock));

        new_block->start = worst->start + size;
        new_block->size = worst->size - size;
        new_block->free = 1;
        new_block->pid = -1;

        new_block->next = worst->next;
        new_block->prev = worst;

        if (worst->next != NULL)
        {
            worst->next->prev = new_block;
        }

        worst->next = new_block;
        worst->size = size;
    }

    worst->free = 0;
    worst->pid = pid;

    return worst;
}