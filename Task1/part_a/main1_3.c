#include <stdio.h>
#include <stddef.h>
#include <dlfcn.h>
#include <stdbool.h>

void (*print_message)(const char *);

bool init_library(){
    void *hdl = dlopen("./libHelloAriel.so",RTLD_LAZY);
    if (NULL == hdl) return false;
    print_message = (void(*)(const char *))dlsym(hdl,"print_message");
    if(NULL == print_message) return false;

    return true;
}
int main(){
    if(init_library()) print_message("Library loading was successful\n");
    else printf("Library was not loaded \n");
    return 0;
}