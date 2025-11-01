#include <stdio.h>

int main() {
    int x, y;
    printf("Enter two integers (x y): ");
    scanf("%d %d", &x, &y);

    if (y != 0) {
        printf("Result: %d\n", x / y);
    } else {
        printf("Cannot divide by zero!\n");
    }

    return 0;
}
