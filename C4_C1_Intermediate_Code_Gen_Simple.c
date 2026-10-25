#include <stdio.h>
#include <string.h>
#include <ctype.h>

int temp_count = 1;

void generate_tac(char exp[]) {
    char op[] = {'/', '*', '-', '+'}; // Operator precedence order
    char left, right;
    char temp_str[100];
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; exp[j] != '\0'; j++) {
            if (exp[j] == op[i]) {
                left = exp[j - 1];
                right = exp[j + 1];

                // Print the Three-Address Code statement
                printf("t%d = %c %c %c\n", temp_count, left, op[i], right);

                // Replace the sub-expression with the temporary variable (e.g., '1' for t1)
                exp[j - 1] = 't';
                exp[j] = temp_count + '0';
                
                // Shift remaining characters left to overwrite the right operand
                for (int k = j + 1; exp[k] != '\0'; k++) {
                    exp[k] = exp[k + 1];
                }

                temp_count++;
                j = -1; // Reset loop to scan from start for same priority operator
            }
        }
    }
}

int main() {
    char expr[50];

    printf("Enter a simple expression (e.g., a+b*c): ");
    scanf("%s", expr);

    printf("\nThree-Address Code (TAC):\n");
    generate_tac(expr);

    return 0;
}
