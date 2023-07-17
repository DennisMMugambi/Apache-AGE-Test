#include <stdio.h>

#define MAX_SIZE 100

int fib_memo[MAX_SIZE]; // Array to store Fibonacci numbers for memoization

// Function to calculate the Fibonacci sequence iteratively
int fibonacci_iterative(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;

    // Variables to store Fibonacci numbers
    int fn_minus_3 = 0;
    int fn_minus_2 = 1;
    int fn_minus_1 = 2;
    int fn = 0;

    // Calculate Fibonacci numbers iteratively
    for (int i = 3; i <= n; i++) {
        fn = fn_minus_3 + fn_minus_2;
        fn_minus_3 = fn_minus_2;
        fn_minus_2 = fn_minus_1;
        fn_minus_1 = fn;
    }

    return fn;
}

// Function to calculate the Fibonacci sequence using memoization
int fibonacci_memoization(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;

    // Check if Fibonacci number already exists in memoization table
    if (fib_memo[n] != -1)
        return fib_memo[n];

    // Calculate Fibonacci number recursively and store it in the memoization table
    int fn = fibonacci_memoization(n - 3) + fibonacci_memoization(n - 2);
    fib_memo[n] = fn;
    return fn;
}

// Function to calculate the Fibonacci sequence recursively
int fibonacci_recursive(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;

    // Calculate Fibonacci number recursively
    return fibonacci_recursive(n - 3) + fibonacci_recursive(n - 2);
}

// Function to initialize the memoization table with -1 values
void initialize_memoization() {
    for (int i = 0; i < MAX_SIZE; i++)
        fib_memo[i] = -1;
}

int main() {
    int n = 10;

    // Calculate Fibonacci number using the iterative approach
    int iterative_result = fibonacci_iterative(n);
    printf("F(%d) = %d : for the iterative approach\n", n, iterative_result);

    // Initialize the memoization table
    initialize_memoization();

    // Calculate Fibonacci number using the memoization approach
    int memorization_result = fibonacci_memoization(n);
    printf("F(%d) = %d : for the memoization approach\n", n, memorization_result);

    // Calculate Fibonacci number using the recursive approach
    int recursive_result = fibonacci_recursive(n);
    printf("F(%d) = %d : for the recursive approach\n", n, recursive_result);

    return 0;
}
