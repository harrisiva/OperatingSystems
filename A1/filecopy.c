// copies contents of file to a destination file (same file type so just copy paste the file with a filename given by the user)
// read data from one file and copy it to another (open and read or just copy and rename)
#include <stdio.h>


int main(int argc, char *argv[] ){
    char inputFilename[300];
    char outputFilename[300];

    // Check number of variables supplied and then set them
    for (int i=0;i<argc;i++){
        printf("%s\n",argv[i]);
    }
    
    return 0;
}