#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
#include "pstat.h"

int main(void){
    struct pstat stat = {0};
    getpinfo(&stat);
    printf(1, "pid\tticket\tticks \n");
    for(int i = 0; i < NPROC; i++) {
        if(stat.inuse[i]) {
            printf(1, "%d \t %d \t %d \n", stat.pid[i], stat.tickets[i], stat.ticks[i]);
        }
    }
    exit();
}