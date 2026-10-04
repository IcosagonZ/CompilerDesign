#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 20

int count;
char production[MAX][10];
char first[MAX][10], follow[MAX][10];

void findFirst(char c, int q1, int q2);
void findFollow(char c);
void addToSet(char set[], char val);

int main() {
    int i, choice;
    char c;

    printf("Enter total no of productions: ");
    if (scanf("%d", &count) != 1) return 0;

    printf("Enter productions (e.g., E=E+T or E=# for epsilon):\n");
    for (i = 0; i < count; i++) {
        scanf("%s", production[i]);
    }

    // Compute FIRST sets
    for (i = 0; i < count; i++) {
        c = production[i][0];
        findFirst(c, 0, 0);
    }

    // Compute FOLLOW sets
    for (i = 0; i < count; i++) {
        c = production[i][0];
        findFollow(c);
    }

    // Print Results
    printf("\n- FIRST SETS-\n");
    for (i = 0; i < count; i++) {
        c = production[i][0];
        printf("FIRST(%c) = { ", c);
        for (int j = 0; j < strlen(first[i]); j++) {
            printf("%c ", first[i][j]);
        }
        printf("}\n");
    }

    printf("\n-FOLLOW SETS-\n");
    for (i = 0; i < count; i++) {
        c = production[i][0];
        printf("FOLLOW(%c) = { ", c);
        for (int j = 0; j < strlen(follow[i]); j++) {
            printf("%c ", follow[i][j]);
        }
        printf("}\n");
    }

    return 0;
}

void addToSet(char set[], char val) {
    for (int k = 0; set[k] != '\0'; k++) {
        if (set[k] == val) return;
        // Avoid duplicates
    }
    int len = strlen(set);
    set[len] = val;
    set[len + 1] = '\0';
}

void findFirst(char c, int q1, int q2) {
    for (int j = 0; j < count; j++) {
        if (production[j][0] == c) {
            if (production[j][2] == '#') {
                // Epsilon
                addToSet(first[j], '#');
            } else if (!isupper(production[j][2])) {
                // Terminal
                addToSet(first[j], production[j][2]);
            } else {
                // Non-terminal
                findFirst(production[j][2], j, 3);
            }
        }
    }
}

void findFollow(char c) {
    if (production[0][0] == c) {
        addToSet(follow[0], '$'); // Start symbol gets $
    }

    for (int i = 0; i < count; i++) {
        for (int j = 2; j < strlen(production[i]); j++) {
            if (production[i][j] == c) {
                if (production[i][j + 1] != '\0') {
                    // Next symbol terminal
                    if (!isupper(production[i][j + 1]) && production[i][j + 1] != '#') {
                        addToSet(follow[i], production[i][j + 1]);
                    }
                } else {
                    // Symbol at the end, add FOLLOW of head
                    if (production[i][0] != c) {
                        findFollow(production[i][0]);
                    }
                }
            }
        }
    }
}
