#ifndef FRAGMENTATION_H
#define FRAGMENTATION_H

#include "memory/memory_block.h"

int has_fragmentation(
    MemoryBlock* head,
    int requested_size
);

#endif