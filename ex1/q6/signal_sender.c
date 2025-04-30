#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void send_bit(pid_t pid, int bit) {
    int sig = (bit) ? SIGUSR1 : SIGUSR2;
    kill(pid, sig);
    usleep(500); // זמן קצר לחכות כדי שהמקבל יספיק לקרוא
}

int main() {
    pid_t receiver_pid;
    int message;

    printf("Enter receiver PID: ");
    scanf("%d", &receiver_pid);

    printf("Enter message: ");
    scanf("%d", &message);

    for (int i = 7; i >= 0; i--) {
        int bit = (message >> i) & 1;
        send_bit(receiver_pid, bit);
    }

    return 0;
}
