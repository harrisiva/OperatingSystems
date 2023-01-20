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

        // Remove the output file (if it exists, the function will work, else it will just return -1 but we ignore this) (cheap alternative to using the access function)
        remove(outputFilename);

        // Open the required files and store their file descriptor <- used for read, write, and close system calls
        int fd_to_read = open(inputFilename,O_RDONLY);
        int fd_to_write = open(outputFilename, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR); // Create output file and open it for reading only (other flags meaning??? <- something to do with file access control OS side)

        // Error handling related to opening files
        if (fd_to_read == -1 || fd_to_write == -1){
            printf("Failed to open one of the files\n");
            return -1;
        }
        
        // Transfer (read and write) bytes (file data)
        char c;
        int bytes;
        while ((bytes = read(fd_to_read, &c, sizeof(c)))>0){
            write(fd_to_write, &c,sizeof(c));
        }
        
        // Close both the files
        close(fd_to_read);
        close(fd_to_write);

        printf("The contents of file %s have been successfully copied into the %s file\n", inputFilename, outputFilename);

    } else { // If the wrong number of inputs are provided, display an output message
        printf("Insufficient parameters passed.\n");
    }
    
    return 0;
}