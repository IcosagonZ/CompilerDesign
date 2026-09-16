%{
#include <stdio.h>
%}

%%
" "     { printf("$"); }
.|\n    { ECHO; }
%%

int yywrap() {
    return 1;
}

int main() {
    printf("Enter text: ");
    yylex();
    return 0;
}
