%

#include <stdio.h>

%}

%%

[a-zA-Z] [a-zA-Z0-9]* {printf("Identifier:%s \n",yytext);} {printf("Ignore");}

%%

int yywrap() { }

return 1;

int main()

printf("Eneter the string to analyze:\n");

yylex();

return 0;