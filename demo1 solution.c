#include <stdio.h>
int main() {
    int x = 10, y = 1;

    if (y != 0) {
        printf("%d", x / y);
    } else {
        printf("Cannot divide by zero!\n");
    }

    return 0;
}
