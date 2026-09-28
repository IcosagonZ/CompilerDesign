%{
#include <stdio.h>
#include <stdlib.h>
%}

%token ZERO ONE

%%

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

int yyerror(char *s)
{
    printf("Invalid string\n");
    return 0;
}