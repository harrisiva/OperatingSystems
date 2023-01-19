// copies contents of file to a destination file (same file type so just copy paste the file with a filename given by the user)
// read data from one file and copy it to another (open and read or just copy and rename)
#include <stdio.h>
#include <fcntl.h>
#include <string.h>


int main(int argc, char *argv[] ){
    if (argc==3){ // If the right number of inputs were provided

        // Set different filenames based on the user args
        char inputFilename[300]; strcpy(inputFilename,argv[1]);
        char outputFilename[300]; strcpy(outputFilename,argv[2]);

        // Open both the input and output file (handle errors) and set a DIR pointer to the files
        // Store the int response (file_descriptor)
        if (open(outputFilename, O_RDWR | O_APPEND | O_CREAT | 0700)!=-1){ printf("Created or opened file successfully");} // Create the output file
        else {printf("Failed to create or open file");}

        
        // Open the input file (check if it opens)

        // Create the output file, open it and set a DIR pointer to it (check if success)
        // Iterate over contents of input file (handle errors)
            // Copy to output file (handle errors)



    } else { // If the wrong number of inputs are provided, display an output message
        printf("Invalid number of input parameters");
    }
    
    return 0;
}