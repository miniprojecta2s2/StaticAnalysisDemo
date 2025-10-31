#include <stdio.h>
#define MAX 10
int n, adj[MAX][MAX], visited[MAX];
int stack[MAX];
int top = -1;
void push(int v) {
    if (top < MAX - 1)
        stack[++top] = v;
}
int pop() {
    if (top >= 0)
        return stack[top--];
    return -1; 
}
int isEmpty() {
   return top == -1;
}
void dfs(int start) {
    push(start);
    while (!isEmpty()) {
        int v = pop();
        if (!visited[v]) {
            printf("%d ", v);
            visited[v] = 1;
                 for (int i = n; i >= 1; i--) {
                if (adj[v][i] && !visited[i]) {
                    push(i);
                }
            }
        }
    }
}
int main() {
    int i, j, start;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter graph data in matrix form:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &adj[i][j]);
    for (i = 1; i <= n; i++)
        visited[i] = 0;
    printf("Enter the starting vertex: ");
    scanf("%d", &start);
    printf("DFS traversal sequence:\n");
    dfs(start);
    printf("\n");
    return 0;
}
