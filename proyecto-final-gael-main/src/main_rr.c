#include <stdio.h>
#include <stdlib.h>
#include "scheduler.h"

int main()
{
    Scheduler* scheduler = scheduler_create_fifo();

    Process p1 = {1,5,5,1,100,0,READY};
    Process p2 = {2,3,3,1,100,0,READY};
    Process p3 = {3,4,4,1,100,0,READY};

    scheduler_add_process(scheduler,p1);
    scheduler_add_process(scheduler,p2);
    scheduler_add_process(scheduler,p3);

    printf("=== ROUND ROBIN ===\n");

    Process* p;

    while ((p = scheduler_next_rr(scheduler,2)) != NULL)
    {
        printf(
            "PID %d | Remaining %d | State %d\n",
            p->pid,
            p->remaining_time,
            p->state
        );
    }

    scheduler_destroy(scheduler);

    return 0;
}