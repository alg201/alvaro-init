#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "poweroff/poweroff.h"

int main(void){
    printf("Nola\n");
    printf("Estoy booteando \"supuestamente\" desde el PID 1\n");
    printf("Saludos,\n");

    printf("PID actual: %d\n", getpid());

    while(1){
        char operation[32] = {0};
        int readbytes = scanf("%31s", operation);
        if (readbytes == -1){
            printf("what?\n");
            continue;
        }
        if(strcmp(operation, "poweroff") == 0 || strcmp(operation, "reboot") == 0){
            handle_poweroff(operation);
        }
    }

    return 0;
}