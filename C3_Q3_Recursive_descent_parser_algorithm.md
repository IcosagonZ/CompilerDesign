#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char *ip;

void E(), T(), F();

void match(char c) {
    if (*ip == c) ip++;
    else { printf("Rejected\n"); exit(0); }
}

void F() {
    if (isalnum(*ip)) ip++;
    else if (*ip == '(') { match('('); E(); match(')'); }
    else { printf("Rejected\n"); exit(0); }
}

void T() {
    F();
    while (*ip == '*' || *ip == '/') { ip++; F(); }
}

void E() {
    T();
    while (*ip == '+' || *ip == '-') { ip++; T(); }
}

int main() {
    char str[100];
    printf("Enter expression: ");
    scanf("%s", str);
    ip = str;
    E();
    if (*ip == '\0') printf("Accepted\n");
    else printf("Rejected\n");
    return 0;
}
