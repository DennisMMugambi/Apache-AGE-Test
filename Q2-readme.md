# Fibonacci Sequence Calculation 

This program calculates the Fibonacci sequence using three different approaches: iterative, recursive, and memoization.

## Development Environment 

* Programming Language: C
* IDE/Editor: Any C-compatible IDE or text editor (e.g., Visual Studio Code, Xcode, Dev-C++, etc.)
* Compiler: GCC (GNU Compiler Collection)

## How to Compile 

1. Make sure you have GCC (GNU Compiler Collection) installed on your system. If you need a step by step guide you can follow this link [Install GCC](https://www.guru99.com/c-gcc-install.html) and navigate to the section that corresponds to your operating system.
2. Save the source code in a file named "fibonacci.c".
3. Open a terminal or command prompt and navigate to the directory where you saved the "fibonacci.c" file.
4. Run the following command to compile the code:

    gcc -o fibonacci fibonacci.c

## How to Run 

1. After successful compilation, run the following command to execute the program:

    ./fibonacci
            
2. The program will display the calculated result for F(n), where 'n' is the desired Fibonacci sequence number.

Note: You can modify the value of 'n' in the source code to calculate the Fibonacci sequence for different numbers.

## Advantages and Disadvantages of Each Approach 

### 1. Iterative Approach:
#### Advantages: 
- Efficient for large values of 'n' since it avoids the overhead of function calls.
- No risk of stack overflow due to excessive recursion.
#### Disadvantages: 
- The code may become complex with multiple variables to track.
- Not suitable if all values of 'n' need to be computed, as it only calculates a single value at a time.

### 2. Recursive Approach:
#### Advantages: 
- Simple and easy to understand the implementation.
- Directly follows the recurrence relation.
#### Disadvantages: 
- Inefficient for large values of 'n' due to redundant recursive function calls.
- May lead to stack overflow for large values of 'n'.

### 3. Memoization Approach:
#### Advantages: 
- Efficient for large values of 'n' as it avoids redundant function calls by storing intermediate results.
- Calculates each value of 'n' only once, improving overall performance.
#### Disadvantages: 
- Requires additional memory to store intermediate results.
- Slightly more complex than the iterative approach due to the memoization logic.
   