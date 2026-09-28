%{
#include <stdio.h>
#include <stdlib.h>

void yyerror(const char *s);
int yylex(void);
%}

%token NUMBER

/* Operator precedence and associativity */
%left '+' '-'
%left '*' '/'

%%

input:
    /* empty */
  | input line
  ;

line:
    '\n'
  | expr '\n' { printf("Result = %d\n", $1); }
  ;

expr:
    NUMBER          { $$ = $1; }
  | expr '+' expr   { $$ = $1 + $3; }
  | expr '-' expr   { $$ = $1 - $3; }
  | expr '*' expr   { $$ = $1 * $3; }
  | expr '/' expr   { 
                        if ($3 == 0) {
                            yyerror("Division by zero");
                            $$ = 0;
                        } else {
                            $$ = $1 / $3;
                        }
                    }
  | '(' expr ')'    { $$ = $2; }
  ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main() {
    printf("Enter expression:\n");
    yyparse();
    return 0;
}
