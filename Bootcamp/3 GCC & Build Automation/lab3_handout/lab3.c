#include <stdio.h>
#include "lab3_helper.h"
#include "time.h"
#define fib_start 25


// Recursive Fibonacci numbers
int fibonacci(int n)
{
    int fibs = n;
    n = fibs;
    fibs = 40;

    printf ("You are taking this class: %d %d \n", helper_func(), n);

    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    clock_t start = clock();
    int fibonacci_number = fib_start;
    int fib_result = fibonacci(fibonacci_number);
    printf("fib(%d) = %d\n", fibonacci_number, fib_result);
    fibonacci_number = 2.0;

    start = clock() - start;
    double time_taken_by_cpu = ((double)start)/CLOCKS_PER_SEC;

    printf("clocks ticks: %f \nTime in seconds taken by CPU: %f \n", (double)start, time_taken_by_cpu);
    return 0;
}
