#include <stdio.h>

#define MAX_STATES 10

int num_states;
int epsilon_matrix[MAX_STATES][MAX_STATES];
int closure[MAX_STATES][MAX_STATES];
int visited[MAX_STATES];

void dfs(int start, int current) {
    visited[current] = 1;
    closure[start][current] = 1;

    for (int next = 0; next < num_states; next++) {
        if (epsilon_matrix[current][next] && !visited[next]) {
            dfs(start, next);
        }
    }
}

int main() {
    printf("Enter total no of states: ");
    if (scanf("%d", &num_states) != 1) return 1;

    printf("Enter epsilon transition adjacency matrix (1 if exists else 0):\n");
    for (int i = 0; i < num_states; i++) {
        for (int j = 0; j < num_states; j++) {
            scanf("%d", &epsilon_matrix[i][j]);
        }
    }

    for (int i = 0; i < num_states; i++) {
        for (int j = 0; j < num_states; j++) {
            visited[j] = 0;
        }
        dfs(i, i);
    }

    printf("\nEpsilon Closures\n");
    for (int i = 0; i < num_states; i++) {
        printf("e-closure(q%d) = { ", i);
        for (int j = 0; j < num_states; j++) {
            if (closure[i][j]) {
                printf("q%d ", j);
            }
        }
        printf("}\n");
    }

    return 0;
}
