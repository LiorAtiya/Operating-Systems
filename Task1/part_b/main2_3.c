#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <syslog.h>

int main(){
    __pid_t pid = fork();
    //We are in child
    if(pid == 0){

        //Move to root dir. used to not block the file system
        chdir("/");

        //Move the child to another session, so the parent may be closed
        setsid();

        printf("starting my daemon\n");

        //Close output chanels
        close(stdout);
        close(stdin);
        close(stderr);

        //Open log and put something
        openlog("myDaemon", LOG_PID, LOG_DAEMON);
        syslog(LOG_NOTICE, "daemon started");
        usleep(3000000);
        syslog(LOG_NOTICE, "Second update of log");
        usleep(3000000);
        syslog(LOG_NOTICE, "Third update of log");
    }else{ //We are the parent
        printf("daemon PID %d\n",pid);
    }

    return 0;
}