#include <stdio.h>
#include <unistd.h>

int main(void){
    printf("Nola\n");
    printf("Estoy booteando \"supuestamente\" desde el PID 1\n");
    printf("Saludos,\n");

    printf("PID actual: %d\n", getpid());

    while(1){
        pause();
    }

    return 0;
}