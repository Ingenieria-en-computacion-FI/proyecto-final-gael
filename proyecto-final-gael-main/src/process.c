#include "process.h"
#include <stdio.h>


void print_process(Process p)
{
    const char* state_str[] = {
        "READY", "RUNNING", "BLOCKED", "FINISHED"
    };

    printf("PID: %d | Burst: %d | Remaining: %d | Priority: %d | Memory: %d | State: %s\n",
        p.pid,
        p.burst_time,
        p.remaining_time,
        p.priority,
        p.memory_required,
        state_str[p.state]
    );
int memory_allocated;

}