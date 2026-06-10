#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "process.h"

typedef struct Scheduler Scheduler;

Scheduler* scheduler_create_fifo();

void scheduler_add_process(Scheduler* scheduler, Process p);

Process* scheduler_next(Scheduler* scheduler);

Process* scheduler_next_rr(Scheduler* scheduler, int quantum);

Process* scheduler_next_sjf(Scheduler* scheduler);

void scheduler_destroy(Scheduler* scheduler);

#endif