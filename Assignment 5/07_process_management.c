#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }

    if (pid == 0) {
        printf("Child Process\n");
        printf("Child PID: %ld\n", (long)getpid());
        printf("Parent PID: %ld\n", (long)getppid());
    } else {
        printf("Parent Process\n");
        printf("Parent PID: %ld\n", (long)getpid());

        if (wait(NULL) == -1) {
            perror("wait failed");
            return 1;
        }

        printf("Child Process Completed\n");
    }

    return 0;
}
