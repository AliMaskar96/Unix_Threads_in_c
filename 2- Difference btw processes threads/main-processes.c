#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char* argv[])
{
    int x = 2;
    int pid = fork();
    if (pid == -1) {
        return 1;
    }
    
    if (pid == 0) {
        x++;
    }
    sleep(2);
    printf("Value of x: %d\n", x);
    if (pid != 0) {
        wait(NULL);
    }
    return 0;
}


// Process:

// Processes are basically the programs that are dispatched from the ready state and are scheduled in the CPU for execution. 
// PCB(Process Control Block) holds the concept of process. A process can create other processes which are known as Child Processes.
// The process takes more time to terminate and it is isolated means it does not share the memory with any other process. 

// The process can have the following states new, ready, running, waiting, terminated, and suspended. 