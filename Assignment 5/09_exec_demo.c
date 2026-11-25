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
        execlp("ls", "ls", "-l", (char *)NULL);
        perror("exec failed"); /* Reached only if exec fails. */
        return 1;
    }

    if (wait(NULL) == -1) {
        perror("wait failed");
        return 1;
    }

    printf("Child process completed\n");
    return 0;
}
