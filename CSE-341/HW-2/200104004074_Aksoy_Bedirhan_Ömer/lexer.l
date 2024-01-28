
%{  
    // stdio.h for print operations
#include <stdio.h>                  
%}



%%
    // keyword declarations
"and" {printf("KW_AND\n");}     
"or" {printf("KW_OR\n");}
"not" {printf("KW_NOT\n");}
"equal" {printf("KW_EQUAL\n");}
"less" {printf("KW_LESS\n");}
"nil" {printf("KW_NIL\n");}
"list" {printf("KW_LIST\n");}
"append" {printf("KW_APPEND\n");}
"concat" {printf("KW_CONCAT\n");}
"set" {printf("KW_SET\n");}
"def" {printf("KW_DEF\n");}
"for" {printf("KW_FOR\n");}
"if" {printf("KW_IF\n");}
"exit" {printf("KW_EXIT\n"); return 0;}
"load" {printf("KW_LOAD\n");}
"display" {printf("KW_DISPLAY\n");}
"true" {printf("KW_TRUE\n");}
"false" {printf("KW_FALSE\n");}

"+" {printf("OP_PLUS\n");}
"-" {printf("OP_MINUS\n");}
"/" {printf("OP_DIV\n");}
"*" {printf("OP_MULT\n");}
"(" {printf("OP_OP\n");}
")" {printf("OP_CP\n");}
"," {printf("OP_COMMA\n");}
" " {;}
"\n" {;}
"\t" {;}

    
";;".* {printf("COMMENT\n"); /* comments all the line*/}           

    
[0-9]+b[0-9]+ {printf("VALUEF\n"); /* valuef definition*/}     

    
[a-zA-z][a-zA-z0-9]* {printf("IDENTIFIER\n"); /* identifier definition*/}  

    
. { printf("SYNTAX ERROR: '%s' cannot be tokenized\n",yytext); return 0; /* rest of this definitions are errors and they cannot be tokenized*/} 

%%

   
int yywrap(){/* yywrap handles EOF condition and lex stop scanning */} 


int main(int argc , char** argv){
    if (argc == 1)
    {
        printf("Enter input:");
    }
    else if (argc == 2)
    {
        FILE *fp;
        fp = fopen(argv[1], "r");
        yyin = fp;
    }
    else 
    {
        printf("Too many arguments\n");
        return 0;
    }

        // yylex recognizes and returns tokens from input stream
    yylex(); 
}