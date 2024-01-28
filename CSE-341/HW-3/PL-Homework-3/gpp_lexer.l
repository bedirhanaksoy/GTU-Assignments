
%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "y.tab.h"
%}

%%

"and"       { return KW_AND; }
"or"        { return KW_OR; }
"not"       { return KW_NOT; }
"set"       { return KW_SET; }
"equal"     { return KW_EQUAL; }
"less"      { return KW_LESS; }
"nil"       { return KW_NIL; }
"append"    { return KW_APPEND; }
"concat"    { return KW_CONCAT; }
"exit"      { return KW_EXIT;}
"def"       { return KW_DEF; }
"for"       { return KW_FOR; }
"if"        { return KW_IF; }
"load"      { return KW_LOAD; }
"list"      { return KW_LIST; }
"display"   { return KW_DISPLAY; }
"true"      { return KW_TRUE; }
"false"     { return KW_FALSE; }

"+"         { return OP_PLUS; }
"-"         { return OP_MINUS; }
"/"         { return OP_DIV; }
"*"         { return OP_MULT; }
"("         { return OP_OP; }
")"         { return OP_CP; }
","         { return OP_COMMA; }


";;".*      { return COMMENT; }
[0-9]+b[0-9]+ { yylval.valuef = strdup(yytext); return VALUEF; }
[a-zA-Z][a-zA-Z0-9]* { yylval.identifier = strdup(yytext); return IDENTIFIER; }

[a-zA-Z][a-zA-Z0-9]*[+\-*/] { printf("SYNTAX_ERROR: No space between identifier and operator: '%s'\n", yytext); return 0; }
[+\-*/][a-zA-Z][a-zA-Z0-9]* { printf("SYNTAX_ERROR: No space between operator and identifier: '%s'\n", yytext); return 0; }


"\n"        {;}
" "         {;}
"\t"        {;}

.           { printf("SYNTAX_ERROR '%s' cannot be tokenized\n", yytext); return 0; }

%%

int yywrap() { }