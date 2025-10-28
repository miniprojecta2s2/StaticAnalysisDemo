#include <stdio.h>

// Function 1: adds numbers
int addNumbers(int a, int b) {
    return a + b;
}

// Function 2: subtracts numbers
int subtractNumbers(int a, int b) {
    return a - b;
}

// Duplicate logic to trigger "duplication" warning
int sumAndPrint(int a, int b) {
    int sum = a + b;
    printf("Sum: %d\n", sum);
    return sum;
}

int sumAndPrintAgain(int a, int b) {
    int sum = a + b; // duplicate logic
    printf("Sum again: %d\n", sum);
    return sum;
}

int main() {
    int x = 10, y = 0;

    // This part will trigger an "error prone" or "division by zero" issue
    if (y == 0)
        printf("Warning: Division by zero!\n");
    else
        printf("%d\n", x / y);

    // Some complexity — nested ifs & loops
    for (int i = 0; i < 5; i++) {
        if (i % 2 == 0) {
            if (i == 2)
                printf("Middle even number: %d\n", i);
            else
                printf("Even number: %d\n", i);
        } else {
            printf("Odd number: %d\n", i);
        }
    }

    addNumbers(5, 6);
    subtractNumbers(9, 4);
    sumAndPrint(3, 4);
    sumAndPrintAgain(7, 8);

    return 0;
}
