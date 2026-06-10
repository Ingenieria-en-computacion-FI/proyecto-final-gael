#ifndef MEMORY_BLOCK_H
#define MEMORY_BLOCK_H

typedef struct MemoryBlock {
    int start;
    int size;
    int free;
    int pid;
    struct MemoryBlock* next;
    struct MemoryBlock* prev;
} MemoryBlock;

#endif