#include <stdio.h>
#include <string.h>
#include <ctype.h>

// +    *    id   $
char table[4][4] = {
    { '>', '<', '<', '>' }, // +
    { '>', '>', '<', '>' }, // *
    { '>', '>', 'e', '>' }, // id
    { '<', '<', '<', 'a' }  // $
};

int get_index(char c) {
    if (c == '+') return 0;
    if (c == '*') return 1;
    if (isalnum(c)) return 2;
    if (c == '$') return 3;
    return -1;
}

int main() {
    char stack[100];
    char input[100];
    int top = 0;

    stack[0] = '$';

    printf("Enter input expression (end with $): ");
    scanf("%s", input);

    int i = 0;
    printf("\nStack\t\tRelation\tInput\t\tAction\n");
    printf("---\n");

    while (1) {
        char a = stack[top];
        char b = input[i];

        int row = get_index(a);
        int col = get_index(b);

        if (row == -1 || col == -1) {
            printf("\nInvalid character encountered!\n");
            break;
        }

        char rel = table[row][col];

        // show current state
        stack[top + 1] = '\0';
        printf("%-15s\t%c\t%-15s\t", stack, rel, &input[i]);

        if (rel == '<' || rel == '=') {
            // shift
            top++;
            stack[top] = b;
            i++;
            printf("Shift %c\n", b);
        } else if (rel == '>') {
            // reduce/pop terminal
            char popped = stack[top];
            top--;
            printf("Reduce %c\n", popped);
        } else if (rel == 'a') {
            // accept
            printf("ACCEPTED!\n");
            break;
        } else {
            // error
            printf("REJECTED (Parsing Error)\n");
            break;
        }
    }

    return 0;
}
