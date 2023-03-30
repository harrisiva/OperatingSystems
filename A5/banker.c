#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <stdbool.h>

// Standardized output messages (e.x. invalid input)
char MSG_INVALID_INPUT[] = "Invalid input, use one of RQ, RL, Status, Run, Exit\n";
char MSG_SAFE_STATE[] = "State is safe, and request is satisfied\n";
char MSG_THREAD_FINISHED[] =  "Thread has finished\n";
char MSG_THREAD_STARTED[] = "Thread has started\n";
char MSG_THREAD_RELEASED[] = "Thread is releasing resources\n";
int ROWS = 0;
int COLS = 0;


// Required functions:
//  func load_max: loads maximum resources per resource type (hard: Dynamic number of customers and resources)
//  func validate_max: check if request is under max number of resources per thread
void print_matrix(int matrix[ROWS][COLS], int h, int w) {
    int i, j;
    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            printf("%d", matrix[i][j]);
        }
        printf("\n");
    }
}
//  func check_safe_state: check safety state criteria (safety algorithm)
//  func thread_f: function called by thread (refer to requirements)
//  func run_safe_sequence: run safe sequence based on the current state and make all threads run the given function 

// max resources types (list len), max resources per resource type list seperted
int main(int argc, char *argv[]){ // arguments taken when invoked (argv) -- LAST ITERATION
    // Open File
    FILE *file;
    file = fopen("sample_in_banker.txt", "r");
    
    // get input for the number of customers
    int max_customers;
    printf("Number of Customers: ");
    scanf("%d",&max_customers);

    // TODO_LATER: get max for each customer from sample_in_banker.txt (skipping and loading into 2d list now)
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

    // print currently available resources (argv) (includes the . right now)
    printf("Currently Available Resources: ");
    for (int i=1;i<argc;i++){
        printf("%c ", *argv[i]);
    } printf("\n");

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