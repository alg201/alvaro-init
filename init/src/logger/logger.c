#include "logger.h"

int __fds[3];
enum fds_errors status = NO_ERROR;

enum fds_errors open_fds(){
    __fds[CONSOLE] = open("/dev/console", O_WRONLY);
    if(__fds[CONSOLE] == -1){
        status |= CONSOLE_COULD_NOT_BE_OPEN;
    }

    __fds[KMSG] = open("/dev/kmsg", O_WRONLY);
    if(__fds[KMSG] == -1){
        status |= KMSG_COULD_NOT_BE_OPEN;
    }

    __fds[NULL_FD] = open("/dev/null", O_WRONLY);
    if(__fds[NULL_FD] == -1){
        status |= NULL_IS_NOT_NULL;
    }

    return status;
}

int log_message(const char* data){

    return 0;
}