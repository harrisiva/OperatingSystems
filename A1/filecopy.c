// copies contents of file to a destination file (same file type so just copy paste the file with a filename given by the user)
// read data from one file and copy it to another (open and read or just copy and rename)
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h> 


int main(int argc, char *argv[] ){
    if (argc==3){ // If the right number of inputs were provided

        // Set different filenames based on the user args
        char inputFilename[300]; strcpy(inputFilename,argv[1]);
        char outputFilename[300]; strcpy(outputFilename,argv[2]);

        // Open both the input and output file (handle errors) and set a DIR pointer to the files
        // Store the int response (file_descriptor)

        // Attempt to open the input file. If this succeeds, proceed to create the output file (if it exists already, raise alert?)

        int input_file_descriptor; 
        if ((input_file_descriptor=open(inputFilename, O_RDONLY, 0700))!=-1){ 
            printf("Opened input file successfully\n");
    
            // Check if the output file already exists, if so, delete it (will be created again down below)
            int result;
            result=access(outputFilename, F_OK);
            if (result!=-1) {
                printf("Output file already exists\n");
                if (remove(outputFilename)!=-1){ // Delete outputfile
                    printf("Successfully deleted existing output file.\n");
                } 
            } 

                int nread;
                char buff[200];
                nread = read(input_file_descriptor,buff,sizeof(buff));
                printf("%d Bytes read\n",nread);
                write(1, buff, nread);

            // Create the output file and open it for reading/writing and appending
            int output_file_descriptor; 
            if ((output_file_descriptor=open(outputFilename, O_APPEND | O_CREAT | 0700))!=-1){ // Create the output file
                printf("Created or opened file (%d) successfully\n",output_file_descriptor);                
                int close_response;
                close_response = close(output_file_descriptor); // Close output file after operating on it
                printf("Closed (%d)\n",close_response);

            } else {printf("Failed to create and open the output file\n");}

            close(input_file_descriptor); // Close input file after operating on it

        } else {
            printf("Failed to open the input file\n");
        }





        // Open the input file (check if it opens)

        // Create the output file, open it and set a DIR pointer to it (check if success)
        // Iterate over contents of input file (handle errors)
            // Copy to output file (handle errors)



    } else { // If the wrong number of inputs are provided, display an output message
        printf("Invalid number of input parameters");
    }
    
    return 0;
}