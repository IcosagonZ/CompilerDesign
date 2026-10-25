#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char tac[20][30];
    char op[10], arg1[10], arg2[10], res[10];
    int n, i;

    printf("Enter the number of 3-Address Code statements: ");
    scanf("%d", &n);

    printf("Enter TAC statements (e.g., t1 = a + b or t2 = c):\n");
    for (i = 0; i < n; i++) {
        scanf(" %[^\n]", tac[i]);
    }

    printf("\n--- Generated 8086 Assembly Code ---\n");

    for (i = 0; i < n; i++) {
        // Case 1: Binary Operation (e.g., res = arg1 op arg2)
        if (sscanf(tac[i], "%s = %s %s %s", res, arg1, op, arg2) == 4) {
            printf("; Statement: %s\n", tac[i]);
            printf("MOV AX, %s\n", arg1);
            
            if (strcmp(op, "+") == 0) {
                printf("ADD AX, %s\n", arg2);
            } else if (strcmp(op, "-") == 0) {
                printf("SUB AX, %s\n", arg2);
            } else if (strcmp(op, "*") == 0) {
                printf("IMUL %s\n", arg2);
            } else if (strcmp(op, "/") == 0) {
                printf("MOV DX, 0\n"); // Clear DX for 16-bit division
                printf("IDIV %s\n", arg2);
            }
            printf("MOV %s, AX\n\n", res);
        } 
        // Case 2: Assignment / Simple Move (e.g., res = arg1)
        else if (sscanf(tac[i], "%s = %s", res, arg1) == 2) {
            printf("; Statement: %s\n", tac[i]);
            printf("MOV AX, %s\n", arg1);
            printf("MOV %s, AX\n\n", res);
        }
    }

    return 0;
}
