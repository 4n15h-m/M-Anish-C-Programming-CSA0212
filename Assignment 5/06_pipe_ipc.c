#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    int fd[2];
    pid_t pid;
    char message[] = "Campus Event: Laboratory Started";
    char buffer[100];

    if (pipe(fd) == -1) {
        perror("Pipe creation failed");
        return 1;
    }

    pid = fork();
    if (pid < 0) {
        perror("Fork failed");
        close(fd[0]);
        close(fd[1]);
        return 1;
    }

    if (pid > 0) {
        close(fd[0]);

        if (write(fd[1], message, strlen(message) + 1) == -1)
            perror("Pipe write failed");

        close(fd[1]);
        wait(NULL);
        printf("Producer completed\n");
    } else {
        close(fd[1]);

        ssize_t bytes = read(fd[0], buffer, sizeof(buffer));
        if (bytes > 0) {
            size_t used = (size_t)bytes;
            if (used >= sizeof(buffer))
                used = sizeof(buffer) - 1;
            buffer[used] = '\0';
            printf("Received Event: %s\n", buffer);
        } else if (bytes == -1) {
            perror("Pipe read failed");
        }

        close(fd[0]);
        exit(0);
    }

    return 0;
}
