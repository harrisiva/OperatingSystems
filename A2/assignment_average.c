#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

// figure out structure for the multi processing (handle multiple nested child processes) and then bring in code from test.c
int main(){
    // pid_t pid; // at the start of the script, same in either case
    if (fork()==0){ // in grad TA process
        printf("In GradTA 1\n");
        int i;
        for (i=0;i<2;i++){
        if (fork()==0){
            printf("In TA Layer%i\n");
        } else {
            printf("In TA's GradTA calling wait\n");
            wait(NULL);
            printf("In TA's GradTA, wait finished\n");
        }
        }

    }  else { // in teacher process
        printf("In teacher, calling wait\n");
        // set up the shared memory (PRODUCER) with the matrix
        wait(NULL);
        printf("Wait finished\n");
    }

    // Read text file using kernel commands (from A1 filecopy)
    // create 2d matrix/array of grades 
    // [[grade_set_1],[grade_set_2]] <- parent
    // [[chapter_1_grades], [chapter_2_grades]] <- grad TA (==num_of_grades_in_grade_set/2)
    // [[assignment_1_grades], [assignment_2_grades]] <- TA process (==num_of_assignment_grades) 
    // calculate average, print, and terminate child process

    return 0;
}