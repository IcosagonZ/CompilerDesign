%{
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
void yyerror(const char *s);
%}

%token ZERO ONE

%%

/* Axiom rule: Requires a newline at the end to trigger success output */
input: S '\n' { printf("Valid string\n"); exit(0); }
     ;

S : ZERO S ONE
  | ZERO ONE
  ;

%%

int main()
{
    printf("Enter a string: ");
    yyparse();
    return 0;
}

void yyerror(const char *s)
{
    printf("Invalid string\n");
    exit(0);
}
