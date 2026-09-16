%{
#include <stdio.h>
int vowels = 0;
int spaces = 0;
%}

%%

[aeiouAEIOU] { vowels++; }
[ ]          { spaces++; }
.|\n         ;

%%

int yywrap() {
    return 1;
}

int main() {
    printf("Enter text:\n");
    yylex();
    printf("Vowels: %d\n", vowels);
    printf("Spaces: %d\n", spaces);
    return 0;
}
