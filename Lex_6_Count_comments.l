%{
#include <stdio.h>
int comment_count = 0;
%}

%%
"//".*                  { comment_count++; }
"/*"([^*]|\*+[^/*])*"*/" { comment_count++; }
.|\n                    { ; }
%%

int yywrap() {
    return 1;
}

int main() {
    yylex();
    printf("Number of comments: %d\n", comment_count);
    return 0;
}
