%{
#include <stdio.h>
#include <stdlib.h>

int yylex();
void yyerror(const char *s);
%}

%token LETTER DIGIT

%%
stmt:
    expr '\n'   { printf("Valid variable name\n"); exit(0); }
    ;

expr:
    LETTER body
    ;

body:
    body LETTER
    | body DIGIT
    | /* empty */
    ;
%%

void yyerror(const char *s) {
    printf("Invalid variable name\n");
    exit(0);
}

int main() {
    printf("Enter a variable name: ");
    yyparse();
    return 0;
}
