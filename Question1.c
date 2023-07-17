#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
int fib[MAX_SIZE];

typedef enum TypeTag {
    ADD,
    SUB,
    MUL,
    DIV,
    ABS,
    FIB,
    LIT
} TypeTag;

typedef struct Node {
    TypeTag type;
    int value;
    struct Node *left;
    struct Node *right;
} Node;

// function to create a new node
Node* makeFunc(TypeTag type) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->type = type;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* makeValue(int value) {
    Node *newNode = makeFunc(LIT);
    newNode->value = value;
    return newNode;
}

// fibonacci function using dynamic programming
int fibonacci(int n) {
    int fib[n+1];
    fib[0] = 0;
    fib[1] = 1;
    for(int i = 2; i <= n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }
    return fib[n];
}

// function to calculate the value of a node
int calc(Node* node) {
    switch (node->type) {
        case ADD:
            // Evaluate the left and right child nodes and return their sum
            return calc(node->left) + calc(node->right);

        case SUB:
            // Evaluate the left and right child nodes and return their difference
            return calc(node->left) - calc(node->right);

        case MUL:
            // Evaluate the left and right child nodes and return their product
            return calc(node->left) * calc(node->right);

        case DIV:
            // Evaluate the left and right child nodes and return their quotient
            return calc(node->left) / calc(node->right);

        case ABS:
            // Evaluate the child node and return the absolute value of the result
            return abs(calc(node->left));

        case FIB:
            // Evaluate the left child node and pass its value to the fibonacci function
            return fibonacci(calc(node->left));

        case LIT:
            // Return the literal value stored in the node
            return node->value;
    }

    // Print an error message and exit if an invalid node type is encountered
    perror("Invalid node type");
    exit(EXIT_FAILURE);
}

int main() {
    // Initialize the 'fib' array with -1
    for (int i = 0; i < MAX_SIZE; i++) {
        fib[i] = -1;
    }

    // Create nodes for arithmetic operations and literals
    Node *add = makeFunc(ADD);
    add->left = makeValue(10);
    add->right = makeValue(6);

    Node *mul = makeFunc(MUL);
    mul->left = makeValue(5);
    mul->right = makeValue(4);

    Node *sub = makeFunc(SUB);
    sub->left = makeValue(calc(add));  // Evaluate the 'add' node and store its result
    sub->right = makeValue(calc(mul)); // Evaluate the 'mul' node and store its result

    Node *fibo = makeFunc(FIB);
    fibo->left = makeValue(abs(calc(sub))); // Evaluate the 'sub' node and take its absolute value
    fibo->value = fibonacci(calc(fibo->left)); // Evaluate the 'fibo->left' node and store the result

    // Print the calculated values
    printf("add : %d\n", calc(add));
    printf("mul : %d\n", calc(mul));
    printf("sub : %d\n", calc(sub));
    printf("fibo : %d\n", calc(fibo));

    // Free the dynamically allocated memory
    free(add);
    free(mul);
    free(sub);
    free(fibo);

    return 0;
}

