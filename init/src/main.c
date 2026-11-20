#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "poweroff/poweroff.h"
#include "logger/logger.h"
#define INVALID_STATUS -1

int main(int argc, char** argv){
    pid_t actualpid = getpid();

    printf("PID actual: %d\n", actualpid);
    if(actualpid != 1){
        perror("I'm not PID 1, exiting\n");
        perror("If this shows up during the boot, then you are in a very big trouble\n");
        return INVALID_STATUS; // not being PID 1 is problematic
    }

    while(1){
        char operation[32] = {0};
        printf("> ");
        int readbytes = scanf("%31s", operation);
        if(readbytes == EOF){
            printf("scan died\n");
            return INVALID_STATUS;
        }
        if (readbytes != 1){
            printf("what?\n");
            continue;
        }
        if(strcmp(operation, "poweroff") == 0 || strcmp(operation, "reboot") == 0){
            int result = handle_poweroff(operation);
            if(result != POWEROFF_OK && handle_poweroff("halt") != POWEROFF_OK){
                return INVALID_STATUS;
            }
        }else{
            printf("what command are you trying to use?\n");
        }
    }

    return 0;
}