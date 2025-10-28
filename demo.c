#include <stdio.h>

// Duplicate block 1
void processNumbersA() {
    int total = 0;
    for (int i = 0; i < 5; i++) {
        total += i;
        if (i % 2 == 0)
            printf("Even A: %d\n", i);
        else
            printf("Odd A: %d\n", i);
    }
    printf("Total A = %d\n", total);
}

// Duplicate block 2 (almost identical)
void processNumbersB() {
    int total = 0;
    for (int i = 0; i < 5; i++) {
        total += i;
        if (i % 2 == 0)
            printf("Even B: %d\n", i);
        else
            printf("Odd B: %d\n", i);
    }
    printf("Total B = %d\n", total);
}

// Simple function for extra complexity
int divide(int x, int y) {
    if (y == 0) {
        printf("Division by zero prevented!\n");
        return 0;
    } else {
        return x / y;
    }
}

int main() {
    int a = 10, b = 0;
    int result = divide(a, b);
    printf("Result: %d\n", result);

    processNumbersA();
    processNumbersB();

    return 0;
}
