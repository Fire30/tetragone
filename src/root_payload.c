#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "log.h"

int main() {

    int kmsg_fd = 0;
    char msg[0x1000] = {};

    LOGV("starting root_payload");

    kmsg_fd = open("/dev/kmsg", O_WRONLY);
    LOGV("kmsg_fd = %d", kmsg_fd);

    strcpy(msg, "We are in root payload!\n");
    write(kmsg_fd, msg, strlen(msg) + 1);

    sprintf(msg, "pid: %d, uid: %d\n", getpid(), getuid());
    write(kmsg_fd, msg, strlen(msg) + 1);

    close(kmsg_fd);

    return 0;
}