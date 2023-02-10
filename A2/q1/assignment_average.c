/*
    Name: Harriharan Sivakumar
    Student ID: 200676770
    Date: 2023-02-09
*/
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>


int main(int arg1, char *arg2[]) {
    
	//Initialize variables
	int cols = 0;
	char *row_num;
	char *filename;

	int finalRow = 0;
	int grades[10][10];
	
	int total_cols = 0;
	char buf[25];

	if (arg1>2 || arg1<2) {printf("Incorrect number of arguments given, please try again.\n");return 1;}
	filename = arg2[1];

	FILE *fp = fopen(filename, "r"); // open file to read for grades
	int array_grade;
	int grade_num = 0;
	while ((row_num = fgets(buf, sizeof(buf), fp)) != NULL) {
		while (sscanf(row_num, "%d%n", &array_grade, &grade_num) == 1) {
			grades[finalRow][cols] = array_grade;  
			if (finalRow == 0)
				total_cols++;
			row_num += grade_num;
			cols++;
		}
		finalRow++;
		cols = 0;
	}

    // close file after reading grades
	fclose(fp);

	
	for (int i = 0; i < finalRow; i++) { //iteration
		int gradTA = fork();
		if (gradTA < 0) {
			printf("Failed to fork gradTA");
		} else if (gradTA == 0) {
		
			for (int hw = 0; hw < total_cols; hw++) { //iteration 

				int numTA = fork();
			
				if (numTA < 0) {
					printf("Failed to fork TA");
				}
				
				else if (numTA == 0) {
				
					int gradesum = 0;
					for (int j = 0; j < finalRow; j++) {
						gradesum += grades[j][hw];
					}
					double grade_avg = (double) gradesum / finalRow;
					printf("Assignment %d - Average = %f \n", hw + 1,grade_avg);
					grade_avg = 0;
					break;
				}
				
				else if (numTA > 0) {
					wait(NULL);
				}
			}
			break;
		} else if (gradTA > 0) {
			wait(NULL);
			break;
		}
	}
	return 0;
}