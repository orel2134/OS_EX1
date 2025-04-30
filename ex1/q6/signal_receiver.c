#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

volatile sig_atomic_t received_number = 0;
volatile sig_atomic_t bit_count = 0;

void handle_sigusr1(int sig) {
    received_number = (received_number << 1) | 1;
    bit_count++;
}

void handle_sigusr2(int sig) {
    received_number = (received_number << 1) | 0;
    bit_count++;
}

int main() {
    struct sigaction sa1, sa2;

    printf("My PID is %d\n", getpid());

    memset(&sa1, 0, sizeof(sa1));
    memset(&sa2, 0, sizeof(sa2));

    sa1.sa_handler = handle_sigusr1;
    sigemptyset(&sa1.sa_mask);
    sa1.sa_flags = 0;
    sigaction(SIGUSR1, &sa1, NULL);

    sa2.sa_handler = handle_sigusr2;
    sigemptyset(&sa2.sa_mask);
    sa2.sa_flags = 0;
    sigaction(SIGUSR2, &sa2, NULL);

    while (1) {
        pause();
        if (bit_count == 8) {
            printf("Received %d\n", received_number);
            received_number = 0;
            bit_count = 0;
        }
    }

    return 0;
}
