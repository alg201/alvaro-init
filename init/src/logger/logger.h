#ifndef LOGGER_H
#define LOGGER_H
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

enum e_fds{
    CONSOLE,
    KMSG,
    NULL_FD
};

enum fds_errors{
    NO_ERROR = 0b000,
    CONSOLE_COULD_NOT_BE_OPEN = 0b001,
    KMSG_COULD_NOT_BE_OPEN = 0b010,
    NULL_IS_NOT_NULL = 0b100
};

enum fds_errors open_fds();

#endif