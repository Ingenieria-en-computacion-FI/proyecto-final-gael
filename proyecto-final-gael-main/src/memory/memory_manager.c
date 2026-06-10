#include "memory_manager.h"
#include <stdlib.h>

MemoryBlock* allocate_first_fit(MemoryBlock* head, int size, int pid)
{
    MemoryBlock* current = head;

    while (current != NULL)
    {
        if (current->free && current->size >= size)
        {
            /* Dividir el bloque si sobra espacio */
            if (current->size > size)
            {
                MemoryBlock* new_block =
                    malloc(sizeof(MemoryBlock));

                new_block->start =
                    current->start + size;

                new_block->size =
                    current->size - size;

                new_block->free = 1;
                new_block->pid = -1;

                new_block->next = current->next;
                new_block->prev = current;

                if (current->next != NULL)
                {
                    current->next->prev = new_block;
                }

                current->next = new_block;
                current->size = size;
            }

            current->free = 0;
            current->pid = pid;

            return current;
        }

        current = current->next;
    }

    return NULL;
}

void free_memory(MemoryBlock* head, int pid)
{
    MemoryBlock* current = head;

    while (current != NULL)
    {
        if (current->pid == pid)
        {
            current->free = 1;
            current->pid = -1;
            return;
        }

        current = current->next;
    }
}