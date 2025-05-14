#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>

void handler(int signum) {
    printf("Caught signal %d\n", signum);
    exit(0);
}

int main() {
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa)); // Clear the struct
    sa.sa_handler = handler; // Set the handler
    sigaction(SIGINT, &sa, NULL); // Register the handler

    while (1) {
        printf("Running... Press Ctrl+C to stop.\n");
        sleep(1);
    }
    return 0;
}
