// #include <stdio.h>
// #include <stdlib.h>

// typedef struct Node {
//     enum TypeTag {
//         CONSTANT,
//         ADD,
//         SUB,
//         MUL,
//         DIV,
//         FIBO
//     } type;
//     union {
//         int value;
//         struct Node* left;
//         struct {
//             struct Node* left;
//             struct Node* right;
//         } binary;
//     } data;
// } Node;

// Node* makeFunc(enum TypeTag type) {
//     Node* node = (Node*)malloc(sizeof(Node));
//     node->type = type;
//     return node;
// }

// int fibonacci(int n) {
//     if (n <= 1)
//         return n;
    
//     int* fib = (int*)malloc((n + 1) * sizeof(int));
//     fib[0] = 0;
//     fib[1] = 1;

//     for (int i = 2; i <= n; i++) {
//         fib[i] = fib[i - 1] + fib[i - 2];
//     }

//     int result = fib[n];
//     free(fib);
//     return result;
// }

// void calc(Node* node) {
//     switch (node->type) {
//         case CONSTANT:
//             printf("constant: %d\n", node->data.value);
//             break;
//         case ADD:
//             printf("add: %d\n", node->data.binary.left->data.value + node->data.binary.right->data.value);
//             break;
//         case SUB:
//             printf("sub: %d\n", node->data.binary.left->data.value - node->data.binary.right->data.value);
//             break;
//         case MUL:
//             printf("mul: %d\n", node->data.binary.left->data.value * node->data.binary.right->data.value);
//             break;
//         case DIV:
//             printf("div: %d\n", node->data.binary.left->data.value / node->data.binary.right->data.value);
//             break;
//         case FIBO:
//             printf("fibo: %d\n", fibonacci(node->data.left->data.binary.left->data.value));
//             break;
//     }
// }

// int main() {
//     Node* add = makeFunc(ADD);
//     add->data.binary.left = makeFunc(CONSTANT);
//     add->data.binary.left->data.value = 10;
//     add->data.binary.right = makeFunc(CONSTANT);
//     add->data.binary.right->data.value = 6;

//     Node* mul = makeFunc(MUL);
//     mul->data.binary.left = makeFunc(CONSTANT);
//     mul->data.binary.left->data.value = 5;
//     mul->data.binary.right = makeFunc(CONSTANT);
//     mul->data.binary.right->data.value = 4;

//     Node* sub = makeFunc(SUB);
//     sub->data.binary.left = mul;
//     sub->data.binary.right = add;

//     Node* fibo = makeFunc(FIBO);
//     fibo->data.left = sub;

//     calc(add);
//     calc(mul);
//     calc(sub);
//     calc(fibo);

//     free(add);
//     free(mul);
//     free(sub);
//     free(fibo);

//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    enum TypeTag {
        CONSTANT,  // Represents a constant value
        ADD,       // Represents addition operation
        SUB,       // Represents subtraction operation
        MUL,       // Represents multiplication operation
        DIV,       // Represents division operation
        FIBO       // Represents operation to generate fibonacci sequence
    } type;
    union {
        int value;              // Value for CONSTANT type
        struct Node* left;      // Left child node for binary operations
        struct {
            struct Node* left;  // Left child node for binary operations
            struct Node* right; // Right child node for binary operations
        } binary;
    } data;
} Node;

Node* makeFunc(enum TypeTag type) {
    Node* node = (Node*)malloc(sizeof(Node));  // Allocate memory for a new Node
    node->type = type;  // Set the type of the Node
    return node;  // Return the created Node
}

int fibonacci(int n) {
    if (n <= 1)
        return n;
    
    int* fib = (int*)malloc((n + 1) * sizeof(int));  // Allocate memory for the Fibonacci sequence
    fib[0] = 0;  // Set the initial value for F(0)
    fib[1] = 1;  // Set the initial value for F(1)

    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];  // Calculate the Fibonacci sequence
    }

    int result = fib[n];  // Store the Fibonacci number for F(n)
    free(fib);  // Free the allocated memory
    return result;  // Return the Fibonacci number for F(n)
}

void calc(Node* node) {
    switch (node->type) {
        case CONSTANT:
            printf("constant: %d\n", node->data.value);  // Print the value of the constant Node
            break;
        case ADD:
            printf("add: %d\n", node->data.binary.left->data.value + node->data.binary.right->data.value);  // Perform addition and print the result
            break;
        case SUB:
            printf("sub: %d\n", node->data.binary.left->data.value - node->data.binary.right->data.value);  // Perform subtraction and print the result
            break;
        case MUL:
            printf("mul: %d\n", node->data.binary.left->data.value * node->data.binary.right->data.value);  // Perform multiplication and print the result
            break;
        case DIV:
            printf("div: %d\n", node->data.binary.left->data.value / node->data.binary.right->data.value);  // Perform division and print the result
            break;
        case FIBO:
            printf("fibo: %d\n", fibonacci(node->data.left->data.binary.left->data.value));  // Calculate the Fibonacci sequence and print the result
            break;
    }
}

int main() {
    Node* add = makeFunc(ADD);  // Create a Node for addition operation
    add->data.binary.left = makeFunc(CONSTANT);  // Set the left child Node as a constant Node
    add->data.binary.left->data.value = 10;  // Assign a value to the constant Node
    add->data.binary.right = makeFunc(CONSTANT);  // Set the right child Node as a constant Node
    add->data.binary.right->data.value = 6;  // Assign a value to the constant Node

    Node* mul = makeFunc(MUL);  // Create a Node for multiplication operation
    mul->data.binary.left = makeFunc(CONSTANT);  // Set the left child Node as a constant Node
    mul->data.binary.left->data.value = 5;  // Assign a value to the constant Node
    mul->data.binary.right = makeFunc(CONSTANT);  // Set the right child Node as a constant Node
    mul->data.binary.right->data.value = 4;  // Assign a value to the constant Node

    Node* sub = makeFunc(SUB);  // Create a Node for subtraction operation
    sub->data.binary.left = mul;  // Set the left child Node as the multiplication Node
    sub->data.binary.right = add;  // Set the right child Node as the addition Node

    Node* fibo = makeFunc(FIBO);  // Create a Node for Fibonacci operation
    fibo->data.left = sub;  // Set the left child Node as the subtraction Node

    calc(add);  // Perform calculation for the addition Node
    calc(mul);  // Perform calculation for the multiplication Node
    calc(sub);  // Perform calculation for the subtraction Node
    calc(fibo);  // Perform calculation for the Fibonacci Node

    free(add);  // Free the memory allocated for the addition Node
    free(mul);  // Free the memory allocated for the multiplication Node
    free(sub);  // Free the memory allocated for the subtraction Node
    free(fibo);  // Free the memory allocated for the Fibonacci Node

    return 0;
}

