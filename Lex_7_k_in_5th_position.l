%{
#include <stdio.h>
int count = 0;
%}

%%

^[a-zA-Z0-9]{4}[kK][a-zA-Z0-9]*  { count++; }
[a-zA-Z0-9]+                     { /* Ignore other words */ }
[ \t\n]+                         { /* Ignore whitespace and newlines */ }
.                                { /* Ignore other chars */ }

%%

int yywrap() {
    return 1;
}

int main() {
    printf("Enter strings:\n");
    yylex();
    printf("\nTotal strings with 'k' in the 5th position: %d\n", count);
    return 0;
}
