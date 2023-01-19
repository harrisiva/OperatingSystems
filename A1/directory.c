#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include<dirent.h> 
// Add error handling for the directory contents printing case

const char MENU[] = "Select the option(s) appropriately by entering the number:\n Enter 1 for creating a directory\n Enter 2 for removing directory\n Enter 3 for printing working directory\n Enter 4 for changing directory one level up\n Enter 5 for reading the contents of directory\n Enter 6 for closing the current directory\n Enter q to exit the program"; 

int main() {

    // present user with the list of options to select directory operations, keep looping until user enters q (print menu and ask for input, exit if input ==q)
    // Set the userSelection to initially be nothing, so you enter the loop and keep running until you hit the q value, add error handling as well
    char userSelection[1];
    
    while (userSelection[0]!='q'){
        printf("%s\n", MENU);
        scanf("%s",userSelection);
        // check length (invalid error handling) (will it be diff since we cap it off anyway?)
        if (userSelection[0]!='q') {
            // Get current working directory (make it a variable here so it can be used by the other function calls below)
            switch (userSelection[0])
            {

            char workingDirectoryName[300];
            getcwd(workingDirectoryName, sizeof(workingDirectoryName));

            // Create new directory
            case '1': 
                char newDirectoryName[300];
                printf("Enter the Directory name you want to create:\n");
                scanf("%s",newDirectoryName);
                // Add error handling for the directoryName (no name, invalid (contains dots etc))
                if (mkdir(newDirectoryName, 0700)==0) {
                    printf("Directory is Created Successfuly.\n");
                } else {
                    printf("Failed to create directory\n");
                }
                break; 

            // Remove a existing directory
            case '2': 
                char directoryToRemove[300];
                printf("Enter the Directory name you want to remove:\n");
                scanf("%s",directoryToRemove);
                if (rmdir(directoryToRemove)==0) {
                    printf("Directory is removed Successfuly.\n");
                } else {
                    printf("Failed to remove directory\n");
                }
                break;

            // Print the current working directory
            case '3': // Calling CWD again to meet assignment requirements
                char cwd[300];
                getcwd(cwd, sizeof(cwd)); // Check if this ran successfully, if not print saying it failed
                printf("Current working directory is: %s\n",cwd); 
                break;

            case '4': // Change working directory one up

                printf("Working Directory Before Operation:%s\n",workingDirectoryName);

                if (chdir("..")==0){ // Change the directory and check if the operation was successful
                    printf("Directory Changed Successfully.\n");
                    char directoryNameAfterChange[300];
                    getcwd(directoryNameAfterChange, sizeof(directoryNameAfterChange));
                    printf("Working Directory After Operation:%s\n",directoryNameAfterChange);
                } else {
                    printf("Directory Changed Unsuccessful.\n");
                }
                break;

            case '5': // Print contents of the working directory (TODO: Add error handling)
                DIR* directory = opendir(workingDirectoryName); // Get pointer to the current directory (and open the directory)
                struct dirent *directory_info; // Get information of the current directory
                while ((directory_info=readdir(directory))!=NULL){printf("%s\n",directory_info->d_name);} // Loop over directory info (files) and print their name
                closedir(directory); // Close the directory using the directory pointer (frees up temporary memory)
                break;

            case '6': // Close the working directory
                DIR* currentWrkDirectory = opendir(workingDirectoryName);
                if (closedir(currentWrkDirectory)==0) {printf("Directory closed successfully.\n");} else {printf("Directory closed unsuccessfully.\n");}
                break;

            default:
                printf("Invalid input. Please try again.\n");
                break;
            }
        }
    }

    return 0;
}