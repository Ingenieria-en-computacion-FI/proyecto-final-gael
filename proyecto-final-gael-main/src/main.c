#include <stdio.h>
#include <stdlib.h>
#include "scheduler.h"
#include "process.h"
#include "memory/memory_block.h"
#include "memory_manager.h"
#include "finished_list.h"
#include "fragmentation.h"

MemoryBlock ram = {0, 500, 1, -1, NULL, NULL};

void print_state(Process p)
{
    const char* states[] = {
        "READY",
        "RUNNING",
        "BLOCKED",
        "FINISHED"
    };

    printf("PID %d | State: %s | Mem: %d\n",
           p.pid,
           states[p.state],
           p.memory_required);
}

void print_memory(MemoryBlock* head)
{
    MemoryBlock* current = head;

    while (current != NULL)
    {
        printf("[start=%d size=%d free=%d pid=%d] ",
               current->start,
               current->size,
               current->free,
               current->pid);

        current = current->next;
    }

    printf("\n");
}

int main()
{
    printf("=== SISTEMA OPERATIVO SIMULADO ===\n\n");

    Scheduler* scheduler = scheduler_create_fifo();
    FinishedNode* finished_list = NULL;

    Process p1 = {1, 5, 5, 1, 100, 0, READY};
    Process p2 = {2, 3, 3, 1, 200, 0, READY};
    Process p3 = {3, 4, 4, 1, 300, 0, READY};

    Process processes[3] = {p1, p2, p3};

    printf("--- ASIGNACION DE MEMORIA ---\n");

    for (int i = 0; i < 3; i++)
    {
        if (allocate_first_fit(
                &ram,
                processes[i].memory_required,
                processes[i].pid))
        {
            processes[i].state = READY;

            printf("PID %d -> memoria asignada (%d)\n",
                   processes[i].pid,
                   processes[i].memory_required);
        }
        else
        {
            processes[i].state = BLOCKED;

            printf("PID %d -> sin memoria suficiente (%d)\n",
                   processes[i].pid,
                   processes[i].memory_required);

            if (has_fragmentation(&ram,
                                  processes[i].memory_required))
            {
                printf("   >>> FRAGMENTACION DETECTADA <<<\n");
            }
        }

        scheduler_add_process(scheduler, processes[i]);
    }

    printf("\n--- ESTADO DE MEMORIA DESPUES DE ASIGNAR ---\n");
    print_memory(&ram);

    printf("\n--- EJECUCION FIFO ---\n");

    Process* p;

    while ((p = scheduler_next(scheduler)) != NULL)
    {
        if (p->state == BLOCKED)
        {
            printf("PID %d bloqueado por falta de memoria\n",
                   p->pid);

            free(p);
            continue;
        }

        p->state = RUNNING;

        print_state(*p);

        free_memory(&ram, p->pid);

        p->state = FINISHED;

        finished_insert(&finished_list, *p);

        free(p);
    }

    coalesce(&ram);

    printf("\n--- ESTADO FINAL DE MEMORIA ---\n");
    print_memory(&ram);

    finished_print(finished_list);

    finished_destroy(finished_list);

    scheduler_destroy(scheduler);

    return 0;
}