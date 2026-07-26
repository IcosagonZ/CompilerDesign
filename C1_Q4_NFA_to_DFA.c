// C1 Q4 NFA to DFA
#include <stdio.h>

int nfa[20][20][20];
int dfa[50][20];
int dfa_states[50][20];
int n_states, n_symbols, n_dfa = 0;

int is_equal(int a[20], int b[20]) {
    for (int i = 0; i < n_states; i++) {
        if (a[i] != b[i]) return 0;
    }
    return 1;
}

int find_state(int state[20]) {
    for (int i = 0; i < n_dfa; i++) {
        if (is_equal(dfa_states[i], state)) return i;
    }
    return -1;
}

int main() {
    printf("Enter number of states in NFA: ");
    scanf("%d", &n_states);
    printf("Enter number of input symbols: ");
    scanf("%d", &n_symbols);

    for (int k = 0; k < n_symbols; k++) {
        printf("Enter transition table for symbol %d (1 if transition exists, 0 otherwise):\n", k);
        for (int i = 0; i < n_states; i++) {
            for (int j = 0; j < n_states; j++) {
                scanf("%d", &nfa[k][i][j]);
            }
        }
    }

    int start[20] = {0};
    start[0] = 1;
    for (int i = 0; i < n_states; i++) dfa_states[0][i] = start[i];
    n_dfa = 1;

    for (int i = 0; i < n_dfa; i++) {
        for (int k = 0; k < n_symbols; k++) {
            int move[20] = {0};
            for (int j = 0; j < n_states; j++) {
                if (dfa_states[i][j]) {
                    for (int m = 0; m < n_states; m++) {
                        if (nfa[k][j][m]) {
                            move[m] = 1;
                        }
                    }
                }
            }

            int state_idx = find_state(move);
            if (state_idx == -1) {
                for (int m = 0; m < n_states; m++) {
                    dfa_states[n_dfa][m] = move[m];
                }
                dfa[i][k] = n_dfa;
                n_dfa++;
            } else {
                dfa[i][k] = state_idx;
            }
        }
    }

    printf("\nDFA Transition Table:\nState\t");
    for (int k = 0; k < n_symbols; k++) printf("Sym %d\t", k);
    printf("\n");

    for (int i = 0; i < n_dfa; i++) {
        printf("{");
        for (int j = 0; j < n_states; j++) {
            if (dfa_states[i][j]) printf("q%d ", j);
        }
        printf("}\t");
        for (int k = 0; k < n_symbols; k++) {
            printf("D%d\t", dfa[i][k]);
        }
        printf("\n");
    }

    return 0;
}
