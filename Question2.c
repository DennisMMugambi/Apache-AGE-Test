#include <stdio.h>

#define MAX_SIZE 100

int f_memo[MAX_SIZE]; // Array to store numbers for memoization

// Function to calculate the recurrence iteratively
int f_iterative(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;

    // Variables to store recurrence numbers
    int fn_minus_3 = 0;
    int fn_minus_2 = 1;
    int fn_minus_1 = 2;
    int fn = 0;

    // Calculate the numbers iteratively
    for (int i = 3; i <= n; i++) {
        fn = fn_minus_3 + fn_minus_2;
        fn_minus_3 = fn_minus_2;
        fn_minus_2 = fn_minus_1;
        fn_minus_1 = fn;
    }

    return fn;
}

// Function to calculate the recurrence using memorization
int f_memorization(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;

    // Check if number already exists in memroization table
    if (f_memo[n] != -1)
        return f_memo[n];

    // Calculate number recursively and store it in the memorization table
    int fn = f_memorization(n - 3) + f_memorization(n - 2);
    f_memo[n] = fn;
    return fn;
}

// Function to calculate the recurrence sequence recursively
int f_recursive(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;

    // Calculate the number recursively
    return f_recursive(n - 3) + f_recursive(n - 2);
}

// Function to initialize the memoization table with -1 values
void initialize_memorization() {
    for (int i = 0; i < MAX_SIZE; i++)
        f_memo[i] = -1;
}

int main() {
    int n = 10;

    // Calculate number using the iterative approach
    int iterative_result = f_iterative(n);
    printf("F(%d) = %d : for the iterative approach\n", n, iterative_result);

    // Initialize the memorization table
    initialize_memorization();

    // Calculate number using the memoization approach
    int memorization_result = f_memorization(n);
    printf("F(%d) = %d : for the memoization approach\n", n, memorization_result);

    // Calculate number using the recursive approach
    int recursive_result = f_recursive(n);
    printf("F(%d) = %d : for the recursive approach\n", n, recursive_result);

    return 0;
}
