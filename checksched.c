// #include "types.h"
// #include "stat.h"
// #include "user.h"
// #include "fcntl.h"
// #include "pstat.h"

// int main(int argc, char * argv[])
// {
//     int pid;
//     int n = 1;
    
//     int padding = 0;
//     if(argc >= 2) {
//         padding = 1;
//         n = atoi(argv[1]);
//     }

//     for(int i = 0; i < n; i++) {
//         pid = fork();
//         printf(1, "%d : pid \n", pid);
//         if(pid < 0) {
//             // this is the error branch
//             printf(1, "process : %d ; failed to reproduce\n", getpid());
//         }
//         else if(pid > 0) {
//             // this is the parent branch
//             printf(1, "process : %d ; created child : %d\n", getpid(), pid);
//         }
//         else {
//             // this is the children branch
//             printf(1, "process : %d ; is a child\n", getpid());
//             if(argc >= (2 + i + padding)) {
//                 settickets(atoi(argv[1 + i + padding]));
//                 printf(1, "%d tickets set to child : %d", atoi(argv[1 + i + padding]), getpid());
//             }

//             for(;;) {
//                 // do nothing
//             }
//         }
//     }
//     wait(); // wait for the children to return
//     exit();
// }

#include "types.h"
#include "stat.h"
#include "user.h"
#include "pstat.h"

const int child_cnt = 5;

__attribute__((noreturn))
void function() {
    while(1){
        __asm__("");
    }
}

int
main(int argc, char *argv[])
{
    int pids[child_cnt];

    for(int i = 0; i<child_cnt; i++){
        int p;
        if((p = fork()) == 0){
            settickets(5-i);
            function();
        }
        else if(p < -1){
            printf(1, "oh no \n");
        }
        else {
            pids[i] = p;
        }
    }


    sleep(500);

    struct pstat info;
    getpinfo(&info);

    for(int i = 0; i<child_cnt; i++){
        for(int j = 0; j<NPROC; j++){
            if(info.inuse[j] == 1 && info.pid[j] == pids[i]){
                printf(1, "%d %d %d\n", info.pid[j], info.tickets[j], info.ticks[j]);
                break;
            }
        }
    }

    for(int i = 0; i<child_cnt; i++){
        kill(pids[i]);
    }

    for(int i = 0; i<child_cnt; i++){
        wait();
    }
    exit();
}
