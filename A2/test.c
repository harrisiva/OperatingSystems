#include <stdio.h>
#include <stdlib.h>

// assuming static number of students, chapters and assignments (for now)
#define MAX_STUDENTS 10
#define MAX_CHAPTERS 3
#define MAX_ASSIGNMENTS 2

int main(){
    // TODO, create shared memory ??? 
    
    // declare 2d array (matrix) for storing grades
    int sample_in_grades[MAX_STUDENTS][MAX_CHAPTERS*MAX_ASSIGNMENTS];

    // open file to read for grades
    FILE *sample_file;
    sample_file = fopen("sample_in_grades.txt", "r");
    // exit program if file failed to open
    if (sample_file==NULL){printf("Failed to read file.\n");exit(0);}

    // to read grades into 2d array [students][grades] <- teacher process
    int i; int j;
    for (i=0;i<MAX_STUDENTS;i++){ 
        for (j=0;j<MAX_CHAPTERS*MAX_ASSIGNMENTS;j++){
            fscanf(sample_file, "%d ", &sample_in_grades[i][j]);;
        } 
    }

    // close file after reading grades
    fclose(sample_file);
    
    // print contents of array for debugging
    for (i=0;i<MAX_STUDENTS;i++){ 
        for (j=0;j<MAX_CHAPTERS*MAX_ASSIGNMENTS;j++){
            printf("%i ",sample_in_grades[i][j]);
        } printf("\n");
    }

    // since we assume the number of chapters will remain constant,
    // we need to create child processes for Grad TA
    // give a set of chapters to grad TA
    // each chapter set is stored in two rows
    // iterate over number of students and pick the row pairs you want

    


    // [[grade_set_1],[grade_set_2]] <- parent
    // [[chapter_1_grades], [chapter_2_grades]] <- grad TA (==num_of_grades_in_grade_set/2)
    // [[assignment_1_grades], [assignment_2_grades]] <- TA process (==num_of_assignment_grades) 
    // calculate average, print, and terminate child process
    return 0;
}