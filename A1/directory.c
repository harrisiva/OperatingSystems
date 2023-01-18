#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>


const char MENU[] = "Select the option(s) appropriately by entering the number:\n Enter 1 for creating a directory\n Enter 2 for removing directory\n Enter 3 for printing working directory\n Enter 4 for changing directory one level up\n Enter 5 for reading the contents of directory\n Enter 6 for closing the current directory\n Enter q to exit the program"; 

int main() {

    // present user with the list of options to select directory operations, keep looping until user enters q (print menu and ask for input, exit if input ==q)
    // Set the userSelection to initially be nothing, so you enter the loop and keep running until you hit the q value, add error handling as well
    char userSelection[1];

    while (userSelection[0]!='q'){
        printf("%s\n", MENU);
        scanf("%s",userSelection);
        // check length (invalid error handling)
        if (userSelection[0]!='q') {
            switch (userSelection[0])
            {
            case '1':
                printf("Directory Operation for 1\n");
                break;
            default:
                printf("Default Condition\n");
                break;
            }
        }
    }




    // create a directory
    //mkdir("test", 0700); // 0700 is the mode, not sure what it exactly means but mkdir is the command we want, same in linux

    // remove a directory
    //rmdir("test");

    // get current working directory
    //char cwd[10000];
    //getcwd(cwd, sizeof(cwd));
    //printf("%s",cwd);

    // change a directory (one level up current)
    // char cwd[10000];
    // getcwd(cwd, sizeof(cwd));
    // printf("%s\n",cwd);

    // chdir("..");

    // char cwd2[10000];
    // getcwd(cwd2, sizeof(cwd2));
    // printf("%s\n",cwd2);



    // Read a directory
    // Print contents of a directory onto the terminal
    // use listdir

    // Close a directory (current)
    // use closedir function

    return 0;
}