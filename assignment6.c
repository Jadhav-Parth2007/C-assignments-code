#include <stdio.h>

// Function Declarations (Prototypes)
long long factorial_iterative(int n);
long long factorial_recursive(int n);

int main() {
    int num;
    long long fact_iter, fact_recur;

    printf("Enter a non-negative integer: ");
    if (scanf("%d", &num) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    if (num < 0) {
        printf("Error: Factorial of a negative number is undefined.\n");
        return 1;
    }

    // Function calls (num is the actual argument)
    fact_iter = factorial_iterative(num);
    fact_recur = factorial_recursive(num);

    printf("\n--- Results ---\n");
    printf("Factorial of %d (Without Recursion): %lld\n", num, fact_iter);
    printf("Factorial of %d (With Recursion): %lld\n", num, fact_recur);

    return 0;
}

// Factorial without recursion (Iterative)
// n is the formal argument
long long factorial_iterative(int n) {
    long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Factorial with recursion
// n is the formal argument
long long factorial_recursive(int n) {
    // Base Case
    if (n == 0 || n == 1) {
        return 1;
    }
    // Recursive Step
    return n * factorial_recursive(n - 1);
}