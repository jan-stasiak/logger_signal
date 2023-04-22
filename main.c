#include <stdio.h>
#include "log.h"

void send_signal(int signal, int value);

int main(void) {
    logger_init(NULL, "/home/jan/Downloads/SCR/log", "/home/jan/Downloads/SCR/dump", SIGUSR1, SIGUSR2, MAX);
    logger_log(HIGH, "HIGH - MAX");
    logger_log(AVERAGE, "AVERAGE - MAX");
    logger_log(LOW, "LOW - MAX");

    send_signal(SIGUSR2, 0);
    logger_stop();
    return 0;
}

void send_signal(int signal, int value) {
    union sigval signal_value;
    signal_value.sival_int = value;
    sigqueue(getpid(), signal, signal_value);
}