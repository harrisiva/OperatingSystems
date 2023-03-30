#include <stdio.h>
#include <stdlib.h>

// Standardized output messages (e.x. invalid input)
char MSG_INVALID_INPUT[] = "Invalid input, use one of RQ, RL, Status, Run, Exit\n";
char MSG_SAFE_STATE[] = "State is safe, and request is satisfied\n";
char MSG_THREAD_FINISHED[] =  "Thread has finished\n";
char MSG_THREAD_STARTED[] = "Thread has started\n";
char MSG_THREAD_RELEASED[] = "Thread is releasing resources\n";

// Required functions:
//  func load_max: loads maximum resources per resource type
//  func validate_max: check if request is under max number of resources per thread
//  func check_safe_state: check safety state criteria (safety algorithm)
//  func thread_f: function called by thread (refer to requirements)
//  func run_safe_sequence: run safe sequence based on the current state and make all threads run the given function 

int main(){
    // arguments taken when invoked (argv) -- LAST ITERATION
    //  create a vector/array with the number of resources (value) per resource types (location) (function?) -- LAST ITERATION

    // TODO:
    // Initiative maximum array to the values based on the sampe in banker input file (function)

    // Enter while loop (while input not Exit) to handle ds (bankers and other algorithms)
    //      Assume input follows format 

    //      If request, Check if request is under max number of resources per thread (function)
    //      Check if request meets system safe critera (safety algorithm from ch.8) and print message in main (function)

    //      If release, release resources and update DS accordingly

    //      If status, print all arrays and matrices used (available, maximum, allocation, and need)

    //      If run, execute the safe sequence based on the current state and all threads should run the same **function** code (just prints, no global/critical sections)
    
    return 0;
}