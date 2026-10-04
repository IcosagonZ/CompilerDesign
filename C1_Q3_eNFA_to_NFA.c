#include <stdio.h>
#include <stdlib.h>

int n_states, n_symbols;
int e_transitions[20][20];
int transitions[20][20][20];
int e_closure[20][20];

void find_e_closure(int state, int current_state) {
    e_closure[state][current_state] = 1;
    for (int i = 0; i < n_states; i++) {
        if (e_transitions[current_state][i] && !e_closure[state][i]) {
            find_e_closure(state, i);
        }
    }
}

int main() {
    printf("Enter no of states: ");
    scanf("%d", &n_states);
    printf("Enter no of input symbols (excl e_0): ");
    scanf("%d", &n_symbols);

    printf("Enter e_0 transition matrix (1 if exists else 0):\n");
    for (int i = 0; i < n_states; i++) {
        for (int j = 0; j < n_states; j++) {
            scanf("%d", &e_transitions[i][j]);
        }
    }

    for (int k = 0; k < n_symbols; k++) {
        printf("Enter transition matrix for symbol %d:\n", k);
        for (int i = 0; i < n_states; i++) {
            for (int j = 0; j < n_states; j++) {
                scanf("%d", &transitions[k][i][j]);
            }
        }
    }

    for (int i = 0; i < n_states; i++) {
        find_e_closure(i, i);
    }

    printf("\nTransitions of NFA without Epsilon:\n");
    for (int i = 0; i < n_states; i++) {
        for (int k = 0; k < n_symbols; k++) {
            printf("State q%d on symbol %d -> { ", i, k);
            int new_trans[20] = {0};
            for (int j = 0; j < n_states; j++) {
                if (e_closure[i][j]) {
                    for (int m = 0; m < n_states; m++) {
                        if (transitions[k][j][m]) {
                            for (int n = 0; n < n_states; n++) {
                                if (e_closure[m][n]) {
                                    new_trans[n] = 1;
                                }
                            }
                        }
                    }
                }
            }
            for (int j = 0; j < n_states; j++) {
                if (new_trans[j]) {
                    printf("q%d ", j);
                }
            }
            printf("}\n");
        }
    }
    return 0;
}
