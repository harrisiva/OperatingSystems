#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
    pid_t pid;
    pid = fork();
    if (pid<0){
        printf("Fork Failed");
        return 1;
    } else if (pid==0){
        printf(stdout, "Created Child");
        execlp("/bin/ls","ls",NULL);
        printf(stdout,"Executed execlp");
    } else {
        wait(NULL);
        printf(stdout,"Child Complete");
    }

    // Read text file using kernel commands (from A1 filecopy)
    // create 2d matrix/array of grades 
    // [[grade_set_1],[grade_set_2]] <- parent
    // [[chapter_1_grades], [chapter_2_grades]] <- grad TA (==num_of_grades_in_grade_set/2)
    // [[assignment_1_grades], [assignment_2_grades]] <- TA process (==num_of_assignment_grades) 
    // calculate average, print, and terminate child process

    return 0;
}