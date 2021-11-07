#define _GNU_SOURCE
#include <sched.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 10000
#define CYCLES 10
char child_stack[STACK_SIZE+1];

void print(const char *text){
    for(int i=0 ; i < CYCLES ; i++){
        printf("Hello %s\n", text);
        usleep(1000000);
    }
}

int child1(void *parent){
    print("child 1 thread");
}

int child2(void *parent){
    print("child 2 thread");
}

// int child3(void *parent){
//     print("child 3 thread");
// }

int main(){
    int result1 = clone(child1,child_stack+STACK_SIZE,CLONE_PARENT,0);
    int result2 = clone(child2,child_stack+STACK_SIZE,CLONE_PARENT,0);
    // int result3 = clone(child3,child_stack+STACK_SIZE,CLONE_PARENT,0);
    printf("clone result1 = %d\n",result1);
    printf("clone result2 = %d\n",result2);
    // printf("clone result = %d\n",result3);
    print("parent");
    return 0;
}