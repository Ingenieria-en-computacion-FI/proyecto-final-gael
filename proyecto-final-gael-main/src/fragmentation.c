#include "fragmentation.h"
#include <stdlib.h>

int has_fragmentation(
    MemoryBlock* head,
    int requested_size
)
{
    int total_free = 0;
    int largest_block = 0;

    MemoryBlock* current = head;

    while (current != NULL)
    {
        if (current->free)
        {
            total_free += current->size;

            if (current->size > largest_block)
            {
                largest_block = current->size;
            }
        }

        current = current->next;
    }

    if (total_free >= requested_size &&
        largest_block < requested_size)
    {
        return 1;
    }

    return 0;
}