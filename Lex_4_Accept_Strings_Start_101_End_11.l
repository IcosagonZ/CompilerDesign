%{
#include <stdio.h>
%}

%%

^101[01]*11$  { printf("Accepted\n"); }

^[01]+$       { printf("Rejected\n"); }

\n            { ; }

.             { ; }

%%

int yywrap() {
    return 1;
}

int main() {
    printf("Enter string: ");
    yylex();
    return 0;
}
