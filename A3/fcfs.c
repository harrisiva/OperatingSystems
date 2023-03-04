#include <stdio.h>
#include <stdlib.h>

struct threadInfo{
    int p_id;
    int arr_time;
    int burst_time;
    int waiting_time;
    int turn_around_time;
};

int main(){
    printf("Hello World\n");
    // need to read the file and create the required struct 
    // (use A1 code so you do everything at a system level)
    // for now base it with normal file reading systems

    // create the following variables:
        // execution and waiting queues
        // program counter (to simulate system time)

    // read lines of the file
    // iterate over each line
    // create a struct object for said object
    // place it in execution queue (i.e., update program counter)
    // move to next (if its one greater than previous arrival, place it in the execution queue)


    // need to just process the file, perform the calculations, and return the output
    struct threadInfo new;
    new.arr_time=1;

    return 0;
}