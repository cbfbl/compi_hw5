/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.ypp" /* yacc.c:339  */

	#include <iostream>
	#include <stdlib.h>
	#include "source.hpp"
	#include "hw3_output.hpp"
	#include "Scope.h"
    #include "Handle.h"
    #include "bp.hpp"

	using namespace output;

  int yylex();
  extern int yylineno;
  extern char* yytext;
  extern void discoveringYYSTYPE(int yy);
  TypeContainer* binOpType(TypeContainer* lhs, TypeContainer* rhs);
  void typeCheck(TypeContainer* lhs,TypeContainer* rhs);
  void isBool(TypeContainer* con);
  void wasAlreadyDefined(TypeContainer* con);
  void notDefined(TypeContainer* con);
  void CheckDefinedFunc(TypeContainer* con);
  void insertToSymbolTable(TypeContainer* type,TypeContainer* id);
  string getActualType(TypeContainer* some_data);
  int yyerror(const char * message);
  string getRetType(ScopeData some_func);
  void numCheck(TypeContainer* data);
  string getFunctionParametersString(string id);
  vector<string> parseFuncParams(string id);
  string StringFromVec(vector<string> params);
  vector<string> functionTypeToVector(string function_type);
  string getFunctionFullType(string id);
  vector<string> getFunctionParameters(string id);
  void enumTypeCheck(TypeContainer* enumtype,TypeContainer* future_id,TypeContainer* exp);
  vector<ScopeData> createFuncArgsVec(TypeContainer* formals);
  string getRetType(string type);
  string getFunctionRetTypeString(string id);
  string getFunctionRetType(TypeContainer* func);
  void notDefinedVariable(TypeContainer* con);
  Scope table;
  Handler handler(table);
  CodeBuffer& code_buffer = CodeBuffer::instance();
  int while_count = 0;
  string last_function_ret_type = "VOID";
  bool is_main_defined = false;


#line 113 "parser.tab.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.hpp".  */
#ifndef YY_YY_PARSER_TAB_HPP_INCLUDED
# define YY_YY_PARSER_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    BOOL = 258,
    VOID = 259,
    INT = 260,
    BYTE = 261,
    B = 262,
    ENUM = 263,
    TRUE = 264,
    FALSE = 265,
    RETURN = 266,
    WHILE = 267,
    IF = 268,
    BREAK = 269,
    CONTINUE = 270,
    SC = 271,
    COMMA = 272,
    LPAREN = 273,
    RPAREN = 274,
    LBRACE = 275,
    RBRACE = 276,
    ID = 277,
    NUM = 278,
    STRING = 279,
    ASSIGN = 280,
    OR = 281,
    AND = 282,
    RELEQ = 283,
    RELOP = 284,
    BINOPL = 285,
    BINOPH = 286,
    CAST = 287,
    NOT = 288,
    THEN = 289,
    ELSE = 290
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 200 "parser.tab.cpp" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   212

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  143

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   290

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    66,    66,    66,    72,    73,    74,    76,    81,    74,
      93,    94,    94,    98,    98,   108,   109,   110,   111,   112,
     113,   123,   127,   135,   136,   150,   154,   155,   156,   156,
     159,   159,   164,   164,   172,   174,   174,   183,   183,   183,
     191,   192,   193,   196,   196,   199,   201,   202,   202,   209,
     211,   214,   215,   221,   227,   231,   235,   237,   238,   239,
     240,   241,   242,   243,   244,   247,   250,   251,   252,   253,
     260,   261,   262,   263,   267,   272,   277,   280,   283,   283
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "BOOL", "VOID", "INT", "BYTE", "B",
  "ENUM", "TRUE", "FALSE", "RETURN", "WHILE", "IF", "BREAK", "CONTINUE",
  "SC", "COMMA", "LPAREN", "RPAREN", "LBRACE", "RBRACE", "ID", "NUM",
  "STRING", "ASSIGN", "OR", "AND", "RELEQ", "RELOP", "BINOPL", "BINOPH",
  "CAST", "NOT", "THEN", "ELSE", "$accept", "Program", "$@1", "Funcs",
  "FuncDecl", "$@2", "$@3", "$@4", "Enums", "$@5", "EnumDecl", "$@6",
  "RetType", "Formals", "FormalsList", "FormalDecl", "EnumeratorList",
  "Enumerator", "Statements", "Statement", "$@7", "$@8", "$@9", "$@10",
  "$@11", "$@12", "$@13", "$@14", "InsertScope", "RemoveScope",
  "CheckType", "Call", "CheckFunc", "ExpList", "Type", "EnumType", "Exp",
  "$@15", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290
};
# endif

#define YYPACT_NINF -55

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-55)))

#define YYTABLE_NINF -63

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-63)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -55,    13,     6,   -55,    -3,    65,   -55,   -55,   -55,   -55,
     -55,   -55,   -55,    65,   -55,   -55,     6,     8,   -55,     2,
     -55,     3,   -55,   -55,    -5,   -55,    11,     3,    10,   166,
     -55,   -55,    28,    32,   -55,    35,    33,    40,   -55,    34,
     166,   -55,   -55,   -55,   -55,   153,    42,    87,    47,    54,
      14,    61,   -55,    53,   -55,   113,   -55,    68,    67,    66,
      70,    76,   -55,   -55,   -55,    -1,    69,    94,   -55,    90,
     -55,   167,    90,    90,   -55,   -55,   153,    90,   -55,   -55,
     -55,    57,    77,    79,   -55,   181,   -55,   -55,    90,    90,
      90,    90,    90,    90,    91,    96,   167,    98,   133,   154,
     -55,   103,   175,   121,    81,   124,   117,   130,   -55,    12,
     101,     5,    17,   112,   -55,   -55,   -55,   -55,   -55,   -55,
     -55,    90,   -55,    90,   -55,    90,    90,   153,   153,   -55,
     160,   167,   -55,   -55,   -55,   -55,   134,   116,   -55,   -55,
     153,   -55,   -55
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,    10,     1,     0,     4,    11,    13,    61,    16,
      59,    60,     3,     4,     6,    15,    10,     0,     5,     0,
      12,     0,     7,    25,     0,    23,     0,     0,     0,    17,
      24,    14,     0,     0,    18,    19,     0,     0,    62,     0,
       0,    21,    22,     8,    20,     0,     0,     0,     0,     0,
       0,     0,    28,    56,    34,     0,    26,     0,     0,     0,
       0,    13,    71,    72,    42,     0,    66,    68,    70,     0,
      67,    43,     0,     0,    52,    53,     0,     0,     9,    27,
      41,     0,    30,    32,    78,     0,    69,    73,     0,     0,
       0,     0,     0,     0,     0,     0,    51,     0,     0,     0,
      55,     0,    57,     0,     0,     0,     0,     0,    63,    75,
      74,    77,    76,    65,    64,    44,    47,    49,    29,    40,
      54,     0,    31,     0,    33,     0,     0,     0,     0,    58,
       0,    38,    79,    48,    50,    36,     0,    45,    39,    49,
       0,    50,    46
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -55,   -55,   -55,   139,   -55,   -55,   -55,   -55,   141,   -55,
       4,   -55,   -55,   -55,   120,   -55,   -55,   135,   102,   -54,
     -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,    24,    36,
     106,   -45,   -55,    78,    -2,   -22,   -32,   -55
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    12,    13,    19,    26,    45,     5,    16,
      54,    17,    14,    33,    34,    35,    24,    25,    55,    56,
      76,   103,   105,   104,   106,   136,    94,   127,   128,   137,
      95,    70,    58,   101,    59,    60,    96,   107
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      57,    79,     8,    15,    10,    11,     6,    37,    62,    63,
      57,    15,    27,     3,     4,    71,    28,    65,    37,     7,
       6,    66,    67,    68,    22,    23,    31,    36,    21,    29,
      74,    57,    69,    85,    91,    92,    93,    87,    36,    89,
      90,    91,    92,    93,    79,    99,   -63,    92,    93,   102,
      38,    39,    40,    57,    43,    41,   109,   110,   111,   112,
     113,   114,    42,    84,    61,    72,    62,    63,     8,     9,
      10,    11,    73,   133,   134,    65,   100,    75,    77,    66,
      67,    68,    57,    57,    80,    81,   141,   -56,    82,   102,
      69,   130,    83,   131,   132,    57,    62,    63,   -62,    62,
      63,    86,   -35,    64,   -37,    65,   123,   115,    65,    66,
      67,    68,    66,    67,    68,   116,     8,   117,    10,    11,
      69,    46,   120,    69,    47,    48,    49,    50,    51,    90,
      91,    92,    93,    52,    78,    53,     8,   122,    10,    11,
     124,    46,   125,    93,    47,    48,    49,    50,    51,   126,
     138,   139,    18,    52,   118,    53,     8,    20,    10,    11,
      44,    46,    30,   140,    47,    48,    49,    50,    51,     8,
     119,    10,    11,    52,    32,    53,   135,   142,    98,    97,
      88,    89,    90,    91,    92,    93,    88,    89,    90,    91,
      92,    93,   121,    88,    89,    90,    91,    92,    93,   129,
     108,    88,    89,    90,    91,    92,    93,    88,    89,    90,
      91,    92,    93
};

static const yytype_uint8 yycheck[] =
{
      45,    55,     3,     5,     5,     6,     2,    29,     9,    10,
      55,    13,    17,     0,     8,    47,    21,    18,    40,    22,
      16,    22,    23,    24,    22,    22,    16,    29,    20,    18,
      16,    76,    33,    65,    29,    30,    31,    69,    40,    27,
      28,    29,    30,    31,    98,    77,    29,    30,    31,    81,
      22,    19,    17,    98,    20,    22,    88,    89,    90,    91,
      92,    93,    22,    65,    22,    18,     9,    10,     3,     4,
       5,     6,    18,   127,   128,    18,    19,    16,    25,    22,
      23,    24,   127,   128,    16,    18,   140,    18,    22,   121,
      33,   123,    22,   125,   126,   140,     9,    10,    22,     9,
      10,     7,    25,    16,    25,    18,    25,    16,    18,    22,
      23,    24,    22,    23,    24,    19,     3,    19,     5,     6,
      33,     8,    19,    33,    11,    12,    13,    14,    15,    28,
      29,    30,    31,    20,    21,    22,     3,    16,     5,     6,
      16,     8,    25,    31,    11,    12,    13,    14,    15,    19,
      16,    35,    13,    20,    21,    22,     3,    16,     5,     6,
      40,     8,    27,   139,    11,    12,    13,    14,    15,     3,
      16,     5,     6,    20,     8,    22,    16,   141,    76,    73,
      26,    27,    28,    29,    30,    31,    26,    27,    28,    29,
      30,    31,    17,    26,    27,    28,    29,    30,    31,   121,
      19,    26,    27,    28,    29,    30,    31,    26,    27,    28,
      29,    30,    31
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    37,    38,     0,     8,    44,    46,    22,     3,     4,
       5,     6,    39,    40,    48,    70,    45,    47,    39,    41,
      44,    20,    22,    22,    52,    53,    42,    17,    21,    18,
      53,    16,     8,    49,    50,    51,    70,    71,    22,    19,
      17,    22,    22,    20,    50,    43,     8,    11,    12,    13,
      14,    15,    20,    22,    46,    54,    55,    67,    68,    70,
      71,    22,     9,    10,    16,    18,    22,    23,    24,    33,
      67,    72,    18,    18,    16,    16,    56,    25,    21,    55,
      16,    18,    22,    22,    70,    72,     7,    72,    26,    27,
      28,    29,    30,    31,    62,    66,    72,    66,    54,    72,
      19,    69,    72,    57,    59,    58,    60,    73,    19,    72,
      72,    72,    72,    72,    72,    16,    19,    19,    21,    16,
      19,    17,    16,    25,    16,    25,    19,    63,    64,    69,
      72,    72,    72,    55,    55,    16,    61,    65,    16,    35,
      64,    55,    65
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    36,    38,    37,    39,    39,    41,    42,    43,    40,
      44,    45,    44,    47,    46,    48,    48,    49,    49,    50,
      50,    51,    51,    52,    52,    53,    54,    54,    56,    55,
      57,    55,    58,    55,    55,    59,    55,    60,    61,    55,
      55,    55,    55,    62,    55,    55,    55,    63,    55,    64,
      65,    66,    55,    55,    67,    67,    68,    69,    69,    70,
      70,    70,    71,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    73,    72
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     3,     0,     2,     0,     0,     0,    11,
       0,     0,     3,     0,     7,     1,     1,     0,     1,     1,
       3,     2,     2,     1,     3,     1,     1,     2,     0,     4,
       0,     4,     0,     4,     1,     0,     6,     0,     0,     7,
       4,     2,     2,     0,     4,     7,    11,     0,     6,     0,
       0,     1,     2,     2,     4,     3,     1,     1,     3,     1,
       1,     1,     2,     3,     3,     3,     1,     1,     1,     2,
       1,     1,     1,     2,     3,     3,     3,     3,     0,     5
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 66 "parser.ypp" /* yacc.c:1646  */
    {
	handler.programStart();
  }
#line 1394 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 69 "parser.ypp" /* yacc.c:1646  */
    {
        handler.mainDefined();
    }
#line 1402 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 72 "parser.ypp" /* yacc.c:1646  */
    {}
#line 1408 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 73 "parser.ypp" /* yacc.c:1646  */
    {}
#line 1414 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 74 "parser.ypp" /* yacc.c:1646  */
    {
    handler.updateLastFunctionRetType((yyvsp[0]));
    }
#line 1422 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 76 "parser.ypp" /* yacc.c:1646  */
    {
    wasAlreadyDefined((yyvsp[0]));
    if ((yyvsp[0])->getName()=="main"){
        handler.defineMain();
    }
    }
#line 1433 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 81 "parser.ypp" /* yacc.c:1646  */
    {
      vector<string> formals_ids = ((FormalListClass*)(yyvsp[-2]))->getNames();
      if (std::find(formals_ids.begin(),formals_ids.end(),(yyvsp[-5])->getName())!=formals_ids.end()){
        errorDef(yylineno,(yyvsp[-5])->getName());
        exit(0);
      }
        handler.createAndInsertFunction((yyvsp[-7]),(yyvsp[-5]),(yyvsp[-2]));
        
    }
#line 1447 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 89 "parser.ypp" /* yacc.c:1646  */
    {
	handler.finishInsertFunction();
    table.removeScope();
}
#line 1456 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 93 "parser.ypp" /* yacc.c:1646  */
    {}
#line 1462 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 94 "parser.ypp" /* yacc.c:1646  */
    {
  vector<string> names = ((FormalListClass*)(yyvsp[0]))->getNames();
  table.insertGlobalEnum((yyvsp[0])->getName());
}
#line 1471 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 97 "parser.ypp" /* yacc.c:1646  */
    {}
#line 1477 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 98 "parser.ypp" /* yacc.c:1646  */
    {
	wasAlreadyDefined((yyvsp[0]));
}
#line 1485 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 100 "parser.ypp" /* yacc.c:1646  */
    {
    vector<string> enum_names = ((FormalListClass*)(yyvsp[-2]))->getNames();
    if (std::find(enum_names.begin(),enum_names.end(),(yyvsp[-5])->getName())!=enum_names.end()){
      errorDef(yylineno,(yyvsp[-5])->getName());
      exit(0);
    }
    (yyval) = handler.enumDeclaration((yyvsp[-5]),(yyvsp[-2]));
}
#line 1498 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 108 "parser.ypp" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1504 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 109 "parser.ypp" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1510 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 110 "parser.ypp" /* yacc.c:1646  */
    {(yyval) = new FormalListClass();}
#line 1516 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 111 "parser.ypp" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1522 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 112 "parser.ypp" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1528 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 113 "parser.ypp" /* yacc.c:1646  */
    {
  vector<string> vec1 = ((FormalListClass*)(yyvsp[-2]))->getNames();
  vector<string> vec2 = ((FormalListClass*)(yyvsp[0]))->getNames();
  string formal_id = vec1[0];
  if (std::find(vec2.begin(),vec2.end(),formal_id)!=vec2.end()){
    errorDef(yylineno,formal_id);
    exit(0);
  }
  (yyval) = handler.formalList((yyvsp[-2]),(yyvsp[0]));
  }
#line 1543 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 123 "parser.ypp" /* yacc.c:1646  */
    {
  wasAlreadyDefined((yyvsp[0]));
  (yyval)=new FormalListClass(Id((yyvsp[0])->getName(),(yyvsp[-1])->getType()));
}
#line 1552 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 127 "parser.ypp" /* yacc.c:1646  */
    {
  if(!table.exist((yyvsp[-1])->getName())){
    errorUndefEnum(yylineno,(yyvsp[-1])->getName());
    exit(0);
  }
  wasAlreadyDefined((yyvsp[0]));
  (yyval)=new FormalListClass(Id((yyvsp[0])->getName(),"enum "+(yyvsp[-1])->getName()));
}
#line 1565 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 135 "parser.ypp" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1571 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 136 "parser.ypp" /* yacc.c:1646  */
    {
    vector<string> vec1 = ((FormalListClass*)(yyvsp[-2]))->getNames();
    vector<string> vec2 = ((FormalListClass*)(yyvsp[0]))->getNames();
    string enumrator_id = vec2[0];
    if (table.exist(enumrator_id)){
      errorDef(yylineno,enumrator_id);
      exit(0);
    }
    if (std::find(vec1.begin(),vec1.end(),enumrator_id)!=vec1.end()){
      errorDef(yylineno,enumrator_id);
      exit(0);
    }
    (yyval) = handler.enumratorList((yyvsp[-2]),(yyvsp[0]));
}
#line 1590 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 150 "parser.ypp" /* yacc.c:1646  */
    {
	wasAlreadyDefined((yyvsp[0]));
	(yyval)=new FormalListClass(Id((yyvsp[0])->getName(),(yyvsp[0])->getType()));
}
#line 1599 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 154 "parser.ypp" /* yacc.c:1646  */
    {}
#line 1605 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 155 "parser.ypp" /* yacc.c:1646  */
    {}
#line 1611 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 156 "parser.ypp" /* yacc.c:1646  */
    {table.insertScope();}
#line 1617 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 156 "parser.ypp" /* yacc.c:1646  */
    {
    table.removeScope();
}
#line 1625 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 159 "parser.ypp" /* yacc.c:1646  */
    {
    wasAlreadyDefined((yyvsp[0]));
    insertToSymbolTable((yyvsp[-1]),(yyvsp[0]));
    }
#line 1634 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 162 "parser.ypp" /* yacc.c:1646  */
    {
}
#line 1641 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 164 "parser.ypp" /* yacc.c:1646  */
    {
  if (!table.exist((yyvsp[-1])->getName())){
    errorUndefEnum(yylineno,(yyvsp[-1])->getName());
    exit(0);
  }
    wasAlreadyDefined((yyvsp[0]));
    table.addScopeData(ScopeData((yyvsp[0])->getName(),table.getNextOffset(),"enum "+(yyvsp[-1])->getName()));}
#line 1653 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 171 "parser.ypp" /* yacc.c:1646  */
    {}
#line 1659 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 172 "parser.ypp" /* yacc.c:1646  */
    {
  ;}
#line 1666 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 174 "parser.ypp" /* yacc.c:1646  */
    {
	wasAlreadyDefined((yyvsp[0]));
}
#line 1674 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 176 "parser.ypp" /* yacc.c:1646  */
    {
  if((yyvsp[-1])->getType() == "ID"){
    notDefined((yyvsp[-1]));
  }
	typeCheck((yyvsp[-5]),(yyvsp[-1]));
  insertToSymbolTable((yyvsp[-5]),(yyvsp[-4]));
	}
#line 1686 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 183 "parser.ypp" /* yacc.c:1646  */
    {wasAlreadyDefined((yyvsp[0]));}
#line 1692 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 183 "parser.ypp" /* yacc.c:1646  */
    {
    if ((yyvsp[0])->getType()=="ID"){
      notDefined((yyvsp[0]));
    }
    enumTypeCheck((yyvsp[-4]),(yyvsp[-3]),(yyvsp[0]));
    table.addScopeData(ScopeData((yyvsp[-3])->getName(),table.getNextOffset(),"enum "+(yyvsp[-4])->getName()));
    }
#line 1704 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 189 "parser.ypp" /* yacc.c:1646  */
    {
}
#line 1711 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 191 "parser.ypp" /* yacc.c:1646  */
    {notDefinedVariable((yyvsp[-3])); typeCheck((yyvsp[-3]),(yyvsp[-1]));}
#line 1717 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 192 "parser.ypp" /* yacc.c:1646  */
    {}
#line 1723 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 193 "parser.ypp" /* yacc.c:1646  */
    {
    handler.returnStatement(NULL);
}
#line 1731 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 196 "parser.ypp" /* yacc.c:1646  */
    {
    handler.returnStatement((yyvsp[0]));
}
#line 1739 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 202 "parser.ypp" /* yacc.c:1646  */
    {
    while_count++;
    table.insertScope();
    }
#line 1748 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 205 "parser.ypp" /* yacc.c:1646  */
    {
        while_count--;
        table.removeScope();
}
#line 1757 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 209 "parser.ypp" /* yacc.c:1646  */
    {
  table.insertScope();}
#line 1764 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 211 "parser.ypp" /* yacc.c:1646  */
    {
  table.removeScope();
}
#line 1772 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 214 "parser.ypp" /* yacc.c:1646  */
    {isBool((yyvsp[0]));}
#line 1778 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 215 "parser.ypp" /* yacc.c:1646  */
    {
    if (while_count==0){
        errorUnexpectedBreak(yylineno);
        exit(0);
    }
}
#line 1789 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 221 "parser.ypp" /* yacc.c:1646  */
    {
    if(while_count==0){
        errorUnexpectedContinue(yylineno);
        exit(0);
    }
}
#line 1800 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 227 "parser.ypp" /* yacc.c:1646  */
    {
	CheckDefinedFunc((yyvsp[-3]));
  (yyval) = handler.functionCall((yyvsp[-3]),(yyvsp[-1]));
}
#line 1809 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 231 "parser.ypp" /* yacc.c:1646  */
    {
	CheckDefinedFunc((yyvsp[-2]));
  (yyval) = handler.functionCallNoParams((yyvsp[-2]));
}
#line 1818 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 235 "parser.ypp" /* yacc.c:1646  */
    {
}
#line 1825 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 237 "parser.ypp" /* yacc.c:1646  */
    {(yyval)=new ExpList(getActualType((yyvsp[0])));}
#line 1831 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 238 "parser.ypp" /* yacc.c:1646  */
    {(yyval)=new ExpList(getActualType((yyvsp[-2])));(yyval)->addTypes((yyvsp[0])->getTypes());}
#line 1837 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 239 "parser.ypp" /* yacc.c:1646  */
    {(yyval)=handler.typeInt((yyvsp[0]));}
#line 1843 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 240 "parser.ypp" /* yacc.c:1646  */
    {(yyval)=handler.typeByte((yyvsp[0]));}
#line 1849 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 241 "parser.ypp" /* yacc.c:1646  */
    {(yyval)=handler.typeBool((yyvsp[0]));}
#line 1855 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 242 "parser.ypp" /* yacc.c:1646  */
    {(yyval)=new Enum((yyvsp[0])->getName(),"ENUM");}
#line 1861 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 243 "parser.ypp" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]);}
#line 1867 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 244 "parser.ypp" /* yacc.c:1646  */
    {
    (yyval) = handler.expBinopH((yyvsp[-1]),(yyvsp[-2]),(yyvsp[0]));
}
#line 1875 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 247 "parser.ypp" /* yacc.c:1646  */
    {
    (yyval) = handler.expBinopL((yyvsp[-1]),(yyvsp[-2]),(yyvsp[0]));
}
#line 1883 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 250 "parser.ypp" /* yacc.c:1646  */
    {(yyval)=handler.expId((yyvsp[0]));}
#line 1889 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 251 "parser.ypp" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1895 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 252 "parser.ypp" /* yacc.c:1646  */
    {(yyval)=handler.expNum((yyvsp[0]));}
#line 1901 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 253 "parser.ypp" /* yacc.c:1646  */
    {
    if ((yyvsp[-1])->getVal()>255){
        errorByteTooLarge(yylineno,std::to_string((yyvsp[-1])->getVal()));
        exit(0);
    }
    (yyval)=new Byte((yyvsp[-1])->getVal(),"BYTE");
}
#line 1913 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 260 "parser.ypp" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1919 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 261 "parser.ypp" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1925 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 262 "parser.ypp" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1931 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 263 "parser.ypp" /* yacc.c:1646  */
    {
    isBool((yyvsp[0]));
    (yyval)=new Bool(!(((Bool*)(yyvsp[0]))->getValue()),"BOOL");
}
#line 1940 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 267 "parser.ypp" /* yacc.c:1646  */
    {
	isBool((yyvsp[-2]));
	isBool((yyvsp[0]));
	(yyval)=new Bool((yyvsp[-2])->getValue() && (yyvsp[0])->getValue(),"BOOL");
}
#line 1950 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 272 "parser.ypp" /* yacc.c:1646  */
    {
	isBool((yyvsp[-2]));
	isBool((yyvsp[0]));
	(yyval)=new Bool((yyvsp[-2])->getValue() || (yyvsp[0])->getValue(),"BOOL");
}
#line 1960 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 277 "parser.ypp" /* yacc.c:1646  */
    {
    (yyval) = handler.expRelop((yyvsp[-2]),(yyvsp[0]));
}
#line 1968 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 280 "parser.ypp" /* yacc.c:1646  */
    {
    (yyval) = handler.expReleq((yyvsp[-2]),(yyvsp[0]));
}
#line 1976 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 283 "parser.ypp" /* yacc.c:1646  */
    {
    if((yyvsp[0])->getType()!="INT"){
        errorMismatch(yylineno);
        exit(0);
    } }
#line 1986 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 287 "parser.ypp" /* yacc.c:1646  */
    {
      if (getActualType((yyvsp[0])).find("enum")==std::string::npos && getActualType((yyvsp[0]))!="ENUM"){
            errorMismatch(yylineno);
            exit(0);
        }
        (yyval)=(yyvsp[-3]);
}
#line 1998 "parser.tab.cpp" /* yacc.c:1646  */
    break;


#line 2002 "parser.tab.cpp" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 295 "parser.ypp" /* yacc.c:1906  */


int main()
{
	yyparse();
    handler.flushCode();
}

int yyerror(const char * message)
{
	output::errorSyn(yylineno);
	exit(0);
}


TypeContainer* binOpType(TypeContainer* lhs, TypeContainer* rhs) {
  string type_one = lhs->getType();
  string type_two = rhs->getType();
  if (type_one == "INT" || type_two == "INT"){
	  return new Int(lhs->getVal()+rhs->getVal(),"INT");
  }
  return new Int(lhs->getVal() + rhs->getVal(), "BYTE");
}

void typeCheck(TypeContainer* lhs,TypeContainer* rhs){
    string lhs_type = getActualType(lhs);
    string rhs_type = getActualType(rhs);

    if(lhs_type == "INT" && rhs_type =="BYTE") return;
    if (lhs_type.find("enum")!=std::string::npos){
      if (rhs_type=="ENUM"){
        lhs_type = lhs_type.substr(lhs_type.find(" ")+1);
        rhs_type = table.getParentEnumId(rhs->getName());
        if (lhs_type!=rhs_type){
          errorUndefEnumValue(yylineno,lhs->getName());
          exit(0);
        }
        else {
          return;
        }
      }
      else {
        errorUndefEnumValue(yylineno,lhs->getName());
        exit(0);
      }
    }
    if(lhs_type != rhs_type){
      errorMismatch(yylineno);
      exit(0);
	}
}

void isBool(TypeContainer* con){
    string type = getActualType(con);
		if (type != "BOOL"){
			errorMismatch(yylineno);
			exit(0);
		}
 }

void wasAlreadyDefined(TypeContainer* con){
	if( table.exist( con->getName() )){
		errorDef(yylineno, con->getName());
		exit(0);
	}
}


void notDefinedVariable(TypeContainer* con){
	 if( table.exist( con->getName() ) == false || table.getDataCopy(con->getName()).isEnum()){
      errorUndef(yylineno, con->getName());
      exit(0);
	}
    if (table.getDataCopy(con->getName()).isFunction()){
        errorUndef(yylineno, con->getName());
        exit(0); 
    }
}

void notDefined(TypeContainer* con){
	 if( table.exist( con->getName() ) == false || table.getDataCopy(con->getName()).isEnum()){
      errorUndef(yylineno, con->getName());
      exit(0);
	}
}

void CheckDefinedFunc(TypeContainer* con){
	 string arrow = "->";
     bool id_exists = table.exist(con->getName());
     if (!id_exists){
         errorUndefFunc(yylineno,con->getName());
         exit(0);
     }
     ScopeData copy = table.getDataCopy(con->getName());
     string type = copy.getTypeCopy();
     if (type.find(arrow)==std::string::npos){
         errorUndefFunc(yylineno,con->getName());
         exit(0);
     }
}


string getFunctionRetType(TypeContainer* func){
    string type = func->getType();
    if (type=="ID"){
		notDefined(func);
        type = table.getDataCopy(func->getName()).getTypeCopy();
        std::size_t location = type.find("->");
        if (location == std::string::npos){
            return type;
        }
        type = type.substr(location+2);
    }
    return type;
}

void insertToSymbolTable(TypeContainer* type,TypeContainer* id){
	ScopeData inserted_element = ScopeData(id->getName(),table.getNextOffset(),type->getType());
	table.addScopeData(inserted_element);
}

/* this function returns the "returned type" of a function */
string getActualType(TypeContainer* some_data){
    string type = some_data->getType();
    if (type=="ID"){
		notDefined(some_data);
        type = table.getDataCopy(some_data->getName()).getTypeCopy();
        // std::size_t location = type.find("->");
        // if (location == std::string::npos){
        //     return type;
        // }
        // type = type.substr(location+2);
    }
    return type;
}

void numCheck(TypeContainer* data){
    string type = getActualType(data);
    if (type!="INT" && type!="BYTE"){
        errorMismatch(yylineno);
        exit(0);
    }
}

string getRetType(ScopeData some_func){
    string type = some_func.getTypeCopy();
    std::size_t location = type.find("->");
    type = type.substr(location+2);
    return type;
}

/* gets function name and returns the type (type1,type2,type3) */
string getFunctionParametersString(string id){
  ScopeData func_data = table.getDataCopy(id);
  string type = func_data.getTypeCopy();
  std::size_t location = type.find("->");
  type = type.substr(0,location);
  return type;
}

string getFunctionRetTypeString(string id){
  ScopeData func_data = table.getDataCopy(id);
  string RetType = func_data.getTypeCopy();
  return getRetType(RetType);
}


vector<string> functionTypeToVector(string function_type) {
  function_type = function_type.substr(0, function_type.find("->"));
  function_type = function_type.substr(1, function_type.length() - 1);
  std::string s = function_type;
  std::string delimiter = ",";
  vector<string> output_vector;
  size_t pos = 0;
  std::string token;
  while ((pos = s.find(delimiter)) != std::string::npos) {
    token = s.substr(0, pos);
    output_vector.push_back(token);
    s.erase(0, pos + delimiter.length());
  }
  return output_vector;
}

string getFunctionFullType(string id){
    return table.getDataCopy(id).getTypeCopy();
}

vector<string> getFunctionParameters(string id){
    string type = getFunctionFullType(id);
    return functionTypeToVector(type);
}

void enumTypeCheck(TypeContainer* enumtype,TypeContainer* future_id,TypeContainer* exp){
    string checked_enum = enumtype->getName();
    string exp_type = getActualType(exp);
    size_t pos = exp_type.find(" ");
    if (pos==string::npos){
      errorUndefEnum(yylineno,enumtype->getName());
      exit(0);
    }
    if (exp_type.substr(pos+1)!=checked_enum){
      errorUndefEnumValue(yylineno,future_id->getName());
      exit(0);
    }
}


vector<ScopeData> createFuncArgsVec(TypeContainer* formals){
    vector<Id> id_vec = ((FormalListClass*)formals)->getIds();
    vector<ScopeData> output_vec;
    int i=-1;
    for (Id id : id_vec){
        output_vec.push_back(ScopeData(id.getName(),i,id.getType()));
        i--;
    }
    return output_vec;
}

vector<string> parseFuncParams(string type){
  vector<string> params;
  string param_string = type.substr(1,type.size()-2);
  int count = 0;
  for(char c : param_string){
    if(c == ',') count++;
  }
  int param_num = count;//(int)std::count(param_string.begin(), param_string.end(), ',');
  int pos = 0;
  for(int i = 0; i < param_num; i++){
    pos = (int)type.find(",");
    params.push_back(param_string.substr(0,pos-1));
    param_string = param_string.substr(pos);
  }
  params.push_back(param_string);
  return params;
}

string StringFromVec(vector<string> params){
  if(params.size() == 0) return "()";
  string temp = "(";
  for(string param : params){
    temp += param + ',';
  }
  return temp.substr(0,temp.size()-1)+')';
}

string getRetType(string type){
  int pos = (int)type.find("->");
  if(pos == std::string::npos){
    return "";
  }
  return type.substr(pos+2,type.size()-2);
}
