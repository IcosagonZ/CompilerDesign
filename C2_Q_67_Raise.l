%{
#include "y.tab.h"
%}

%%

0       { return ZERO; }
1       { return ONE; }
\n      { return '\n'; }   /* Pass newline to Yacc so it knows input is complete */
[ \t]   ;                  /* Ignore whitespace (spaces/tabs) */
.       { return yytext[0]; } /* Return invalid characters directly */

%%

int yywrap()
{
    return 1;
}
