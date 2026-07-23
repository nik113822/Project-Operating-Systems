/*
 * Sequential numerical integration baseline from the assignment.
 * f(x) = ln(x) * sqrt(x), x in [1, 4]
 */

#include <math.h>
#include <stdio.h>
#include <sys/time.h>

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

int main(void)
{
    const double a = 1.0;
    const double b = 4.0;
    const unsigned long n = 1000000000UL;
    const double dx = (b - a) / n;
    double S = 0.0;

    const double t0 = get_wtime();

    for (unsigned long i = 0; i < n; i++) {
        const double xi = a + (i + 0.5) * dx;
        S += f(xi);
    }

    S *= dx;

    const double t1 = get_wtime();
    printf("Time=%lf seconds, Result=%.8f\n", t1 - t0, S);
    return 0;
}
