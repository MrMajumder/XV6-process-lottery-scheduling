#include "types.h"
#include "mmu.h"
#include "param.h"
#include "proc.h"
#include "user.h"

#undef USE_YIELD
#define MAX_CHILDREN 32
#define LARGE_TICKET_COUNT 100000
#define MAX_YIELDS_FOR_SETUP 100

__attribute__((noreturn))
void yield_forever() {
    while (1) {
        yield();
    }
}

__attribute__((noreturn))
void run_forever() {
    while (1) {
        __asm__("");
    }
}

int spawn(int tickets) {
    int pid = fork();
    if (pid == 0) {
        ps(tickets);
        yield();
#ifdef USE_YIELD
        yield_forever();
#else
        run_forever();
#endif
    } else if (pid != -1) {
        return pid;
    } else {
        printf(2, "error in fork\n");
        return -1;
    }
}

int find_index_of_pid(int *list, int pid) {
    for (int i = 0; i < NPROC; ++i) {
        if (list[i] == pid)
            return i;
    }
    return -1;
}

void wait_for_ticket_counts(int num_children, int *pids, int *tickets) {
    for (int yield_count = 0; yield_count < MAX_YIELDS_FOR_SETUP; ++yield_count) {
        yield();
        int done = 1;
        struct pstat info;
        ps(&info);
        for (int i = 0; i < num_children; ++i) {
            int index = find_index_of_pid(info.pid, pids[i]);
            if (info.tickets[index] != tickets[i]) done = 0;
        }
        if (done)
            break;
    }
}

int main(int argc, char *argv[])
{
    if (argc < 3) {
        printf(2, "usage: %s seconds tickets1 tickets2 ... ticketsN\n"
                  "       seconds is the number of time units to run for\n"
                  "       ticketsX is the number of tickets to give to subprocess N\n",
                  argv[0]);
        exit();
    }
    int tickets_for[MAX_CHILDREN];
    int active_pids[MAX_CHILDREN];
    int num_seconds = atoi(argv[1]);
    int num_children = argc - 2;
    if (num_children > MAX_CHILDREN) {
        printf(2, "only up to %d supported\n", MAX_CHILDREN);
        exit();
    }
    /* give us a lot of ticket so we don't get starved */
    ps(LARGE_TICKET_COUNT);
    for (int i = 0; i < num_children; ++i) {
        int tickets = atoi(argv[i + 2]);
        tickets_for[i] = tickets;
        active_pids[i] = spawn(tickets);
    }
    wait_for_ticket_counts(num_children, active_pids, tickets_for);
    struct pstat before, after;
    ps(&before);
    sleep(num_seconds);
    ps(&after);
    for (int i = 0; i < num_children; ++i) {
        kill(active_pids[i]);
    }
    for (int i = 0; i < num_children; ++i) {
        wait();
    }
    exit();
}