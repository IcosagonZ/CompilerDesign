#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 10

int count;
char production[MAX][10];
char firstSet[MAX][10];
char followSet[MAX][10];

void addToResult(char result[], char val) {
    int k;
    for (k = 0; result[k] != '\0'; k++) {
        if (result[k] == val)
            return;
    }
    result[k] = val;
    result[k + 1] = '\0';
}

void FIRST(char* result, char c) {
    int i, j, k;
    char subResult[20];
    int epsilonFound;

    result[0] = '\0';
    subResult[0] = '\0';

    // If 'c' is a terminal, FIRST(c) = {c}
    if (!(isupper(c))) {
        addToResult(result, c);
        return;
    }

    // If 'c' is a non-terminal, check all production rules
    for (i = 0; i < count; i++) {
        // Find production rule starting with 'c'
        if (production[i][0] == c) {
            // Check RHS of production rule (starts at index 2, assuming format X=Y...)
            if (production[i][2] == '#') {
                addToResult(result, '#');
            } else {
                j = 2;
                while (production[i][j] != '\0') {
                    epsilonFound = 0;
                    FIRST(subResult, production[i][j]);

                    for (k = 0; subResult[k] != '\0'; k++) {
                        if (subResult[k] == '#')
                            epsilonFound = 1;
                        else
                            addToResult(result, subResult[k]);
                    }

                    // If epsilon is not in FIRST of current symbol, stop checking next symbols
                    if (!epsilonFound)
                        break;
                    j++;
                }
            }
        }
    }
}

void FOLLOW(char* result, char c) {
    int i, j, k;
    char subResult[20];

    // If 'c' is the start symbol, add '$' to FOLLOW(c)
    if (production[0][0] == c) {
        addToResult(result, '$');
    }

    for (i = 0; i < count; i++) {
        for (j = 2; production[i][j] != '\0'; j++) {
            if (production[i][j] == c) {
                // Check symbols following 'c'
                if (production[i][j + 1] != '\0') {
                    FIRST(subResult, production[i][j + 1]);
                    
                    // Add everything from FIRST except '#'
                    for (k = 0; subResult[k] != '\0'; k++) {
                        if (subResult[k] != '#') {
                            addToResult(result, subResult[k]);
                        }
                    }

                    // If FIRST contains '#', recursively find FOLLOW of the LHS symbol
                    for (k = 0; subResult[k] != '\0'; k++) {
                        if (subResult[k] == '#' && production[i][0] != c) {
                            FOLLOW(subResult, production[i][0]);
                            for (int l = 0; subResult[l] != '\0'; l++) {
                                addToResult(result, subResult[l]);
                            }
                        }
                    }
                } 
                // If 'c' is at the end of the RHS, find FOLLOW of LHS
                else if (production[i][0] != c) {
                    FOLLOW(subResult, production[i][0]);
                    for (k = 0; subResult[k] != '\0'; k++) {
                        addToResult(result, subResult[k]);
                    }
                }
            }
        }
    }
}

int main() {
    int i;
    char choice;
    char c;
    char result[20];

    printf("Enter the number of production rules: ");
    scanf("%d", &count);

    printf("Enter rules in the format 'E=TR' (Use '#' for epsilon):\n");
    for (i = 0; i < count; i++) {
        scanf("%s", production[i]);
    }

    printf("\n--- FIRST Sets ---\n");
    for (i = 0; i < count; i++) {
        c = production[i][0];
        FIRST(result, c);
        printf("FIRST(%c) = { ", c);
        for (int j = 0; result[j] != '\0'; j++) {
            printf("%c ", result[j]);
        }
        printf("}\n");
    }

    printf("\n--- FOLLOW Sets ---\n");
    for (i = 0; i < count; i++) {
        c = production[i][0];
        FOLLOW(result, c);
        printf("FOLLOW(%c) = { ", c);
        for (int j = 0; result[j] != '\0'; j++) {
            printf("%c ", result[j]);
        }
        printf("}\n");
    }

    return 0;
}
