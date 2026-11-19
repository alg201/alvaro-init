#include "poweroff.h"
#include <linux/reboot.h>

int handle_poweroff(char* type){
    int result = 0;
    if(strcmp(type, "poweroff") == 0)
        result = syscall(SYS_reboot, LINUX_REBOOT_MAGIC1, LINUX_REBOOT_MAGIC2, LINUX_REBOOT_CMD_POWER_OFF);
    if(strcmp(type, "reboot") == 0)
        result = syscall(SYS_reboot, LINUX_REBOOT_MAGIC1, LINUX_REBOOT_MAGIC2, LINUX_REBOOT_CMD_RESTART);
    if(strcmp(type, "halt") == 0)
        result = syscall(SYS_reboot, LINUX_REBOOT_MAGIC1, LINUX_REBOOT_MAGIC2, LINUX_REBOOT_CMD_HALT);
    if(result == -1){
        if (errno == EINVAL) {
            printf("poweroff failed!\n");
        } else if (errno == EPERM) {
            printf("Failed permissions!\n");
        } else {
            printf("Errno code: %d\n", errno);
        }
        return errno;
    }

    return POWEROFF_OK;
}