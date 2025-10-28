#include <stdio.h>

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }
int divSafe(int a, int b) {
    if (b == 0) return 0;
    return a / b;
}

// Duplicate logic (Codacy can detect this)
int calculate1(int a, int b) {
    int sum = 0;
    for (int i = 0; i < b; i++) sum += a;
    return sum;
}

int calculate2(int a, int b) {  // Duplicate logic
    int sum = 0;
    for (int i = 0; i < b; i++) sum += a;
    return sum;
}

void analyzeArray(int arr[], int size) {
    int max = arr[0];
    for (int i = 0; i < size; i++) {
        if (arr[i] > max)
            max = arr[i];
        else if (arr[i] == max)
            printf("Duplicate max found: %d\n", arr[i]);
    }
    printf("Max value: %d\n", max);
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    analyzeArray(arr, 5);

    int x = 10, y = 0;
    printf("Sum: %d\n", add(x, 5));
    printf("Sub: %d\n", sub(x, 5));
    printf("Mul: %d\n", mul(x, 5));
    printf("Div: %d\n", divSafe(x, y));  // Safe division

    // Conditional chain (adds complexity)
    if (x > 0)
        if (x < 10)
            printf("x is small\n");
        else if (x == 10)
            printf("x is exactly 10\n");
        else
            printf("x is large\n");

    calculate1(2, 3);
    calculate2(2, 3);

    return 0;
}
