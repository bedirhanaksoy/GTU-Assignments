/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "gpp_interpreter.y"

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


#line 421 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    VALUEF = 258,                  /* VALUEF  */
    IDENTIFIER = 259,              /* IDENTIFIER  */
    KW_AND = 260,                  /* KW_AND  */
    KW_OR = 261,                   /* KW_OR  */
    KW_NOT = 262,                  /* KW_NOT  */
    KW_EQUAL = 263,                /* KW_EQUAL  */
    KW_LESS = 264,                 /* KW_LESS  */
    KW_NIL = 265,                  /* KW_NIL  */
    KW_LIST = 266,                 /* KW_LIST  */
    KW_APPEND = 267,               /* KW_APPEND  */
    KW_CONCAT = 268,               /* KW_CONCAT  */
    KW_SET = 269,                  /* KW_SET  */
    KW_DEF = 270,                  /* KW_DEF  */
    KW_FOR = 271,                  /* KW_FOR  */
    KW_IF = 272,                   /* KW_IF  */
    KW_EXIT = 273,                 /* KW_EXIT  */
    KW_LOAD = 274,                 /* KW_LOAD  */
    KW_DISPLAY = 275,              /* KW_DISPLAY  */
    KW_TRUE = 276,                 /* KW_TRUE  */
    KW_FALSE = 277,                /* KW_FALSE  */
    OP_PLUS = 278,                 /* OP_PLUS  */
    OP_MINUS = 279,                /* OP_MINUS  */
    OP_DIV = 280,                  /* OP_DIV  */
    OP_MULT = 281,                 /* OP_MULT  */
    OP_OP = 282,                   /* OP_OP  */
    OP_CP = 283,                   /* OP_CP  */
    OP_COMMA = 284,                /* OP_COMMA  */
    COMMENT = 285                  /* COMMENT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define VALUEF 258
#define IDENTIFIER 259
#define KW_AND 260
#define KW_OR 261
#define KW_NOT 262
#define KW_EQUAL 263
#define KW_LESS 264
#define KW_NIL 265
#define KW_LIST 266
#define KW_APPEND 267
#define KW_CONCAT 268
#define KW_SET 269
#define KW_DEF 270
#define KW_FOR 271
#define KW_IF 272
#define KW_EXIT 273
#define KW_LOAD 274
#define KW_DISPLAY 275
#define KW_TRUE 276
#define KW_FALSE 277
#define OP_PLUS 278
#define OP_MINUS 279
#define OP_DIV 280
#define OP_MULT 281
#define OP_OP 282
#define OP_CP 283
#define OP_COMMA 284
#define COMMENT 285

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 353 "gpp_interpreter.y"

    char* str;
    char* valuef;
    char* identifier;
    struct abstr_syntx_tree_node* node;
    struct funct_def* function;

#line 542 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_VALUEF = 3,                     /* VALUEF  */
  YYSYMBOL_IDENTIFIER = 4,                 /* IDENTIFIER  */
  YYSYMBOL_KW_AND = 5,                     /* KW_AND  */
  YYSYMBOL_KW_OR = 6,                      /* KW_OR  */
  YYSYMBOL_KW_NOT = 7,                     /* KW_NOT  */
  YYSYMBOL_KW_EQUAL = 8,                   /* KW_EQUAL  */
  YYSYMBOL_KW_LESS = 9,                    /* KW_LESS  */
  YYSYMBOL_KW_NIL = 10,                    /* KW_NIL  */
  YYSYMBOL_KW_LIST = 11,                   /* KW_LIST  */
  YYSYMBOL_KW_APPEND = 12,                 /* KW_APPEND  */
  YYSYMBOL_KW_CONCAT = 13,                 /* KW_CONCAT  */
  YYSYMBOL_KW_SET = 14,                    /* KW_SET  */
  YYSYMBOL_KW_DEF = 15,                    /* KW_DEF  */
  YYSYMBOL_KW_FOR = 16,                    /* KW_FOR  */
  YYSYMBOL_KW_IF = 17,                     /* KW_IF  */
  YYSYMBOL_KW_EXIT = 18,                   /* KW_EXIT  */
  YYSYMBOL_KW_LOAD = 19,                   /* KW_LOAD  */
  YYSYMBOL_KW_DISPLAY = 20,                /* KW_DISPLAY  */
  YYSYMBOL_KW_TRUE = 21,                   /* KW_TRUE  */
  YYSYMBOL_KW_FALSE = 22,                  /* KW_FALSE  */
  YYSYMBOL_OP_PLUS = 23,                   /* OP_PLUS  */
  YYSYMBOL_OP_MINUS = 24,                  /* OP_MINUS  */
  YYSYMBOL_OP_DIV = 25,                    /* OP_DIV  */
  YYSYMBOL_OP_MULT = 26,                   /* OP_MULT  */
  YYSYMBOL_OP_OP = 27,                     /* OP_OP  */
  YYSYMBOL_OP_CP = 28,                     /* OP_CP  */
  YYSYMBOL_OP_COMMA = 29,                  /* OP_COMMA  */
  YYSYMBOL_COMMENT = 30,                   /* COMMENT  */
  YYSYMBOL_YYACCEPT = 31,                  /* $accept  */
  YYSYMBOL_START = 32,                     /* START  */
  YYSYMBOL_INPUT = 33,                     /* INPUT  */
  YYSYMBOL_EXP = 34,                       /* EXP  */
  YYSYMBOL_FUNCTION = 35                   /* FUNCTION  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   63

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  31
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  5
/* YYNRULES -- Number of rules.  */
#define YYNRULES  18
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  44

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   285


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   375,   375,   375,   377,   378,   379,   380,   383,   384,
     385,   386,   387,   388,   389,   390,   393,   394,   395
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "VALUEF", "IDENTIFIER",
  "KW_AND", "KW_OR", "KW_NOT", "KW_EQUAL", "KW_LESS", "KW_NIL", "KW_LIST",
  "KW_APPEND", "KW_CONCAT", "KW_SET", "KW_DEF", "KW_FOR", "KW_IF",
  "KW_EXIT", "KW_LOAD", "KW_DISPLAY", "KW_TRUE", "KW_FALSE", "OP_PLUS",
  "OP_MINUS", "OP_DIV", "OP_MULT", "OP_OP", "OP_CP", "OP_COMMA", "COMMENT",
  "$accept", "START", "INPUT", "EXP", "FUNCTION", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-22)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -22,     0,   -22,   -22,   -22,    33,   -22,   -22,   -22,   -22,
      17,     2,   -21,    17,    17,    17,    17,    37,    -2,    20,
     -22,    17,    17,    17,    17,   -22,   -16,    28,   -13,     5,
       6,     7,     8,   -22,    17,    10,   -22,   -22,   -22,   -22,
     -22,    11,   -22,   -22
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     1,    15,    14,     0,     7,     3,     4,     5,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       6,     0,     0,     0,     0,    12,     0,    14,     0,     0,
       0,     0,     0,    13,    14,     0,    16,     8,     9,    11,
      10,     0,    17,    18
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -22,   -22,   -22,    -5,   -22
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     7,     8,     9
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
       2,     3,     4,     3,     4,    18,    19,    20,    21,    22,
      23,    24,    33,    26,    28,    36,    29,    30,    31,    32,
       3,     4,    35,     3,    27,    17,    25,     5,     0,    41,
       6,     3,    34,    37,    38,    39,    40,    10,    42,    43,
       0,    10,     0,     0,    17,     0,     0,    17,    11,     0,
       0,    12,     0,     0,     0,    17,    13,    14,    15,    16,
      13,    14,    15,    16
};

static const yytype_int8 yycheck[] =
{
       0,     3,     4,     3,     4,    10,     4,    28,    13,    14,
      15,    16,    28,    18,    19,    28,    21,    22,    23,    24,
       3,     4,    27,     3,     4,    27,    28,    27,    -1,    34,
      30,     3,     4,    28,    28,    28,    28,     4,    28,    28,
      -1,     4,    -1,    -1,    27,    -1,    -1,    27,    15,    -1,
      -1,    18,    -1,    -1,    -1,    27,    23,    24,    25,    26,
      23,    24,    25,    26
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    32,     0,     3,     4,    27,    30,    33,    34,    35,
       4,    15,    18,    23,    24,    25,    26,    27,    34,     4,
      28,    34,    34,    34,    34,    28,    34,     4,    34,    34,
      34,    34,    34,    28,     4,    34,    28,    28,    28,    28,
      28,    34,    28,    28
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    31,    32,    32,    33,    33,    33,    33,    34,    34,
      34,    34,    34,    34,    34,    34,    35,    35,    35
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     3,     1,     5,     5,
       5,     5,     4,     5,     1,     1,     5,     6,     7
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 4: /* INPUT: EXP  */
#line 377 "gpp_interpreter.y"
           { printf("%s\n", evaluate((yyvsp[0].node), table)); }
#line 1576 "y.tab.c"
    break;

  case 5: /* INPUT: FUNCTION  */
#line 378 "gpp_interpreter.y"
                   { add_func_to_symbl_table(table, (yyvsp[0].function)); printf("#function\n"); }
#line 1582 "y.tab.c"
    break;

  case 6: /* INPUT: OP_OP KW_EXIT OP_CP  */
#line 379 "gpp_interpreter.y"
                              {exit(EXIT_SUCCESS);}
#line 1588 "y.tab.c"
    break;

  case 7: /* INPUT: COMMENT  */
#line 380 "gpp_interpreter.y"
              { printf("Result: COMMENT\n"); }
#line 1594 "y.tab.c"
    break;

  case 8: /* EXP: OP_OP OP_PLUS EXP EXP OP_CP  */
#line 383 "gpp_interpreter.y"
                                 { (yyval.node) = binary_node_create(ADD_NODE, (yyvsp[-2].node), (yyvsp[-1].node)); }
#line 1600 "y.tab.c"
    break;

  case 9: /* EXP: OP_OP OP_MINUS EXP EXP OP_CP  */
#line 384 "gpp_interpreter.y"
                                   { (yyval.node) = binary_node_create(SUBTRACT_NODE, (yyvsp[-2].node), (yyvsp[-1].node)); }
#line 1606 "y.tab.c"
    break;

  case 10: /* EXP: OP_OP OP_MULT EXP EXP OP_CP  */
#line 385 "gpp_interpreter.y"
                                  { (yyval.node) = binary_node_create(MULTIPLY_NODE, (yyvsp[-2].node), (yyvsp[-1].node)); }
#line 1612 "y.tab.c"
    break;

  case 11: /* EXP: OP_OP OP_DIV EXP EXP OP_CP  */
#line 386 "gpp_interpreter.y"
                                 { (yyval.node) = binary_node_create(DIVIDE_NODE, (yyvsp[-2].node), (yyvsp[-1].node)); }
#line 1618 "y.tab.c"
    break;

  case 12: /* EXP: OP_OP IDENTIFIER EXP OP_CP  */
#line 387 "gpp_interpreter.y"
                                 { (yyval.node) = FUNC_CALL_NODE_create(ID_NODE_create((yyvsp[-2].identifier)), (abs_stx_tree_node*[]){(yyvsp[-1].node)}, 1); }
#line 1624 "y.tab.c"
    break;

  case 13: /* EXP: OP_OP IDENTIFIER EXP EXP OP_CP  */
#line 388 "gpp_interpreter.y"
                                     { (yyval.node) = FUNC_CALL_NODE_create(ID_NODE_create((yyvsp[-3].identifier)), (abs_stx_tree_node*[]){(yyvsp[-2].node), (yyvsp[-1].node)}, 2); }
#line 1630 "y.tab.c"
    break;

  case 14: /* EXP: IDENTIFIER  */
#line 389 "gpp_interpreter.y"
                 { (yyval.node) = ID_NODE_create((yyvsp[0].identifier)); }
#line 1636 "y.tab.c"
    break;

  case 15: /* EXP: VALUEF  */
#line 390 "gpp_interpreter.y"
             { (yyval.node) = node_const_create((yyvsp[0].valuef)); }
#line 1642 "y.tab.c"
    break;

  case 16: /* FUNCTION: OP_OP KW_DEF IDENTIFIER EXP OP_CP  */
#line 393 "gpp_interpreter.y"
                                            { (yyval.function) = func_create(ID_NODE_create((yyvsp[-2].identifier)), NULL, 0, (yyvsp[-1].node)); }
#line 1648 "y.tab.c"
    break;

  case 17: /* FUNCTION: OP_OP KW_DEF IDENTIFIER IDENTIFIER EXP OP_CP  */
#line 394 "gpp_interpreter.y"
                                                       { (yyval.function) = func_create(ID_NODE_create((yyvsp[-3].identifier)), (abs_stx_tree_node*[]){ID_NODE_create((yyvsp[-2].identifier))}, 1, (yyvsp[-1].node)); }
#line 1654 "y.tab.c"
    break;

  case 18: /* FUNCTION: OP_OP KW_DEF IDENTIFIER IDENTIFIER IDENTIFIER EXP OP_CP  */
#line 395 "gpp_interpreter.y"
                                                                  { (yyval.function) = func_create(ID_NODE_create((yyvsp[-4].identifier)), (abs_stx_tree_node*[]){ID_NODE_create((yyvsp[-3].identifier)), ID_NODE_create((yyvsp[-2].identifier))}, 2, (yyvsp[-1].node)); }
#line 1660 "y.tab.c"
    break;


#line 1664 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 398 "gpp_interpreter.y"


void yyerror(char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main(void) {
    table = symbl_table_create();

    return yyparse();
}
