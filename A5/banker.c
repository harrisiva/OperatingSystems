/**
--------------------------------------
Authors: Aidan Traboulay & Aleksander Neceski
IDs: 200115590 & 201851860
Emails: trab5590@mylaurier.ca & nece1860@mylaurier.ca
--------------------------------------
**/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <stdbool.h>

#define matrixCHAR 21

/*
*
* Global Variables
*
*/
int thread_arr_len = 0; 
int resources = 0;
int **matrix;
int **allocated;
int *available;

/*
*
* Function Prototypes
*
*/
int *get_lines(char *line);
void read_file(FILE** file, int **matrix);
void get_thread_length(FILE **file);
bool safe();
void request_resources(char* buffer);
void release_resources(char* buffer);
void status();
void release_resources(int thread_number);
void run();
void invoke_command(char *prefix, char *buffer);

/*
*
* Get the matrixmimum number of resources from the file
*
*/
int *get_lines(char *line) { 
    int i = 0;
    char *token = strtok(line, ",");
    int *thread_arr = malloc(sizeof(int) * resources);
    thread_arr[i] = atoi(token);

    while ((token = strtok(NULL, ","))) {    
        i += 1;
        thread_arr[i] = atoi(token);
    }
    return thread_arr;
}

/*
*
* Read the file and store the matrix resources in a 2D array
*
*/
void read_file(FILE **file, int **matrix) { 
    ssize_t temp;
    size_t length = 0;
    char *line;
    int *thread_array; 
    int i = 0; 

    while ((temp = getline(&line, &length, *file)) != -1) {
        *(matrix + i) = malloc(sizeof(int) * resources);
        thread_array = get_lines(line);
        for (int j = 0; j < resources; j++) { 
            matrix[i][j] = thread_array[j];
        }
        i += 1;
    }
    return;
}

/*
*
* Determine the length of the thread array
*
*/
void get_thread_length(FILE **file) { 
    ssize_t read;
    size_t length = 0;
    char *line;
    while ((read = getline(&line, &length, *file)) != -1) { 
        thread_arr_len += 1;
    }
    rewind(*file);
    return;
}

/*
*
* Determine if the state is safe
*
*/
bool safe() {
    int work[resources];
    bool finish[thread_arr_len];
    bool is_safe = true;
    int q, h, i;
    for (q = 0; q < resources; q++) {
        work[q] = available[q];
    }
    for (q = 0; q < thread_arr_len; i++) {
        finish[q] = false;
    }
    for (q = 0; q < thread_arr_len; q++) {
        for (h = 0; h < thread_arr_len; h++) {
            if (finish[h] == false) {
                for (i = 0; i < resources; i++) {
                    if (matrix[h][i] - allocated[h][i] > work[i]) {
                        break;
                    }
                }
                if (i == resources) {
                    for (i = 0; i < resources; i++) {
                        work[i] += allocated[j][i];
                    }

                    finish[j] = true;
                }
            }
        }
    }
    for (q = 0; q < thread_arr_len; q++) {
        if (finish[q] == false) {
            is_safe = false;
        }
    }
    return is_safe;
}

/*
*
* Request resources command
*
*/
void request_resources(char *buf) {
    int q;
    bool deny = false;
    
    char* token = strtok(buf, " ");
    token = strtok(NULL, " ");
    int customer_number = atoi(token);
    int customer_resources[resources];
    q = 0;

    while ((token = strtok(NULL, " "))) {   
        customer_resources[q] = atoi(token);
        q++;
    }

    for (q = 0; q < resources; q++) {
        if (customer_resources[q] > matrix[customer_number][q]) {
            deny = true;
        }
    }

    if (deny == false) {
        for (q = 0; q < resources; q++) {
            if (customer_resources[q] > available[q]) {
                deny = true;
            }
        }
    }

    if (deny == false) {
        for (q = 0; q < resources; q++) {
            available[q] -= customer_resources[q];
            allocated[customer_number][q] += customer_resources[q];
        }
    }

    if (deny == true || safe() == false) {
        printf("State is not safe, and request is not satisfied\n");
    } else {
        printf("State is safe, and request is satisfied\n");
    }
    return;
}

/*
*
* Release resources command
*
*/
void release_resources(char *buffer) {
    char* token = strtok(buffer, " ");
    int temp[resources];
    token = strtok(NULL, " "); 
    int thread_num = atoi(token);
    int q = 0;
    while ((token = strtok(NULL, " "))) {   
        temp[q] = atoi(token);
        q++;
    }
    printf("    To release: ");
    for (int i = 0; i < resources; i++) { 
        available[i] += temp[i];
        allocated[thread_num][i] -= temp[i];
        printf("%d ", temp[i]);
    }
    printf("\n");
    printf("    Now available Resources: ");
    for (int i = 0; i < resources; i++) { 
        printf("%d ", available[i]);
    }
    printf("\n");
    printf("    Resources still held by thread: ");
    for (int i = 0; i < resources; i++) { 
        printf("%d ", allocated[thread_num][i]);
    }
    printf("\n");
}

/*
*
* Status command
*
*/
void status() {
    printf("available Resources: \n");
    int i, j; 
    for (i = 0; i < resources; i++) { 
        printf("%d ", available[i]);
    }
    printf("\n");

    printf("matrix Resources: \n");
    for (i = 0; i < thread_arr_len; i++) { 
        for (j = 0; j < resources; j++) { 
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("allocated Resources: \n");
    for (i = 0; i < thread_arr_len; i++) {
        for (j = 0; j < resources; j++) { 
            printf("%d ", allocated[i][j]);
        }
        printf("\n");
    }

    printf("Need Resources: \n");
    for (i = 0; i < thread_arr_len; i++) { 
        for (j = 0; j < resources; j++) { 
            printf("%d ", matrix[i][j] - allocated[i][j]);
        }
        printf("\n");
    }
}

/*
*
* Release thread resources
*
*/
void release_thread_resources(int thread_num) { 
    printf("--> Customer/Thread %d \n", thread_num);
    printf("    allocated resources: ");
    for (int i = 0; i < resources; i++) { 
        printf("%d ", allocated[thread_num][i]);
    }
    
    printf(" \n");

    printf("    Needed: ");
    for (int i = 0; i < resources; i++) {  
        printf("%d ", matrix[thread_num][i] -  allocated[thread_num][i]);
    }

    printf(" \n");

    printf("    available: ");
    for (int i = 0; i < resources; i++) { 
        printf("%d ", available[i]);
    }

    printf(" \n");

    printf("    Thread has started \n");
    printf("    Thread has finished \n");
    printf("    Thread is releasing resources \n");
    for (int i = 0; i < resources; i++) { 
        available[i] += allocated[thread_num][i];
    }

    printf("    New available: ");
    for (int i = 0; i < resources; i++) { 
        printf("%d ", available[i]);
    }

    printf(" \n");
}

/*
*
* Run command
*
*/
void run() {
    int thread_valid;
    int remaining_threads[thread_arr_len];
    int remaining_thread_count = thread_arr_len;
    
    for (int i = 0; i < thread_arr_len; i++) { 
        remaining_threads[i] = i;
    }
    
    int thread_num;
    int counter = 0;

    printf("Safe Sequence: ");
    for (int i = 0; i < thread_arr_len; i++) { 
        printf("%d ", remaining_threads[i]);
    }
    
    printf(" \n");
    
    while (remaining_thread_count > 0 && counter < thread_arr_len) { 
        for (int i = 0; i < remaining_thread_count; i++) { 
            thread_valid = 1;
            thread_num = remaining_threads[i];

            for (int j = 0; j < resources; j++) { 
                if (available[j] < (matrix[thread_num][j] - allocated[thread_num][j])) {
                    thread_valid = 0;
                }
            }

            if (thread_valid == 1) {
                for (; i < remaining_thread_count - 1; i++) { 
                    remaining_threads[i] = remaining_threads[i + 1];
                }

                i++;
                remaining_thread_count -= 1;
                release_thread_resources(thread_num);
            }
        }
        counter++;
    }
}

/*
*
* Command handler
*
*/
void invoke_command(char *prefix, char *buf) { 
    if (strcmp(prefix, "Exit") == 0) {
        exit(0);
    } else if (strcmp(prefix, "Run") == 0) { 
        run();
    } else if (strcmp(prefix, "Status") == 0) { 
        status();
    } else if (strcmp(prefix, "RQ") == 0) { 
        request_resources(buf);
    } else if (strcmp(prefix, "RL") == 0) { 
        release_resources(buf);
    } else { 
        printf("Invalid input, use one of RQ, RL, Status, Run, Exit \n");
    }
}

/*
*
* Main
*
*/
int main(int argc, char **argv) {
    FILE* f;
    f = fopen("sample_in_banker.txt" , "r");

    available = malloc(sizeof(int) * resources);

    if (argc > 1) {
        for (int i = 1; i < argc; i++) { 
            available[i-1] = atoi(argv[i]);
            resources += 1; 
        }
    } else { 
        exit(0);
    }

    get_thread_length(&f);
    matrix = malloc(sizeof(int*) * thread_arr_len);
    read_file(&f, matrix);
    allocated = malloc(sizeof(int*) * thread_arr_len);

    printf("Number of Customers: %d \n", thread_arr_len);
    printf("Currently available Resources: ");
    for (int i = 0; i < resources; i++) { 
        printf("%d ", available[i]);
    }

    printf(" \n");

    printf("matriximum resources from file: \n");
    for (int i = 0; i < thread_arr_len; i++) { 
        allocated[i] = calloc(resources, sizeof(int));
        for (int j = 0; j < resources; j++) { 
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    while (1) {
        char buf[matrixCHAR];                  
        
        fputs ("Enter Command: ", stdout);   
        while (fgets(buf, matrixCHAR, stdin)) {  
            char *buff = malloc(sizeof(char) * matrixCHAR);
            strcpy(buff, buf);
            char *prefix = strtok(buf, " \n");
            invoke_command(prefix, buff);
            fputs ("Enter Command: ", stdout);
        }
    }
}