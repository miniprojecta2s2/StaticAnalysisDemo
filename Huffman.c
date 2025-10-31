#include <stdio.h>
#include <string.h>
#define MAX 50
#define MAXCODE 50

void findTwoSmallest(int freq[], int n, int *i, int *j) {
    *i = -1; *j = -1;
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

int main() {
    int n;
    char chars[MAX];
    int freq[MAX];
    char codes[MAX][MAXCODE];


    printf("Enter number of characters: ");
    scanf("%d", &n);

    printf("Enter characters: ");
    for (int i = 0; i < n; i++) {
        scanf(" %c", &chars[i]);
    }

    printf("Enter their frequencies: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &freq[i]);
    }

       for (int i = 0; i < n; i++) {
        codes[i][0] = '\0';
    }

       while (1) {
        int i, j;
        findTwoSmallest(freq, n, &i, &j);
        if (j == -1) break;
        strcat(codes[i], "0");
        strcat(codes[j], "1");

       
        freq[i] += freq[j];
        freq[j] = 0; // mark as used
    }

    
    for (int k = 0; k < n; k++) {
        int len = strlen(codes[k]);
        for (int l = 0; l < len / 2; l++) {
            char tmp = codes[k][l];
            codes[k][l] = codes[k][len - 1 - l];
            codes[k][len - 1 - l] = tmp;
        }
    }

        printf("\nHuffman Codes:\n");
    for (int i = 0; i < n; i++) {
        printf("%c: %s\n", chars[i], codes[i]);
    }

    return 0;
}
