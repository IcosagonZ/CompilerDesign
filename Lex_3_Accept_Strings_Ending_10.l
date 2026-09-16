%{
#include <stdio.h>
%}

%s ST1 ST2

%%

<INITIAL>1    { BEGIN ST1; }
<INITIAL>0    { BEGIN INITIAL; }

<ST1>0        { BEGIN ST2; }
<ST1>1        { BEGIN ST1; }

<ST2>1        { BEGIN ST1; }
<ST2>0        { BEGIN INITIAL; }

<ST2>\n       { printf("ACCEPTED\n"); BEGIN INITIAL; }
<INITIAL>\n   { printf("REJECTED\n"); BEGIN INITIAL; }
<ST1>\n       { printf("REJECTED\n"); BEGIN INITIAL; }

.             { printf("Invalid character\n"); BEGIN INITIAL; }

%%

int yywrap() {
    return 1;
}

int main() {
    printf("Enter string: ");
    yylex();
    return 0;
}
