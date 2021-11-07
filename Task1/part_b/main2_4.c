#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){

    int pid, pid1, pid2;
  
    pid = fork();
  
    if (pid == 0) {
        char *args[2] = {"./main2_1", NULL};
        execvp(args[0],args);
    }
    else {
        pid1 = fork();
        if (pid1 == 0) {
            char *args[2] = {"./main2_2", NULL};
            execvp(args[0],args);
        }
        else {
            pid2 = fork();
            if (pid2 == 0) {
                char *args[2] = {"./main2_3", NULL};
                execvp(args[0],args);
            }
            else {
                sleep(3);
            }
        }
    }
  
    return 0;
}