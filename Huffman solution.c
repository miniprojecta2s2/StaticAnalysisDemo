#include <stdio.h>
#include <string.h>

#define MAX 50
#define MAXCODE 128   /* allow more space for generated codes */

/* Finds two smallest non-zero entries in freq[0..n-1].
   Returns indices via *i and *j (-1 means not found). */
void findTwoSmallest(int freq[], int n, int *i, int *j) {
    *i = -1;
    *j = -1;
    for (int k = 0; k < n; k++) {
        if (freq[k] == 0) continue;
        if (*i == -1 || freq[k] < freq[*i]) {
            *j = *i;
            *i = k;
        } else if (*j == -1 || freq[k] < freq[*j]) {
            *j = k;
        }
    }
}

int main(void) {
    int n;
    char chars[MAX];
    int freq[MAX];
    char codes[MAX][MAXCODE];

    /* initialize arrays */
    for (int idx = 0; idx < MAX; ++idx) {
        freq[idx] = 0;
        codes[idx][0] = '\0';
        chars[idx] = '\0';
    }

    printf("Enter number of characters (1-%d): ", MAX);
    if (scanf("%d", &n) != 1) {
        fprintf(stderr, "Invalid input for number of characters.\n");
        return 1;
    }
    if (n <= 0 || n > MAX) {
        fprintf(stderr, "Number of characters must be between 1 and %d.\n", MAX);
        return 1;
    }

    printf("Enter %d characters (space separated or newline separated):\n", n);
    for (int i = 0; i < n; i++) {
        /* leading space in format skips whitespace/newlines */
        if (scanf(" %c", &chars[i]) != 1) {
            fprintf(stderr, "Failed to read character %d.\n", i+1);
            return 1;
        }
    }

    printf("Enter their frequencies (positive integers):\n");
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &freq[i]) != 1) {
            fprintf(stderr, "Failed to read frequency for character %c.\n", chars[i]);
            return 1;
        }
        if (freq[i] < 0) {
            fprintf(stderr, "Frequency must be non-negative.\n");
            return 1;
        }
    }

    /* ensure codes are empty strings for used indices */
    for (int i = 0; i < n; i++) codes[i][0] = '\0';

    /* If all frequencies are zero or only one non-zero, nothing to do */
    int nonZeroCount = 0;
    for (int i = 0; i < n; ++i) if (freq[i] > 0) ++nonZeroCount;
    if (nonZeroCount == 0) {
        fprintf(stderr, "No symbols with positive frequency provided.\n");
        return 1;
    }
    if (nonZeroCount == 1) {
        /* single symbol -> code is "0" */
        for (int i = 0; i < n; ++i) {
            if (freq[i] > 0) {
                strncpy(codes[i], "0", MAXCODE - 1);
                codes[i][MAXCODE - 1] = '\0';
                break;
            }
        }
    } else {
        /* Build codes by repeatedly combining two smallest nodes */
        while (1) {
            int i, j;
            findTwoSmallest(freq, n, &i, &j);
            if (i == -1 || j == -1) break;  /* done or not enough nodes */

            /* Prepend bits by appending and then reversing later.
               Use strncat to prevent overflow. */
            if (strlen(codes[i]) + 1 < (size_t)MAXCODE)
                strncat(codes[i], "0", MAXCODE - strlen(codes[i]) - 1);
            if (strlen(codes[j]) + 1 < (size_t)MAXCODE)
                strncat(codes[j], "1", MAXCODE - strlen(codes[j]) - 1);

            /* merge nodes: add freq[j] into i, zero out j */
            freq[i] += freq[j];
            freq[j] = 0;
        }
    }

    /* Reverse each code because bits were appended from leaf to root */
    for (int k = 0; k < n; k++) {
        size_t len = strlen(codes[k]);
        for (size_t l = 0; l < len / 2; l++) {
            char tmp = codes[k][l];
            codes[k][l] = codes[k][len - 1 - l];
            codes[k][len - 1 - l] = tmp;
        }
    }

    printf("\nHuffman Codes:\n");
    for (int i = 0; i < n; i++) {
        if (chars[i] != '\0') {
            printf("%c: %s\n", chars[i], codes[i][0] ? codes[i] : "(no code)");
        }
    }

    return 0;
}
