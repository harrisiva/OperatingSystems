#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <string.h>
#define INT_MAX 1000

char FILENAME[] = "sample_in_banker.txt";

// Standardized output messages (e.x. invalid input)
char MSG_INVALID_INPUT[] = "Invalid input, use one of RQ, RL, Status, Run, Exit\n";
char MSG_SAFE_STATE[] = "State is safe, and request is satisfied\n";
char MSG_THREAD_FINISHED[] =  "Thread has finished\n";
char MSG_THREAD_STARTED[] = "Thread has started\n";
char MSG_THREAD_RELEASED[] = "Thread is releasing resources\n";

int ROWS = 0;
int COLS = 0;
void print_matrix(int matrix[ROWS][COLS], int h, int w) {
    int i, j;
    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            printf("%d", matrix[i][j]);
        }
        printf("\n");
    }
}

// Required functions:
//  func load_max: loads maximum resources per resource type (hard: Dynamic number of customers and resources)
//  func validate_max: check if request is under max number of resources per thread
//  func check_safe_state: check safety state criteria (safety algorithm) + DS
//  func thread_f: function called by thread (refer to requirements)
//  func run_safe_sequence: run safe sequence based on the current state and make all threads run the given function 

// max resources types (list len), max resources per resource type list seperted
int main(int argc, char *argv[]){ // arguments taken when invoked (argv) -- LAST ITERATION
    // Open File
    FILE *file;
    file = fopen("sample_in_banker.txt", "r");
    
    // get and set the maximum number of processes (number of resources) and customers
    int max_processes = argc-1;
    int max_customers;
    printf("Number of Customers: ");
    scanf("%d",&max_customers);

    // set "data structure" for bankers algorithm
    int available[max_processes]; // status of each thread
    int max[max_customers][max_processes]; // i=Thread, j=Resource
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

    // Pull from file
    int w, h;
    char line[256], *number;
    int matrix[max_customers][argc];
    ROWS = max_customers;
    COLS = argc;
    h = 0;
    while (!feof(file))
    {
        w = 0;
        fscanf(file, "%s", line);
        number = strtok(line, ",");
        while (number != NULL) 
        {
            matrix[h][w] = atoi(number);
            w++;
            number = strtok(NULL, ",");
        }
        h++;
    }
    print_matrix(matrix, h, w);

    fclose(file);

    // Enter loop for commands
    char command[INT_MAX];
    while (strcmp(command, "Exit")!=0){
        
        // Get command from user
        printf("Enter Command: ");
        scanf("%s",command);
    
        if (strcmp(command,"Exit")==0){break;}; // if command is exit, break the loop 

        // Extract details from the command for processing
        // Command type 
        // Command parameters (load into int array from the terminal)

        // If RQ (request), check if command satisfies the following:
        //      thread does not request more than maximum number of resources allocated to itself
        //      thread does not make a request that leaves the system unsafe (denied, print error statement)
        // Print safe message and update "DS"

        // If RL (release), release resources and "DS", print success message

        // Status, print all arrays and matrices used as "DS"

        // If Run, 

    }

    // Cleanup portion of the program
    
    
    
    
    

    // TODO:
    // Initiative maximum array to the values based on the sampe in banker input file (function)

    // Enter while loop (while input not Exit) to handle ds (bankers and other algorithms)
    //      Assume input follows format 

    //      If request, Check if request is under max number of resources per thread (function)
    //      Check if request meets system safe critera (safety algorithm from ch.8) and print message in main (function)

    //      If release, release resources and update DS accordingly

    //      If status, print all arrays and matrices used (available, maximum, allocation, and need)

    //      If run, execute the safe sequence based on the current state and all threads should run the same **function** code (just prints, no global/critical sections)
    //          Run the commands (create thread for each) and run a mutual function (prints contents similar to status) 

    return 0;
}