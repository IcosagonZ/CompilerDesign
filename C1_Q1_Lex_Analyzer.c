#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isKeyword(char buffer[]) {
    char keywords[10][10] = {"int", "float", "if", "else", "while", "return", "void", "char", "for", "do"};
    for (int i = 0; i < 10; ++i) {
        if (strcmp(keywords[i], buffer) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char ch, buffer[30], operators[] = "+-*/=%<>";
    int i, j;

    FILE *fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error opening input file.\n");
        return 0;
    }

    while ((ch = fgetc(fp)) != EOF) {
        if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r') {
            continue;
        }

        for (i = 0; i < strlen(operators); ++i) {
            if (ch == operators[i]) {
                printf("%c : Operator\n", ch);
                break;
            }
        }

        if (isalnum(ch)) {
            buffer[0] = ch;
            j = 1;
            while (isalnum(ch = fgetc(fp))) {
                buffer[j++] = ch;
            }
            buffer[j] = '\0';

            ungetc(ch, fp);

            if (isKeyword(buffer)) {
                printf("%s : Keyword\n", buffer);
            } else if (isdigit(buffer[0])) {
                printf("%s : Number\n", buffer);
            } else {
                printf("%s : Identifier\n", buffer);
            }
        }
    }

    fclose(fp);
    return 0;
}
