#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
    int fd = open("systemlog.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    char message[] = "System Event Recorded\n";

    if (fd < 0) {
        perror("Open failed");
        return 1;
    }

    if (write(fd, message, sizeof(message) - 1) < 0) {
        perror("Write failed");
        close(fd);
        return 1;
    }

    if (close(fd) < 0) {
        perror("Close failed");
        return 1;
    }

    return 0;
}
