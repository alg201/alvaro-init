#ifndef POWEROFF_H
#define POWEROFF_H
#define POWEROFF_OK 0
#include <asm-generic/errno-base.h>
#include <linux/reboot.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

int handle_poweroff(char* type);

#endif