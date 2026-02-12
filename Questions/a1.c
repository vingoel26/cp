#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();
    if (pid == 0) {
        printf("Child process sleeping...\n");
        sleep(5);
        printf("Child woke up\n");
    } else {
        printf("Parent process\n");
    }
    return 0;
}
