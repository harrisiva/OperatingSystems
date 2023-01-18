#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>


int main() {

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