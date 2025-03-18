#include <stdio.h>
#include <time.h>

unsigned long long fibonacci(unsigned long long n, unsigned long long fibonacciArray[]);

int main(void)
{
    clock_t start = clock();
    unsigned long long value = 0;
    unsigned long long fibonacciArray[93] = {};
    for (int i = 0; i < 93; i++)
    {
        value = fibonacci(i, fibonacciArray);
        printf("Value for i = %d: %llu\n", i, value);
    }
    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", time_taken);
    return 0;
}

unsigned long long fibonacci(unsigned long long n, unsigned long long fibonacciArray[])
{
    if (n <= 1)
    {
        return 1;
    }
    else
    {
        fibonacciArray[n - 1] = fibonacciArray[n - 1] != 0 ? fibonacciArray[n - 1] : fibonacci(n - 1, fibonacciArray);
        fibonacciArray[n - 2] = fibonacciArray[n - 2] != 0 ? fibonacciArray[n - 2] : fibonacci(n - 2, fibonacciArray);
        return fibonacciArray[n - 1] + fibonacciArray[n - 2];
    }
}