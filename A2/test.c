#include <stdio.h>
#include <stdlib.h>

int main(){


    // assuming static number of students, chapters and assignments for now
    int MAX_STUDENTS = 10;
    int MAX_CHAPTERS = 3; 
    int MAX_ASSIGNMENTS = 2;
    
    // declare 2d array (matrix) for storing grades
    int sample_in_grades[MAX_STUDENTS][MAX_CHAPTERS*MAX_ASSIGNMENTS];

    // open file to read for grades
    FILE *sample_file;
    sample_file = fopen("sample_in_grades.txt", "r");
    // exit program if file failed to open
    if (sample_file==NULL){printf("Failed to read file.\n");exit(0);}

    // to read grades into 2d array [students][grades] <- parrent process
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


    // Read text file using kernel commands (from A1 filecopy)
    // create 2d matrix/array of grades 
    // [[grade_set_1],[grade_set_2]] <- parent
    // [[chapter_1_grades], [chapter_2_grades]] <- grad TA (==num_of_grades_in_grade_set/2)
    // [[assignment_1_grades], [assignment_2_grades]] <- TA process (==num_of_assignment_grades) 
    // calculate average, print, and terminate child process
    return 0;
}