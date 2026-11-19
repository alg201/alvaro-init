#ifndef POWEROFF_H
#define POWEROFF_H
#include <linux/reboot.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <stdio.h>

void handle_poweroff(char* type);

#endif