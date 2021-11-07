#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void print(const char *msg){
    for(int i=0 ; i < 10 ; i++){
        printf("%s\n", msg);
        usleep(1000000);
    }
}

int main(){
    //Create child
    pid_t pid = fork();

    //We are in child
    if(pid == 0){
        pid_t pid = fork();
        if(pid == 0){
            print("child");
        }else{
            print("grand child");
        }
    }
    else{
        print("parent");
    }
}