#include <stdio.h>
#include <string.h>

char stack[20], input[20];
int top = -1, len = 0, i = 0;

void print_status(char *action) {
    stack[top + 1] = '\0';
    printf("$%-10s\t%-10s$\t%s\n", stack, input + i, action);
}

void check() {
    // Reduce rule: E -> id (using 'i' to represent 'id')
    for (int j = 0; j <= top; j++) {
        if (stack[j] == 'i') {
            stack[j] = 'E';
            print_status("REDUCE E -> id");
        }
    }

    // Reduce rules: E -> E+E and E -> E*E
    if (top >= 2) {
        if ((stack[top-2] == 'E' && stack[top-1] == '+' && stack[top] == 'E') ||
            (stack[top-2] == 'E' && stack[top-1] == '*' && stack[top] == 'E')) {
            
            char op = stack[top-1];
            top -= 2;
            stack[top] = 'E';
            
            if (op == '+') print_status("REDUCE E -> E+E");
            else print_status("REDUCE E -> E*E");
        }
    }
}

int main() {
    printf("Grammar:\n E -> E + E\n E -> E * E\n E -> id\n\n");
    printf("Enter input string (use 'i' for id): ");
    scanf("%s", input);
    len = strlen(input);

    printf("\nSTACK\t\tINPUT\t\tACTION\n");
    printf("--------------------------------------------\n");

    for (i = 0; i < len; i++) {
        print_status("SHIFT");
        top++;
        stack[top] = input[i];
        
        check();
    }

    // Final check for any remaining reductions after last shift
    check();

    if (top == 0 && stack[top] == 'E') {
        printf("\nResult: String Accepted!\n");
    } else {
        printf("\nResult: String Rejected!\n");
    }

    return 0;
}
