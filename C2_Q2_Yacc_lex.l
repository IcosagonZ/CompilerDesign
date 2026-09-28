%{
#include "y.tab.h"
%}

%%
[a-zA-Z]           { return LETTER; }
[0-9]              { return DIGIT; }
\n                 { return '\n'; }
.                  { /* ignore other characters */ }
%%

int yywrap() {
    return 1;
}
