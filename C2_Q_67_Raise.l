%{
#include "y.tab.h"
%}

%%

0       { return ZERO; }
1       { return ONE; }
[ \t\n] ;

.       { return yytext[0]; }

%%