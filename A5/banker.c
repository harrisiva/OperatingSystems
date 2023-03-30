#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INT_MAX 1000

char FILENAME[] = "sample_in_banker.txt";

// Standardized output messages (e.x. invalid input)
char MSG_INVALID_INPUT[] = "Invalid input, use one of RQ, RL, Status, Run, Exit\n";
char MSG_SAFE_STATE[] = "State is safe, and request is satisfied\n";
char MSG_THREAD_FINISHED[] =  "Thread has finished\n";
char MSG_THREAD_STARTED[] = "Thread has started\n";
char MSG_THREAD_RELEASED[] = "Thread is releasing resources\n";

// Required functions:
//  func load_max: loads maximum resources per resource type (hard: Dynamic number of customers and resources)
//  func validate_max: check if request is under max number of resources per thread
//  func check_safe_state: check safety state criteria (safety algorithm) + DS
//  func thread_f: function called by thread (refer to requirements)
//  func run_safe_sequence: run safe sequence based on the current state and make all threads run the given function 

// max resources types (list len), max resources per resource type list seperted
int main(int argc, char *argv[]){ // arguments taken when invoked (argv) -- LAST ITERATION
    
    // get and set the maximum number of processes (number of resources) and customers
    int max_processes = argc-1;
    int max_customers;
    printf("Number of Customers: ");
    scanf("%d",&max_customers);

    // set "data structure" for bankers algorithm
    int available[max_processes];
    int max[max_customers][max_processes]; 
    int allocation[max_customers][max_processes];
    int need[max_customers][max_processes];

    // Load available resources per resource type from argv to the available array
    printf("Currently Available Resources:");
    for (int i=0;i<max_processes;i++){available[i] = atoi(argv[i+1]);printf(" %i", available[i]);}printf("\n"); 
    
    int max_resources[5][4] = { // Hard coded max resources for now 
        {6,4,7,3},
        {4,2,3,2},
        {2,5,3,3},
        {6,3,3,2},
        {5,5,7,5}
    };

    // Enter loop for commands
    char command[INT_MAX];
    while (strcmp(command, "Exit")!=0){
        printf("Enter Command: ");
        scanf("%s",command);
        printf("Command: %s\n", command);
    }

    // Exit function here (or exit processes/thread handling)

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