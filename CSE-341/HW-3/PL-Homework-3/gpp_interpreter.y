%{
        #include <stdio.h>
        #include <stdlib.h>
        #include <string.h>
    typedef enum
    {
        VALUEF_NODE,
        ADD_NODE,
        SUBTRACT_NODE,
        MULTIPLY_NODE,
        DIVIDE_NODE,
        FUNC_CALL_NODE,
        ID_NODE
    } TypeOfTheNode;

    struct abstr_syntx_tree_node
    {
        TypeOfTheNode type;
        union
        {
            char *valuef;     // for VALUEF nodes
            char *identifier; // for IDENTIFIER nodes
            struct
            { // for binary operation nodes
                struct abstr_syntx_tree_node *left;
                struct abstr_syntx_tree_node *right;
            } binary;
            struct
            { // for function call nodes
                struct abstr_syntx_tree_node *name;
                struct abstr_syntx_tree_node **args;
                int arg_count;
            } function_call;
        } data;
    };
    typedef struct abstr_syntx_tree_node abs_stx_tree_node;

    struct funct_def
    {
        abs_stx_tree_node *name;
        abs_stx_tree_node *function_body;
        abs_stx_tree_node **params;
        int param_count;
    };
    typedef struct funct_def funct_def;

    struct symbol_table
    {
        funct_def **functions;
        int function_count;
    };
    typedef struct symbol_table symbol_table;

    symbol_table *symbl_table_create()
    {
        symbol_table *table = (symbol_table *)malloc(sizeof(symbol_table));
        table->functions = NULL;
        table->function_count = 0;
        return table;
    }

    void add_func_to_symbl_table(symbol_table *table, funct_def *function)
    {
        table->function_count++;
        table->functions = (funct_def **)realloc(table->functions, sizeof(funct_def *) * table->function_count);
        table->functions[table->function_count - 1] = function;
    }

    funct_def *func_search_in_symbl_table(symbol_table *table, abs_stx_tree_node *name)
    {
        for (int i = 0; i < table->function_count; i++)
        {
            if (strcmp(table->functions[i]->name->data.identifier, name->data.identifier) == 0)
            {
                return table->functions[i];
            }
        }
        return NULL;
    }

    funct_def *func_create(abs_stx_tree_node *name, abs_stx_tree_node **params, int param_count, abs_stx_tree_node *function_body)
    {
        funct_def *function = malloc(sizeof(funct_def));
        if (function == NULL)
        {
            fprintf(stderr, "Error: Out of memory\n");
            exit(1);
        }
        function->name = name;
        function->params = params;
        function->param_count = param_count;
        function->function_body = function_body;
        return function;
    }

    abs_stx_tree_node *node_const_create(char *value)
    {
        abs_stx_tree_node *node = (abs_stx_tree_node *)malloc(sizeof(abs_stx_tree_node));
        if (node == NULL)
        {
            fprintf(stderr, "Error: Out of memory\n");
            exit(1);
        }
        node->type = VALUEF_NODE;
        node->data.valuef = strdup(value);
        return node;
    }

    abs_stx_tree_node *ID_NODE_create(char *identifier)
    {
        abs_stx_tree_node *node = (abs_stx_tree_node *)malloc(sizeof(abs_stx_tree_node));
        if (node == NULL)
        {
            fprintf(stderr, "Error: Out of memory\n");
            exit(1);
        }
        node->type = ID_NODE;
        node->data.identifier = strdup(identifier);
        return node;
    }

    abs_stx_tree_node *binary_node_create(TypeOfTheNode type, abs_stx_tree_node *left, abs_stx_tree_node *right)
    {
        abs_stx_tree_node *node = (abs_stx_tree_node *)malloc(sizeof(abs_stx_tree_node));
        if (node == NULL)
        {
            fprintf(stderr, "Error: Out of memory\n");
            exit(1);
        }
        node->type = type;
        node->data.binary.left = left;
        node->data.binary.right = right;
        return node;
    }

    abs_stx_tree_node *FUNC_CALL_NODE_create(abs_stx_tree_node *name, abs_stx_tree_node **args, int arg_count)
    {
        abs_stx_tree_node *node = (abs_stx_tree_node *)malloc(sizeof(abs_stx_tree_node));
        if (node == NULL)
        {
            fprintf(stderr, "Error: Out of memory\n");
            exit(1);
        }
        node->type = FUNC_CALL_NODE;
        node->data.function_call.name = name;
        node->data.function_call.args = args;
        node->data.function_call.arg_count = arg_count;
        return node;
    }

    int greatest_common_divisor(int a, int b)
    {
        if (b == 0)
        {
            return a;
        }
        return greatest_common_divisor(b, a % b);
    }

    void simplify_result(int *numerator, int *denominator)
    {
        int common = greatest_common_divisor(*numerator, *denominator);
        *numerator /= common;
        *denominator /= common;
    }

    char *VALUEF_operations(char operatorType, char *a, char *b)
    {
        int lenA = strlen(a);
        int lenB = strlen(b);

        int posBInA = strchr(a, 'b') - a;
        int posBInB = strchr(b, 'b') - b;

        char beforeDecimalA[posBInA + 1];
        char afterDecimalA[lenA - posBInA];
        char beforeDecimalB[posBInB + 1];
        char afterDecimalB[lenB - posBInB];

        strncpy(beforeDecimalA, a, posBInA);
        beforeDecimalA[posBInA] = '\0';
        strcpy(afterDecimalA, a + posBInA + 1);

        strncpy(beforeDecimalB, b, posBInB);
        beforeDecimalB[posBInB] = '\0';
        strcpy(afterDecimalB, b + posBInB + 1);

        int intBeforeA = atoi(beforeDecimalA);
        int intAfterA = atoi(afterDecimalA);
        int intBeforeB = atoi(beforeDecimalB);
        int intAfterB = atoi(afterDecimalB);

        int resultBefore = 0;
        int resultAfter = 0;

        switch (operatorType)
        {
        case '+':
            resultBefore = intBeforeA * intAfterB + intBeforeB * intAfterA;
            resultAfter = intAfterA * intAfterB;
            break;
        case '-':
            resultBefore = intBeforeA * intAfterB - intBeforeB * intAfterA;
            resultAfter = intAfterA * intAfterB;
            break;
        case '*':
            resultBefore = intBeforeA * intBeforeB;
            resultAfter = intAfterA * intAfterB;
            break;
        case '/':
            if (intBeforeB == 0 || intAfterB == 0)
            {
                fprintf(stderr, "Division by zero is not allowed.\n");
                return NULL;
            }

            resultBefore = intBeforeA * intAfterB;
            resultAfter = intAfterA * intBeforeB;

            break;
        default:
            fprintf(stderr, "Invalid operator type: %c\n", operatorType);
            return NULL;
        }

        simplify_result(&resultBefore, &resultAfter);

        char *result = (char *)malloc(20);
        snprintf(result, 20, "%db%d", resultBefore, resultAfter);
        return result;
    }

    char *evaluate(abs_stx_tree_node *node, symbol_table *table)
    {
        if (node == NULL){
            fprintf(stderr, "Error: Null node encountered.\n");
            exit(EXIT_FAILURE);
        }

        switch (node->type){

        case VALUEF_NODE:

            return node->data.valuef;
            
        case ID_NODE:
        {
            funct_def *function = func_search_in_symbl_table(table, node);
            if (function == NULL)
            {
                return node->data.identifier;
            }

            return evaluate(function->function_body, table);
        }
        case ADD_NODE:
        {
            char *left_value = evaluate(node->data.binary.left, table);

            char *right_value = evaluate(node->data.binary.right, table);

            char *result = VALUEF_operations('+', left_value, right_value);

            // if the immediate values are created dynamically, free them
            free(left_value);
            free(right_value);
            return result;
        }
        case SUBTRACT_NODE:

        {
            char *left_value = evaluate(node->data.binary.left, table);
            char *right_value = evaluate(node->data.binary.right, table);
            char *result = VALUEF_operations('-', left_value, right_value);
            // if the immediate values are created dynamically, free them
            free(left_value);
            free(right_value);
            return result;
        }
        case MULTIPLY_NODE:

        {
            char *left_value = evaluate(node->data.binary.left, table);
            char *right_value = evaluate(node->data.binary.right, table);
            char *result = VALUEF_operations('*', left_value, right_value);
            // if the immediate values are created dynamically, free them
            free(left_value);
            free(right_value);
            return result;
        }
        case DIVIDE_NODE:

        {
            char *left_value = evaluate(node->data.binary.left, table);
            char *right_value = evaluate(node->data.binary.right, table);
            char *result = VALUEF_operations('/', left_value, right_value);
            // if the immediate values are created dynamically, free them
            free(left_value);
            free(right_value);
            return result;
        }
        case FUNC_CALL_NODE:

        {
            funct_def *function = func_search_in_symbl_table(table, node->data.function_call.name);

            if (function == NULL)
            {
                fprintf(stderr, "Error: Undefined function '%s'\n", node->data.function_call.name->data.identifier);
                exit(EXIT_FAILURE);
            }

            // check whether the number of inputs are matching with as expected
            if (node->data.function_call.arg_count != function->param_count)
            {
                fprintf(stderr, "Error: Function '%s' expects %d arguments, but %d were provided\n",
                        node->data.function_call.name->data.identifier, function->param_count, node->data.function_call.arg_count);
                exit(EXIT_FAILURE);
            }

            char *evaluateuated_args[100];
            for (int i = 0; i < function->param_count; i++){

                evaluateuated_args[i] = evaluate(node->data.function_call.args[i], table);
            }
            if (function->param_count == 1){

                function->function_body->data.binary.left = node_const_create(evaluateuated_args[0]);
                function->function_body->data.binary.right = node_const_create(evaluateuated_args[0]);
            }
            else if (function->param_count == 2){
                function->function_body->data.binary.left = node_const_create(evaluateuated_args[0]);
                function->function_body->data.binary.right = node_const_create(evaluateuated_args[1]);
            }
            char *result = evaluate(function->function_body, table);

            return result;
        }
        default:
            fprintf(stderr, "Error: Unsupported node type\n");
            exit(EXIT_FAILURE);
        }
    }

    symbol_table* table;
    extern int yylex();
    void yyerror (char *s);

%}



%union {
    char* str;
    char* valuef;
    char* identifier;
    struct abstr_syntx_tree_node* node;
    struct funct_def* function;
}

%token <valuef> VALUEF
%token <identifier> IDENTIFIER
%token KW_AND KW_OR KW_NOT KW_EQUAL KW_LESS KW_NIL KW_LIST KW_APPEND KW_CONCAT KW_SET KW_DEF KW_FOR KW_IF KW_EXIT KW_LOAD KW_DISPLAY KW_TRUE KW_FALSE 
%token OP_PLUS OP_MINUS OP_DIV OP_MULT OP_OP OP_CP OP_COMMA COMMENT


%start START

%type <str> INPUT
%type <node> EXP
%type <function> FUNCTION

%% 

START: | START INPUT 

INPUT: EXP { printf("%s\n", evaluate($1, table)); }
        | FUNCTION { add_func_to_symbl_table(table, $1); printf("#function\n"); }
        | OP_OP KW_EXIT OP_CP {exit(EXIT_SUCCESS);}
    | COMMENT { printf("Result: COMMENT\n"); }
    ;

EXP: OP_OP OP_PLUS EXP EXP OP_CP { $$ = binary_node_create(ADD_NODE, $3, $4); }
    | OP_OP OP_MINUS EXP EXP OP_CP { $$ = binary_node_create(SUBTRACT_NODE, $3, $4); }
    | OP_OP OP_MULT EXP EXP OP_CP { $$ = binary_node_create(MULTIPLY_NODE, $3, $4); }
    | OP_OP OP_DIV EXP EXP OP_CP { $$ = binary_node_create(DIVIDE_NODE, $3, $4); }
    | OP_OP IDENTIFIER EXP OP_CP { $$ = FUNC_CALL_NODE_create(ID_NODE_create($2), (abs_stx_tree_node*[]){$3}, 1); }
    | OP_OP IDENTIFIER EXP EXP OP_CP { $$ = FUNC_CALL_NODE_create(ID_NODE_create($2), (abs_stx_tree_node*[]){$3, $4}, 2); }
    | IDENTIFIER { $$ = ID_NODE_create($1); }
    | VALUEF { $$ = node_const_create($1); }
    ;

FUNCTION: OP_OP KW_DEF IDENTIFIER EXP OP_CP { $$ = func_create(ID_NODE_create($3), NULL, 0, $4); }
        | OP_OP KW_DEF IDENTIFIER IDENTIFIER EXP OP_CP { $$ = func_create(ID_NODE_create($3), (abs_stx_tree_node*[]){ID_NODE_create($4)}, 1, $5); }
        | OP_OP KW_DEF IDENTIFIER IDENTIFIER IDENTIFIER EXP OP_CP { $$ = func_create(ID_NODE_create($3), (abs_stx_tree_node*[]){ID_NODE_create($4), ID_NODE_create($5)}, 2, $6); }
    ;

%%

void yyerror(char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main(void) {
    table = symbl_table_create();

    return yyparse();
}