%{
#include <stdio.0>
int valid = 1;
%}

%%

[aA][lL][eE][xX]    { valid = 0; }
\n                  { 
                        if (valid) 
                            printf("ACCEPTED\n"); 
                        else 
                            printf("REJECTED\n"); 
                        valid = 1; 
                    }
.                   ;               

%%

int main() {
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}
