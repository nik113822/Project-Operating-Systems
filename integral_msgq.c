/*
 * Νικόλαος Παπαδούρης, 1090040
 * Αλέξανδρος Κολλώσης, 1084562
 * Μίλτος Κουράκος, 1084621
 * Νικόλαος Ανδρομιδάς, 1084641
 *
 * Multiple-process numerical integration using a System V message queue.
 * This file reproduces the implementation presented in the submitted report.
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <unistd.h>

#define NUM_PROCESSES 4

typedef struct {
    long type;
    double result;
} msg_t;

double get_wtime(void)
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1.0e-6;
}

double f(double x)
{
    return log(x) * sqrt(x);
}

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    const double a = 1.0;
    const double b = 4.0;
    const unsigned long n = 1000000000UL;
    const double dx = (b - a) / n;
    const double t0 = get_wtime();

    /* Create message queue. IPC_PRIVATE creates a queue for this process tree. */
    const int msgid = msgget(IPC_PRIVATE, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < NUM_PROCESSES; i++) {
        const pid_t pid = fork();

        if (pid == -1) {
            perror("fork");
            msgctl(msgid, IPC_RMID, NULL);
            return EXIT_FAILURE;
        }

        if (pid == 0) {
            double S = 0.0;
            const unsigned long start = (unsigned long)i * (n / NUM_PROCESSES);
            const unsigned long end = (i == NUM_PROCESSES - 1)
                                          ? n
                                          : (unsigned long)(i + 1) * (n / NUM_PROCESSES);

            for (unsigned long j = start; j < end; j++) {
                const double xi = a + (j + 0.5) * dx;
                S += f(xi);
            }

            S *= dx;

            msg_t msg;
            msg.type = 1;
            msg.result = S;

            if (msgsnd(msgid, &msg, sizeof(msg.result), 0) == -1) {
                perror("msgsnd");
                _exit(EXIT_FAILURE);
            }

            _exit(EXIT_SUCCESS);
        }
    }

    double result = 0.0;

    for (int i = 0; i < NUM_PROCESSES; i++) {
        msg_t msg;

        if (msgrcv(msgid, &msg, sizeof(msg.result), 1, 0) == -1) {
            perror("msgrcv");
            msgctl(msgid, IPC_RMID, NULL);
            return EXIT_FAILURE;
        }

        result += msg.result;
    }

    for (int i = 0; i < NUM_PROCESSES; i++) {
        wait(NULL);
    }

    msgctl(msgid, IPC_RMID, NULL);

    const double t1 = get_wtime();
    printf("Time=%lf seconds, Result=%.8f\n", t1 - t0, result);
    return EXIT_SUCCESS;
}
