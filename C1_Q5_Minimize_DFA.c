// C1 Q5 Minimize DFA
#include <stdio.h>
#include <stdbool.h>

int main() {
    int states, symbols, num_final;
    printf("Enter total number of states: ");
    scanf("%d", &states);

    printf("Enter number of input symbols: ");
    scanf("%d", &symbols);

    int trans[100][100];
    printf("Enter transition table (state for each symbol):\n");
    for (int i = 0; i < states; i++) {
        for (int j = 0; j < symbols; j++) {
            printf("State %d on symbol %d -> ", i, j);
            scanf("%d", &trans[i][j]);
        }
    }

    int is_final[100] = {0};
    printf("Enter number of final states: ");
    scanf("%d", &num_final);

    printf("Enter final states:\n");
    for (int i = 0; i < num_final; i++) {
        int f;
        scanf("%d", &f);
        is_final[f] = 1;
    }

    int group[100];
    for (int i = 0; i < states; i++) {
        group[i] = is_final[i] ? 1 : 0;
    }

    bool changed = true;
    int num_groups = (num_final > 0 && num_final < states) ? 2 : 1;

    while (changed) {
        changed = false;
        int new_group[100];
        int next_group_id = 0;

        for (int i = 0; i < states; i++) {
            new_group[i] = -1;
        }

        for (int i = 0; i < states; i++) {
            if (new_group[i] != -1) continue;

            new_group[i] = next_group_id;
            for (int j = i + 1; j < states; j++) {
                if (group[i] == group[j]) {
                    bool same = true;
                    for (int k = 0; k < symbols; k++) {
                        if (group[trans[i][k]] != group[trans[j][k]]) {
                            same = false;
                            break;
                        }
                    }
                    if (same) {
                        new_group[j] = next_group_id;
                    }
                }
            }
            next_group_id++;
        }

        for (int i = 0; i < states; i++) {
            if (group[i] != new_group[i]) {
                changed = true;
                group[i] = new_group[i];
            }
        }
        num_groups = next_group_id;
    }

    printf("\n--- Minimized DFA ---\n");
    printf("Equivalent State Groups:\n");
    for (int g = 0; g < num_groups; g++) {
        printf("Group %d: { ", g);
        for (int i = 0; i < states; i++) {
            if (group[i] == g) {
                printf("%d ", i);
            }
        }
        printf("}\n");
    }

    printf("\nMinimized Transition Table:\n");
    printf("Group\t");
    for (int j = 0; j < symbols; j++) {
        printf("Sym %d\t", j);
    }
    printf("\n");

    for (int g = 0; g < num_groups; g++) {
        int rep = -1;
        for (int i = 0; i < states; i++) {
            if (group[i] == g) {
                rep = i;
                break;
            }
        }
        printf("G%d\t", g);
        for (int j = 0; j < symbols; j++) {
            printf("G%d\t", group[trans[rep][j]]);
        }
        printf("\n");
    }

    return 0;
}
