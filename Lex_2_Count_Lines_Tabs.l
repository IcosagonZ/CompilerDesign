%{
#include <stdio.h>
int line_count = 0;
int tab_count = 0;
%}

%%
\n      { line_count++; }
\t      { tab_count++; }
.       { /* Ignore other char */ }
%%

int yywrap() {
    return 1;
}

int main() {
    printf("Enter input: \n");
    yylex();
    printf("\nNumber of lines: %d\n", line_count);
    printf("Number of tabs: %d\n", tab_count);
    return 0;
}
