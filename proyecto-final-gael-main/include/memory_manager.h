#ifndef MEMORY_MANAGER_H
#define MEMORY_MANAGER_H

#include "memory/memory_block.h"

MemoryBlock* allocate_first_fit(MemoryBlock* head, int size, int pid);

void free_memory(MemoryBlock* head, int pid);

void coalesce(MemoryBlock* head);

#endif