#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>


int main(int arg1, char *arg2[]) {
    
	//variables initialization
	int cols = 0;
	char *row_num;
	int finalRow = 0;
	int final_grades[10][10];
	char *fileInput = arg2[1];
	int total_cols = 0;
	char buf[25];

	if (arg1 > 2) {
		printf("Wrong Usage: give proper arguments\n");
		return 1;
	}
	
	int filevar = access(fileInput, F_OK);
	if (filevar != 0) { //if filevar equals 0 fails to access file
		printf("Access failed %s file", fileInput);
		return 0;
	} else {
		int fd = open(fileInput, O_RDWR, S_IRWXU);
		if (fd == -1) {
			perror("File not opened: Error"); //error if -1
		}
		close(fd);
	}

	FILE *txt_fd = fopen(fileInput, "r"); //opening file for reading
	int array_grade;
	int grade_num = 0;
	while ((row_num = fgets(buf, sizeof(buf), txt_fd)) != NULL) {

		while (sscanf(row_num, "%d%n", &array_grade, &grade_num) == 1) {

			final_grades[finalRow][cols] = array_grade;  
			if (finalRow == 0)
				total_cols++;
			row_num += grade_num;
			cols++;
		}
		finalRow++;
		cols = 0;
	}

	fclose(txt_fd);

	
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
						gradesum += final_grades[j][hw];
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