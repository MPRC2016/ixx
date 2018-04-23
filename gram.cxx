/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 29 "gram.y" /* yacc.c:339  */


#include "expr.h"
#include "scanner.h"

#if defined(YYDEBUG)
#include <stdio.h>
#endif

#ifdef sun
/* workaround for Sun bug */
#include <malloc.h>
#endif

/*
 * Global data needed for communication between a yacc parser and
 * the rest of the program.
 */

Scanner* yyparse_scanner;
ExprKit* yyparse_exprkit;
Expr* yyparse_root;

/*
 * It would be better if yylex and yyerror were inline functions,
 * but some versions of yacc will generate prototypes or other
 * potentially confusing information unless they are macros.
 *
 * On the other hand, IBM AIXV3 requires that they be functions ...
 */

#if defined(AIXV3)
extern "C" {
    int yylex() { return yyparse_scanner->get_token(); }
    void yyerror(char* msg) { yyparse_scanner->error(msg); }
}
#else
#define yylex() (yyparse_scanner->get_token())
#define yyerror(msg) (yyparse_scanner->error(msg))
#endif

inline Expr* root(ExprList* list) {
    return yyparse_exprkit->root(list);
}

static ExprList* definition_list(Expr* def) {
    ExprList* s = yyparse_exprkit->exprlist();
    s->append(def);
    return s;
}

static ExprList* append(ExprList* list, Expr* element) {
    ExprList* e = list;
    if (e == nil) {
	e = yyparse_exprkit->exprlist();
    }
    e->append(element);
    return e;
}

static ExprList* concat(ExprList* list1, ExprList* list2) {
    ExprList* e = list1;
    if (e == nil) {
	e = list2;
    } else if (list2 != nil) {
	for (ListItr(ExprList) i(*list2); i.more(); i.next()) {
	    e->append(i.cur());
	}
    }
    return e;
}

static CaseList* case_append(CaseList* list, CaseElement* element) {
    CaseList* e = list;
    if (e == nil) {
	e = yyparse_exprkit->caselist();
    }
    e->append(element);
    return e;
}

inline Identifier* ident(UniqueString* s) {
    return yyparse_exprkit->ident(s);
}

inline Expr* interface(
    UniqueString* s, ExprList* supertypes, ExprList* defs
) {
    return yyparse_exprkit->interface(ident(s), supertypes, defs);
}

inline Expr* forward_interface(UniqueString* s) {
    return yyparse_exprkit->forward_interface(ident(s));
}

inline Expr* module(UniqueString* s, ExprList* defs) {
    return yyparse_exprkit->module(ident(s), defs);
}

inline Expr* srcpos(SourcePosition* p) {
    return yyparse_exprkit->position(p);
}

inline Expr* global(UniqueString* s) {
    return yyparse_exprkit->scoped(nil, s);
}

inline Expr* scoped(Expr* scope, UniqueString* s) {
    return yyparse_exprkit->scoped(scope, s);
}

inline Expr* const_dcl(Identifier* ident, Expr* type, Expr* expr) {
    return yyparse_exprkit->constant(ident, type, expr);
}

inline Expr* boolcon(Boolean value) {
    return yyparse_exprkit->boolean_literal(value);
}

inline Expr* intcon(long value) {
    return yyparse_exprkit->integer_literal(value);
}

inline Expr* charcon(long value) {
    return yyparse_exprkit->char_literal(value);
}

inline Expr* floatcon(double value) {
    return yyparse_exprkit->float_literal(value);
}

inline Expr* stringcon(String* value) {
    return yyparse_exprkit->string_literal(value);
}

inline Expr* unary(Opcode op, Expr* expr) {
    return yyparse_exprkit->unary(op, expr);
}

inline Expr* binary(Opcode op, Expr* left, Expr* right) {
    return yyparse_exprkit->binary(op, left, right);
}

inline Expr* typedef_decl(Expr* type, ExprList* declarator_list) {
    return yyparse_exprkit->typename_(type, declarator_list);
}

inline Expr* unsigned_type(Expr* type) {
    return yyparse_exprkit->unsigned_type(type);
}

inline Expr* long_type() {
    return yyparse_exprkit->ident(new String("long"));
}

inline Expr* ulong_type() {
    return yyparse_exprkit->unsigned_type(long_type());
}

inline Expr* long_long_type() {
    return yyparse_exprkit->ident(new String("longlong"));
}

inline Expr* ulong_long_type() {
    return yyparse_exprkit->unsigned_type(long_long_type());
}

static ExprList* declarator_list(Expr* declarator) {
    ExprList* s = yyparse_exprkit->exprlist();
    s->append(declarator);
    return s;
}

inline Expr* declarator(Identifier* ident, ExprList* opt_subscript_list) {
    return yyparse_exprkit->declarator(ident, opt_subscript_list);
}

inline Expr* struct_type(Identifier* ident, ExprList* member_list) {
    return yyparse_exprkit->struct_decl(ident, member_list);
}

inline Expr* struct_member(Expr* type, ExprList* declarator_list) {
    return yyparse_exprkit->struct_member(type, declarator_list);
}

inline Expr* union_type(
    Identifier* ident, Expr* type, CaseList* case_list
) {
    return yyparse_exprkit->union_decl(ident, type, case_list);
}

static CaseList* case_list(CaseElement* case_stmt) {
    CaseList* s = yyparse_exprkit->caselist();
    s->append(case_stmt);
    return s;
}

inline CaseElement* case_element(
    ExprList* case_label_list, UnionMember* element
) {
    return yyparse_exprkit->case_element(case_label_list, element);
}

static ExprList* case_label_list(Expr* case_label) {
    ExprList* s = yyparse_exprkit->exprlist();
    s->append(case_label);
    return s;
}

inline Expr* case_label(Expr* value) {
    return yyparse_exprkit->case_label(value);
}

inline Expr* default_label() {
    return yyparse_exprkit->default_label();
}

inline UnionMember* union_member(Expr* type, Expr* declarator) {
    return yyparse_exprkit->union_member(type, declarator);
}

inline Expr* enum_type(Identifier* ident, ExprList* name_list) {
    return yyparse_exprkit->enum_decl(ident, name_list);
}

inline Expr* enumerator(UniqueString* s) {
    return yyparse_exprkit->enumerator(ident(s));
}

inline Expr* sequence_type(Expr* type, Expr* opt_length) {
    return yyparse_exprkit->sequence_decl(type, opt_length);
}

inline Expr* string_type(Expr* opt_length) {
    return yyparse_exprkit->string_decl(opt_length);
}

inline ExprList* attr_dcl(
    Boolean opt_readonly, Expr* type, ExprList* declarator_list
) {
    return yyparse_exprkit->attr_decl(opt_readonly, type, declarator_list);
}

inline Expr* except_dcl(Identifier* ident, ExprList* member_list) {
    return yyparse_exprkit->except_decl(ident, member_list);
}

inline Expr* op(
    ExprList* attr, Expr* type, UniqueString* s, ExprList* params,
    ExprList* raises, ExprList* context
) {
    return yyparse_exprkit->operation(
	ident(s), type, params, raises, attr, context
    );
}

static ExprList* param_list(Expr* param) {
    ExprList* s = yyparse_exprkit->exprlist();
    s->append(param);
    return s;
}

inline Expr* param(
    ParamTag attribute, Expr* type, Identifier* ident, ExprList* subscripts
) {
    return yyparse_exprkit->parameter(attribute, type, ident, subscripts);
}

static ExprList* string_list(Expr* str) {
    ExprList* s = yyparse_exprkit->exprlist();
    s->append(str);
    return s;
}


#line 342 "gram.tab.c" /* yacc.c:339  */

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
   by #include "gram.tab.h".  */
#ifndef YY_YY_GRAM_TAB_H_INCLUDED
# define YY_YY_GRAM_TAB_H_INCLUDED
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
    ATTRIBUTE = 258,
    CASE = 259,
    CONST = 260,
    CONTEXT = 261,
    DEFAULT = 262,
    ENUM = 263,
    EXCEPTION = 264,
    FALSE = 265,
    IN = 266,
    INOUT = 267,
    INTERFACE = 268,
    LONG = 269,
    MODULE = 270,
    ONEWAY = 271,
    OPERATOR = 272,
    OUT = 273,
    RAISES = 274,
    READONLY = 275,
    SEQUENCE = 276,
    STRING_TOKEN = 277,
    STRUCT = 278,
    SWITCH = 279,
    TRUE = 280,
    TYPEDEF = 281,
    UNION = 282,
    UNSIGNED = 283,
    ASM = 284,
    AUTO = 285,
    BREAK = 286,
    CLASS = 287,
    CONTINUE = 288,
    DELETE = 289,
    DO = 290,
    ELSE = 291,
    EXTERN = 292,
    FOR = 293,
    FRIEND = 294,
    GOTO = 295,
    IF = 296,
    INLINE = 297,
    NEW = 298,
    PRIVATE = 299,
    PROTECTED = 300,
    PUBLIC = 301,
    REGISTER = 302,
    RETURN = 303,
    SIGNED = 304,
    SIZEOF = 305,
    STATIC = 306,
    TEMPLATE = 307,
    THIS = 308,
    VIRTUAL = 309,
    VOLATILE = 310,
    WHILE = 311,
    INTCON = 312,
    CHARCON = 313,
    FLOATCON = 314,
    IDENT = 315,
    STRING = 316,
    SCOPE = 317,
    LSHIFT = 318,
    RSHIFT = 319,
    SRCPOS = 320,
    ELLIPSES = 321,
    INCR = 322,
    DECR = 323,
    ARROW = 324,
    LE = 325,
    GE = 326,
    EQ = 327,
    NE = 328,
    AND = 329,
    OR = 330,
    lowPrec = 331,
    UNARY = 332,
    CAST = 333,
    highPrec = 334
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 326 "gram.y" /* yacc.c:355  */

    Boolean boolean_;
    long long_;
    double double_;
    class String* string_;
    class UniqueString* ustring_;
    class Identifier* identifier_;
    class Expr* expr_;
    class ExprList* exprlist_;
    class CaseList* caselist_;
    class CaseElement* case_;
    class UnionMember* umember_;
    class SourcePosition* position_;
    /* ParamTag */ unsigned long param_;
    /* Opcode */ unsigned long opcode_;

#line 479 "gram.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_GRAM_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 496 "gram.tab.c" /* yacc.c:358  */

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
#define YYFINAL  42
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   378

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  104
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  122
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  219

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   334

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    84,     2,     2,     2,    83,    92,     2,
      76,    97,    81,    79,    86,    80,    78,    82,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    89,   101,
      93,    87,    94,    88,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    77,     2,   103,    91,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    96,    90,   102,    85,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    95,    98,    99,   100
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   402,   402,   406,   407,   411,   412,   413,   414,   416,
     417,   419,   423,   424,   428,   429,   433,   434,   435,   439,
     440,   441,   445,   446,   447,   448,   452,   456,   457,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,   476,   480,   481,
     482,   483,   487,   488,   492,   493,   494,   495,   496,   497,
     498,   502,   503,   507,   508,   509,   513,   514,   518,   522,
     523,   527,   531,   532,   536,   540,   546,   547,   548,   549,
     550,   551,   552,   556,   557,   561,   565,   566,   570,   571,
     575,   579,   583,   584,   588,   593,   594,   598,   602,   603,
     607,   612,   613,   617,   621,   627,   628,   632,   633,   637,
     638,   646,   648,   652,   653,   654,   655,   659,   660,   664,
     665,   669,   670
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ATTRIBUTE", "CASE", "CONST", "CONTEXT",
  "DEFAULT", "ENUM", "EXCEPTION", "FALSE", "IN", "INOUT", "INTERFACE",
  "LONG", "MODULE", "ONEWAY", "OPERATOR", "OUT", "RAISES", "READONLY",
  "SEQUENCE", "STRING_TOKEN", "STRUCT", "SWITCH", "TRUE", "TYPEDEF",
  "UNION", "UNSIGNED", "ASM", "AUTO", "BREAK", "CLASS", "CONTINUE",
  "DELETE", "DO", "ELSE", "EXTERN", "FOR", "FRIEND", "GOTO", "IF",
  "INLINE", "NEW", "PRIVATE", "PROTECTED", "PUBLIC", "REGISTER", "RETURN",
  "SIGNED", "SIZEOF", "STATIC", "TEMPLATE", "THIS", "VIRTUAL", "VOLATILE",
  "WHILE", "INTCON", "CHARCON", "FLOATCON", "IDENT", "STRING", "SCOPE",
  "LSHIFT", "RSHIFT", "SRCPOS", "ELLIPSES", "INCR", "DECR", "ARROW", "LE",
  "GE", "EQ", "NE", "AND", "OR", "'('", "'['", "'.'", "'+'", "'-'", "'*'",
  "'/'", "'%'", "'!'", "'~'", "','", "'='", "'?'", "':'", "'|'", "'^'",
  "'&'", "'<'", "'>'", "lowPrec", "'{'", "')'", "UNARY", "CAST",
  "highPrec", "';'", "'}'", "']'", "$accept", "start", "definition_list",
  "definition", "opt_inheritance", "name_list", "name", "export_list",
  "export", "const_dcl", "expr", "type_dcl", "type", "simple_type",
  "template_type", "constr_type", "declarator_list", "declarator",
  "opt_subscript_list", "struct_type", "member_list", "member",
  "union_type", "switch_type", "case_list", "case", "case_label_list",
  "case_label", "element", "enum_type", "enum_list", "sequence_type",
  "opt_sequence_length", "string_type", "opt_string_length", "attr_dcl",
  "opt_readonly", "except_dcl", "op_dcl", "opt_op_attr", "opt_params",
  "params", "param", "param_attribute", "opt_raises", "opt_context",
  "string_list", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,    40,    91,    46,    43,
      45,    42,    47,    37,    33,   126,    44,    61,    63,    58,
     124,    94,    38,    60,    62,   331,   123,    41,   332,   333,
     334,    59,   125,    93
};
# endif

#define YYPACT_NINF -98

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-98)))

#define YYTABLE_NINF -108

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     177,    50,   -34,   -31,   -14,     9,    23,   236,    33,   -98,
      24,   177,   -98,   -26,    -7,   -98,   -98,   -98,    10,    84,
      12,    20,     6,   -98,    43,    60,    64,   -98,   -98,   -98,
      29,    36,   -36,    40,    41,    71,   -98,   -98,   -98,   -98,
     -98,   114,   -98,   -98,   -98,   -98,   -98,   -98,    50,   158,
     -98,   125,    60,   -98,    83,    61,    90,   -98,   -30,   -98,
      55,   177,   -98,   -98,    66,   -98,    79,    72,   -98,   -98,
     -98,   -98,   -98,   -98,   158,   158,   158,   158,    60,   212,
     -98,   -98,   158,   -98,   -58,   107,    73,    60,   -98,    91,
     119,    80,    71,    17,   158,    76,   191,   -98,   -98,   -98,
     158,   158,   158,   158,   158,   158,   158,   158,   158,   158,
     -98,   251,   120,   -98,   -98,    71,   -98,   -30,    47,    86,
     -98,   158,   -98,   174,    35,    60,    92,   -98,   251,   -98,
     -98,   186,   186,   -22,   -22,   -98,   -98,   -98,   272,   286,
     148,   -98,   -43,    60,   -98,   -98,    93,   -98,    96,    97,
      98,   188,   100,   101,    50,   -98,    81,   -98,   193,    60,
     109,   -98,   -98,   -98,   -98,   -98,    50,   -98,   -98,   150,
     -98,   -98,    15,    71,   132,   158,   124,     7,   -98,   218,
     -98,    66,     5,   237,   -98,   -98,   -98,    71,   -98,   113,
     -98,   -98,   -98,   126,   138,   -98,    50,   -98,   -98,   -98,
     214,   108,   175,   160,   241,   -98,   -98,   -30,   172,   -98,
      80,   -35,   190,   -98,   -98,     4,   192,   -98,   -98
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,    11,
       0,     2,     3,     0,     0,    49,    50,    51,     0,    56,
       0,    98,     0,    16,     0,    54,     0,    60,    61,    62,
       0,     0,    12,     0,     0,     0,    52,    53,    63,    64,
      65,     0,     1,     4,     6,     5,     7,    58,     0,     0,
      97,    57,    55,    17,     0,     0,     0,    72,     0,     9,
       0,     0,    72,    69,    48,    66,     0,    95,    28,    29,
      30,    31,    32,    33,     0,     0,     0,     0,    27,     0,
      59,    18,     0,    92,     0,     0,    13,    14,    19,     0,
       0,    68,     0,     0,     0,     0,     0,    34,    35,    46,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      99,    26,     0,    91,   103,     0,    73,     0,   105,     0,
      71,     0,    67,    78,     0,    76,     0,    77,    96,    94,
      47,    41,    42,    36,    37,    38,    39,    40,    44,    45,
      43,    93,     0,    15,   106,   102,     0,    20,     0,     0,
       0,     0,     0,     0,     0,    10,     0,    81,    79,    80,
       0,    74,     8,    23,    22,    21,     0,    24,    25,     0,
      70,    82,     0,     0,     0,     0,     0,     0,    83,     0,
      86,   100,   113,     0,    89,    75,    84,     0,    87,     0,
     114,   116,   115,     0,   108,   109,     0,    88,    90,    85,
     117,   113,   112,     0,   119,   110,    69,     0,     0,   104,
     111,     0,     0,   118,   121,     0,     0,   120,   122
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -98,   -98,   195,     2,   -98,    42,    -1,   -98,   -98,   134,
     -67,   142,    -2,     0,   -98,   -98,   -97,   -80,    56,    -4,
     199,   -98,    -3,   -98,   -98,   102,   -98,   105,   -98,    -5,
     -98,   -98,   -98,   -98,   -98,   -98,   -98,   159,   -98,   -98,
     -98,   -98,    85,   -98,   -98,   -98,   -98
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    10,    11,    12,    60,    86,    78,   118,   147,    13,
      79,    14,   115,    36,    27,    37,    64,    65,    91,    15,
      85,   116,    16,   126,   177,   178,   179,   180,   189,    17,
      84,    28,    95,    29,    50,   150,   151,    18,   153,   154,
     193,   194,   195,   196,   204,   209,   215
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      25,    26,    40,    38,    39,    35,    25,    96,    97,    98,
      99,   175,   122,    43,   176,   111,   190,   191,   142,   175,
      51,    52,   176,   192,    42,     2,    30,   128,   112,    31,
      23,   123,    24,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,    92,   113,   124,    32,    25,    67,   158,
    -101,   117,     1,    58,   156,     2,     3,    87,   161,   104,
     105,   106,   213,   144,    19,    59,    23,   145,    24,    33,
       6,    20,    21,     7,     8,    44,   181,    23,    22,    24,
      40,    38,    39,    34,    25,    40,    38,    39,   127,    25,
     216,    43,   125,    41,    45,    23,     1,    24,    47,     2,
       3,   217,  -107,    53,     4,    48,     5,   198,   183,   185,
      23,    46,    24,    49,     6,     2,   143,     7,     8,   190,
     191,    19,    54,   159,    55,    56,   192,     2,    20,    21,
       6,    63,    57,    19,     8,    22,    61,    62,    66,    80,
      20,    21,     6,    81,   100,   101,     8,    22,    82,   146,
      83,    88,    92,    25,   169,    93,     9,   121,    94,   117,
     102,   103,   104,   105,   106,    25,   173,    23,    68,    24,
     129,   107,   108,   109,    40,    38,    39,   187,    25,    23,
     141,    24,     1,    69,   170,     2,     3,   155,   157,   160,
       4,   166,     5,   119,   162,    25,   202,   163,   164,   165,
       6,   167,   168,     7,     8,   172,    87,   171,   182,   114,
     174,   100,   101,   184,   199,    70,    71,    72,    23,    73,
      24,   120,   175,   200,   201,   176,     2,   102,   103,   104,
     105,   106,    19,   203,    74,   206,   207,    75,    76,    20,
      21,     6,     9,    77,     2,     8,    22,   208,   212,   211,
      19,   214,   148,   218,   100,   101,    89,    20,    21,     6,
     149,    90,   210,     8,    22,   102,   103,   104,   105,   106,
     102,   103,   104,   105,   106,   100,   101,   152,    23,   186,
      24,   107,   108,   109,   188,     0,   205,     0,   130,     0,
       0,   102,   103,   104,   105,   106,    23,     0,    24,     0,
     100,   101,   107,   108,   109,     0,   110,     0,     0,     0,
       0,     0,     0,     0,   100,   101,   102,   103,   104,   105,
     106,     0,     0,     0,     0,     0,   197,   107,   108,   109,
     102,   103,   104,   105,   106,   100,   101,     0,     0,     0,
       0,   107,   108,   109,     0,     0,     0,     0,     0,   100,
     101,   102,   103,   104,   105,   106,     0,     0,     0,     0,
       0,     0,     0,   108,   109,   102,   103,   104,   105,   106,
       0,     0,     0,     0,     0,     0,     0,     0,   109
};

static const yytype_int16 yycheck[] =
{
       1,     1,     7,     7,     7,     7,     7,    74,    75,    76,
      77,     4,    92,    11,     7,    82,    11,    12,   115,     4,
      14,    22,     7,    18,     0,     8,    60,    94,    86,    60,
      60,    14,    62,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,    86,   102,    28,    60,    48,    48,    14,
       3,    86,     5,    89,   121,     8,     9,    58,   101,    81,
      82,    83,    97,    16,    14,   101,    60,    20,    62,    60,
      23,    21,    22,    26,    27,   101,   173,    60,    28,    62,
      85,    85,    85,    60,    85,    90,    90,    90,    93,    90,
      86,    89,    93,    60,   101,    60,     5,    62,    14,     8,
       9,    97,    97,    60,    13,    93,    15,   187,   175,   102,
      60,   101,    62,    93,    23,     8,   117,    26,    27,    11,
      12,    14,    62,   124,    60,    96,    18,     8,    21,    22,
      23,    60,    96,    14,    27,    28,    96,    96,    24,    14,
      21,    22,    23,    60,    63,    64,    27,    28,    87,   102,
      60,    96,    86,   154,   154,    76,    65,    77,    86,    86,
      79,    80,    81,    82,    83,   166,   166,    60,    10,    62,
      94,    90,    91,    92,   179,   179,   179,   179,   179,    60,
      60,    62,     5,    25,   103,     8,     9,   101,    14,    97,
      13,     3,    15,   102,   101,   196,   196,   101,   101,   101,
      23,   101,   101,    26,    27,    96,   207,    14,    76,   102,
      60,    63,    64,    89,   101,    57,    58,    59,    60,    61,
      62,   102,     4,    97,    86,     7,     8,    79,    80,    81,
      82,    83,    14,    19,    76,    60,    76,    79,    80,    21,
      22,    23,    65,    85,     8,    27,    28,     6,    76,   207,
      14,    61,   118,    61,    63,    64,    61,    21,    22,    23,
     118,    62,   206,    27,    28,    79,    80,    81,    82,    83,
      79,    80,    81,    82,    83,    63,    64,   118,    60,   177,
      62,    90,    91,    92,   179,    -1,   201,    -1,    97,    -1,
      -1,    79,    80,    81,    82,    83,    60,    -1,    62,    -1,
      63,    64,    90,    91,    92,    -1,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    64,    79,    80,    81,    82,
      83,    -1,    -1,    -1,    -1,    -1,    89,    90,    91,    92,
      79,    80,    81,    82,    83,    63,    64,    -1,    -1,    -1,
      -1,    90,    91,    92,    -1,    -1,    -1,    -1,    -1,    63,
      64,    79,    80,    81,    82,    83,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    91,    92,    79,    80,    81,    82,    83,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,     8,     9,    13,    15,    23,    26,    27,    65,
     105,   106,   107,   113,   115,   123,   126,   133,   141,    14,
      21,    22,    28,    60,    62,   110,   117,   118,   135,   137,
      60,    60,    60,    60,    60,   116,   117,   119,   123,   126,
     133,    60,     0,   107,   101,   101,   101,    14,    93,    93,
     138,    14,   110,    60,    62,    60,    96,    96,    89,   101,
     108,    96,    96,    60,   120,   121,    24,   117,    10,    25,
      57,    58,    59,    61,    76,    79,    80,    85,   110,   114,
      14,    60,    87,    60,   134,   124,   109,   110,    96,   106,
     124,   122,    86,    76,    86,   136,   114,   114,   114,   114,
      63,    64,    79,    80,    81,    82,    83,    90,    91,    92,
      94,   114,    86,   102,   102,   116,   125,    86,   111,   102,
     102,    77,   121,    14,    28,   110,   127,   133,   114,    94,
      97,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,    60,   120,   110,    16,    20,   102,   112,   113,   115,
     139,   140,   141,   142,   143,   101,   114,    14,    14,   110,
      97,   101,   101,   101,   101,   101,     3,   101,   101,   117,
     103,    14,    96,   117,    60,     4,     7,   128,   129,   130,
     131,   120,    76,   114,    89,   102,   129,   116,   131,   132,
      11,    12,    18,   144,   145,   146,   147,    89,   121,   101,
      97,    86,   117,    19,   148,   146,    60,    76,     6,   149,
     122,   109,    76,    97,    61,   150,    86,    97,    61
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   104,   105,   106,   106,   107,   107,   107,   107,   107,
     107,   107,   108,   108,   109,   109,   110,   110,   110,   111,
     111,   111,   112,   112,   112,   112,   113,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   115,   115,
     115,   115,   116,   116,   117,   117,   117,   117,   117,   117,
     117,   118,   118,   119,   119,   119,   120,   120,   121,   122,
     122,   123,   124,   124,   125,   126,   127,   127,   127,   127,
     127,   127,   127,   128,   128,   129,   130,   130,   131,   131,
     132,   133,   134,   134,   135,   136,   136,   137,   138,   138,
     139,   140,   140,   141,   142,   143,   143,   144,   144,   145,
     145,   146,   146,   147,   147,   147,   147,   148,   148,   149,
     149,   150,   150
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     2,     2,     7,     3,
       6,     1,     0,     2,     1,     3,     1,     2,     3,     0,
       2,     3,     2,     2,     2,     2,     5,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     3,     3,     1,
       1,     1,     1,     1,     1,     2,     1,     2,     2,     3,
       1,     1,     1,     1,     1,     1,     1,     3,     2,     0,
       4,     5,     0,     2,     3,     9,     1,     1,     1,     2,
       2,     2,     3,     1,     2,     3,     1,     2,     3,     2,
       2,     5,     1,     3,     5,     0,     2,     2,     0,     3,
       4,     0,     1,     5,     8,     0,     1,     0,     1,     1,
       3,     4,     2,     0,     1,     1,     1,     0,     4,     0,
       4,     1,     3
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
#line 402 "gram.y" /* yacc.c:1646  */
    { yyparse_root = root((yyvsp[0].exprlist_)); }
#line 1782 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 406 "gram.y" /* yacc.c:1646  */
    { (yyval.exprlist_) = definition_list((yyvsp[0].expr_)); }
#line 1788 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 407 "gram.y" /* yacc.c:1646  */
    { (yyval.exprlist_) = append((yyvsp[-1].exprlist_), (yyvsp[0].expr_)); }
#line 1794 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 411 "gram.y" /* yacc.c:1646  */
    { (yyval.expr_) = (yyvsp[-1].expr_); }
#line 1800 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 412 "gram.y" /* yacc.c:1646  */
    { (yyval.expr_) = (yyvsp[-1].expr_); }
#line 1806 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 413 "gram.y" /* yacc.c:1646  */
    { (yyval.expr_) = (yyvsp[-1].expr_); }
#line 1812 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 415 "gram.y" /* yacc.c:1646  */
    { (yyval.expr_) = interface((yyvsp[-5].ustring_), (yyvsp[-4].exprlist_), (yyvsp[-2].exprlist_)); }
#line 1818 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 416 "gram.y" /* yacc.c:1646  */
    { (yyval.expr_) = forward_interface((yyvsp[-1].ustring_)); }
#line 1824 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 418 "gram.y" /* yacc.c:1646  */
    { (yyval.expr_) = module((yyvsp[-4].ustring_), (yyvsp[-2].exprlist_)); }
#line 1830 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 419 "gram.y" /* yacc.c:1646  */
    { (yyval.expr_) = srcpos((yyvsp[0].position_)); }
#line 1836 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 423 "gram.y" /* yacc.c:1646  */
    { (yyval.exprlist_) = nil; }
#line 1842 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 424 "gram.y" /* yacc.c:1646  */
    { (yyval.exprlist_) = (yyvsp[0].exprlist_); }
#line 1848 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 428 "gram.y" /* yacc.c:1646  */
    { (yyval.exprlist_) = append(nil, (yyvsp[0].expr_)); }
#line 1854 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 429 "gram.y" /* yacc.c:1646  */
    { (yyval.exprlist_) = append((yyvsp[-2].exprlist_), (yyvsp[0].expr_)); }
#line 1860 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 433 "gram.y" /* yacc.c:1646  */
    { (yyval.expr_) = ident((yyvsp[0].ustring_)); }
#line 1866 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 434 "gram.y" /* yacc.c:1646  */
    { (yyval.expr_) = global((yyvsp[0].ustring_)); }
#line 1872 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 435 "gram.y" /* yacc.c:1646  */
    { (yyval.expr_) = scoped((yyvsp[-2].expr_), (yyvsp[0].ustring_)); }
#line 1878 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 439 "gram.y" /* yacc.c:1646  */
    { (yyval.exprlist_) = nil; }
#line 1884 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 440 "gram.y" /* yacc.c:1646  */
    { (yyval.exprlist_) = append((yyvsp[-1].exprlist_), (yyvsp[0].expr_)); }
#line 1890 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 441 "gram.y" /* yacc.c:1646  */
    { (yyval.exprlist_) = concat((yyvsp[-2].exprlist_), (yyvsp[-1].exprlist_)); }
#line 1896 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 445 "gram.y" /* yacc.c:1646  */
    { (yyval.expr_) = (yyvsp[-1].expr_); }
#line 1902 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 446 "gram.y" /* yacc.c:1646  */
    { (yyval.expr_) = (yyvsp[-1].expr_); }
#line 1908 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 447 "gram.y" /* yacc.c:1646  */
    { (yyval.expr_) = (yyvsp[-1].expr_); }
#line 1914 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 448 "gram.y" /* yacc.c:1646  */
    { (yyval.expr_) = (yyvsp[-1].expr_); }
#line 1920 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 452 "gram.y" /* yacc.c:1646  */
    { (yyval.expr_) = const_dcl(ident((yyvsp[-2].ustring_)), (yyvsp[-3].expr_), (yyvsp[0].expr_)); }
#line 1926 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 456 "gram.y" /* yacc.c:1646  */
    { (yyval.expr_) = (yyvsp[0].expr_); }
#line 1932 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 457 "gram.y" /* yacc.c:1646  */
    { (yyval.expr_) = boolcon(false); }
#line 1938 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 458 "gram.y" /* yacc.c:1646  */
    { (yyval.expr_) = boolcon(true); }
#line 1944 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 459 "gram.y" /* yacc.c:1646  */
    { (yyval.expr_) = intcon((yyvsp[0].long_)); }
#line 1950 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 460 "gram.y" /* yacc.c:1646  */
    { (yyval.expr_) = charcon((yyvsp[0].long_)); }
#line 1956 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 461 "gram.y" /* yacc.c:1646  */
    { (yyval.expr_) = floatcon((yyvsp[0].double_)); }
#line 1962 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 462 "gram.y" /* yacc.c:1646  */
    { (yyval.expr_) = stringcon((yyvsp[0].string_)); }
#line 1968 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 463 "gram.y" /* yacc.c:1646  */
    { (yyval.expr_) = unary((yyvsp[-1].opcode_), (yyvsp[0].expr_)); }
#line 1974 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 464 "gram.y" /* yacc.c:1646  */
    { (yyval.expr_) = unary((yyvsp[-1].opcode_), (yyvsp[0].expr_)); }
#line 1980 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 465 "gram.y" /* yacc.c:1646  */
    { (yyval.expr_) = binary((yyvsp[-1].opcode_), (yyvsp[-2].expr_), (yyvsp[0].expr_)); }
#line 1986 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 466 "gram.y" /* yacc.c:1646  */
    { (yyval.expr_) = binary((yyvsp[-1].opcode_), (yyvsp[-2].expr_), (yyvsp[0].expr_)); }
#line 1992 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 467 "gram.y" /* yacc.c:1646  */
    { (yyval.expr_) = binary((yyvsp[-1].opcode_), (yyvsp[-2].expr_), (yyvsp[0].expr_)); }
#line 1998 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 468 "gram.y" /* yacc.c:1646  */
    { (yyval.expr_) = binary((yyvsp[-1].opcode_), (yyvsp[-2].expr_), (yyvsp[0].expr_)); }
#line 2004 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 469 "gram.y" /* yacc.c:1646  */
    { (yyval.expr_) = binary((yyvsp[-1].opcode_), (yyvsp[-2].expr_), (yyvsp[0].expr_)); }
#line 2010 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 470 "gram.y" /* yacc.c:1646  */
    { (yyval.expr_) = binary((yyvsp[-1].opcode_), (yyvsp[-2].expr_), (yyvsp[0].expr_)); }
#line 2016 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 471 "gram.y" /* yacc.c:1646  */
    { (yyval.expr_) = binary((yyvsp[-1].opcode_), (yyvsp[-2].expr_), (yyvsp[0].expr_)); }
#line 2022 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 472 "gram.y" /* yacc.c:1646  */
    { (yyval.expr_) = binary((yyvsp[-1].opcode_), (yyvsp[-2].expr_), (yyvsp[0].expr_)); }
#line 2028 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 473 "gram.y" /* yacc.c:1646  */
    { (yyval.expr_) = binary((yyvsp[-1].opcode_), (yyvsp[-2].expr_), (yyvsp[0].expr_)); }
#line 2034 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 474 "gram.y" /* yacc.c:1646  */
    { (yyval.expr_) = binary((yyvsp[-1].opcode_), (yyvsp[-2].expr_), (yyvsp[0].expr_)); }
#line 2040 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 475 "gram.y" /* yacc.c:1646  */
    { (yyval.expr_) = unary((yyvsp[-1].opcode_), (yyvsp[0].expr_)); }
#line 2046 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 476 "gram.y" /* yacc.c:1646  */
    { (yyval.expr_) = (yyvsp[-1].expr_); }
#line 2052 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 480 "gram.y" /* yacc.c:1646  */
    { (yyval.expr_) = typedef_decl((yyvsp[-1].expr_), (yyvsp[0].exprlist_)); }
#line 2058 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 481 "gram.y" /* yacc.c:1646  */
    { (yyval.expr_) = (yyvsp[0].expr_); }
#line 2064 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 482 "gram.y" /* yacc.c:1646  */
    { (yyval.expr_) = (yyvsp[0].expr_); }
#line 2070 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 483 "gram.y" /* yacc.c:1646  */
    { (yyval.expr_) = (yyvsp[0].expr_); }
#line 2076 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 487 "gram.y" /* yacc.c:1646  */
    { (yyval.expr_) = (yyvsp[0].expr_); }
#line 2082 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 488 "gram.y" /* yacc.c:1646  */
    { (yyval.expr_) = (yyvsp[0].expr_); }
#line 2088 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 492 "gram.y" /* yacc.c:1646  */
    { (yyval.expr_) = (yyvsp[0].expr_); }
#line 2094 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 493 "gram.y" /* yacc.c:1646  */
    { (yyval.expr_) = unsigned_type((yyvsp[0].expr_)); }
#line 2100 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 494 "gram.y" /* yacc.c:1646  */
    { (yyval.expr_) = long_type(); }
#line 2106 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 495 "gram.y" /* yacc.c:1646  */
    { (yyval.expr_) = ulong_type(); }
#line 2112 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 496 "gram.y" /* yacc.c:1646  */
    { (yyval.expr_) = long_long_type(); }
#line 2118 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 497 "gram.y" /* yacc.c:1646  */
    { (yyval.expr_) = ulong_long_type(); }
#line 2124 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 498 "gram.y" /* yacc.c:1646  */
    { (yyval.expr_) = (yyvsp[0].expr_); }
#line 2130 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 502 "gram.y" /* yacc.c:1646  */
    { (yyval.expr_) = (yyvsp[0].expr_); }
#line 2136 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 503 "gram.y" /* yacc.c:1646  */
    { (yyval.expr_) = (yyvsp[0].expr_); }
#line 2142 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 507 "gram.y" /* yacc.c:1646  */
    { (yyval.expr_) = (yyvsp[0].expr_); }
#line 2148 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 508 "gram.y" /* yacc.c:1646  */
    { (yyval.expr_) = (yyvsp[0].expr_); }
#line 2154 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 509 "gram.y" /* yacc.c:1646  */
    { (yyval.expr_) = (yyvsp[0].expr_); }
#line 2160 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 513 "gram.y" /* yacc.c:1646  */
    { (yyval.exprlist_) = declarator_list((yyvsp[0].expr_)); }
#line 2166 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 514 "gram.y" /* yacc.c:1646  */
    { (yyval.exprlist_) = append((yyvsp[-2].exprlist_), (yyvsp[0].expr_)); }
#line 2172 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 518 "gram.y" /* yacc.c:1646  */
    { (yyval.expr_) = declarator(ident((yyvsp[-1].ustring_)), (yyvsp[0].exprlist_)); }
#line 2178 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 522 "gram.y" /* yacc.c:1646  */
    { (yyval.exprlist_) = nil; }
#line 2184 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 523 "gram.y" /* yacc.c:1646  */
    { (yyval.exprlist_) = append((yyvsp[-3].exprlist_), (yyvsp[-1].expr_)); }
#line 2190 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 527 "gram.y" /* yacc.c:1646  */
    { (yyval.expr_) = struct_type(ident((yyvsp[-3].ustring_)), (yyvsp[-1].exprlist_)); }
#line 2196 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 531 "gram.y" /* yacc.c:1646  */
    { (yyval.exprlist_) = nil; }
#line 2202 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 532 "gram.y" /* yacc.c:1646  */
    { (yyval.exprlist_) = append((yyvsp[-1].exprlist_), (yyvsp[0].expr_)); }
#line 2208 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 536 "gram.y" /* yacc.c:1646  */
    { (yyval.expr_) = struct_member((yyvsp[-2].expr_), (yyvsp[-1].exprlist_)); }
#line 2214 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 542 "gram.y" /* yacc.c:1646  */
    { (yyval.expr_) = union_type(ident((yyvsp[-7].ustring_)), (yyvsp[-4].expr_), (yyvsp[-1].caselist_)); }
#line 2220 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 546 "gram.y" /* yacc.c:1646  */
    { (yyval.expr_) = (yyvsp[0].expr_); }
#line 2226 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 547 "gram.y" /* yacc.c:1646  */
    { (yyval.expr_) = (yyvsp[0].expr_); }
#line 2232 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 548 "gram.y" /* yacc.c:1646  */
    { (yyval.expr_) = long_type(); }
#line 2238 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 549 "gram.y" /* yacc.c:1646  */
    { (yyval.expr_) = ulong_type(); }
#line 2244 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 550 "gram.y" /* yacc.c:1646  */
    { (yyval.expr_) = unsigned_type((yyvsp[0].expr_)); }
#line 2250 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 551 "gram.y" /* yacc.c:1646  */
    { (yyval.expr_) = long_long_type(); }
#line 2256 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 552 "gram.y" /* yacc.c:1646  */
    { (yyval.expr_) = ulong_long_type(); }
#line 2262 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 556 "gram.y" /* yacc.c:1646  */
    { (yyval.caselist_) = case_list((yyvsp[0].case_)); }
#line 2268 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 557 "gram.y" /* yacc.c:1646  */
    { (yyval.caselist_) = case_append((yyvsp[-1].caselist_), (yyvsp[0].case_)); }
#line 2274 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 561 "gram.y" /* yacc.c:1646  */
    { (yyval.case_) = case_element((yyvsp[-2].exprlist_), (yyvsp[-1].umember_)); }
#line 2280 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 565 "gram.y" /* yacc.c:1646  */
    { (yyval.exprlist_) = case_label_list((yyvsp[0].expr_)); }
#line 2286 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 566 "gram.y" /* yacc.c:1646  */
    { (yyval.exprlist_) = append((yyvsp[-1].exprlist_), (yyvsp[0].expr_)); }
#line 2292 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 570 "gram.y" /* yacc.c:1646  */
    { (yyval.expr_) = case_label((yyvsp[-1].expr_)); }
#line 2298 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 571 "gram.y" /* yacc.c:1646  */
    { (yyval.expr_) = default_label(); }
#line 2304 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 575 "gram.y" /* yacc.c:1646  */
    { (yyval.umember_) = union_member((yyvsp[-1].expr_), (yyvsp[0].expr_)); }
#line 2310 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 579 "gram.y" /* yacc.c:1646  */
    { (yyval.expr_) = enum_type(ident((yyvsp[-3].ustring_)), (yyvsp[-1].exprlist_)); }
#line 2316 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 583 "gram.y" /* yacc.c:1646  */
    { (yyval.exprlist_) = append(nil, enumerator((yyvsp[0].ustring_))); }
#line 2322 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 584 "gram.y" /* yacc.c:1646  */
    { (yyval.exprlist_) = append((yyvsp[-2].exprlist_), enumerator((yyvsp[0].ustring_))); }
#line 2328 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 589 "gram.y" /* yacc.c:1646  */
    { (yyval.expr_) = sequence_type((yyvsp[-2].expr_), (yyvsp[-1].expr_)); }
#line 2334 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 593 "gram.y" /* yacc.c:1646  */
    { (yyval.expr_) = nil; }
#line 2340 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 594 "gram.y" /* yacc.c:1646  */
    { (yyval.expr_) = (yyvsp[0].expr_); }
#line 2346 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 598 "gram.y" /* yacc.c:1646  */
    { (yyval.expr_) = string_type((yyvsp[0].expr_)); }
#line 2352 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 602 "gram.y" /* yacc.c:1646  */
    { (yyval.expr_) = nil; }
#line 2358 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 603 "gram.y" /* yacc.c:1646  */
    { (yyval.expr_) = (yyvsp[-1].expr_); }
#line 2364 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 608 "gram.y" /* yacc.c:1646  */
    { (yyval.exprlist_) = attr_dcl((yyvsp[-3].boolean_), (yyvsp[-1].expr_), (yyvsp[0].exprlist_)); }
#line 2370 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 612 "gram.y" /* yacc.c:1646  */
    { (yyval.boolean_) = false; }
#line 2376 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 613 "gram.y" /* yacc.c:1646  */
    { (yyval.boolean_) = true; }
#line 2382 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 617 "gram.y" /* yacc.c:1646  */
    { (yyval.expr_) = except_dcl(ident((yyvsp[-3].ustring_)), (yyvsp[-1].exprlist_)); }
#line 2388 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 623 "gram.y" /* yacc.c:1646  */
    { (yyval.expr_) = op((yyvsp[-7].exprlist_), (yyvsp[-6].expr_), (yyvsp[-5].ustring_), (yyvsp[-3].exprlist_), (yyvsp[-1].exprlist_), (yyvsp[0].exprlist_)); }
#line 2394 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 627 "gram.y" /* yacc.c:1646  */
    { (yyval.exprlist_) = nil; }
#line 2400 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 628 "gram.y" /* yacc.c:1646  */
    { (yyval.exprlist_) = append(nil, intcon(ONEWAY)); }
#line 2406 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 632 "gram.y" /* yacc.c:1646  */
    { (yyval.exprlist_) = nil; }
#line 2412 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 633 "gram.y" /* yacc.c:1646  */
    { (yyval.exprlist_) = (yyvsp[0].exprlist_); }
#line 2418 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 637 "gram.y" /* yacc.c:1646  */
    { (yyval.exprlist_) = param_list((yyvsp[0].expr_)); }
#line 2424 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 638 "gram.y" /* yacc.c:1646  */
    { (yyval.exprlist_) = append((yyvsp[-2].exprlist_), (yyvsp[0].expr_)); }
#line 2430 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 647 "gram.y" /* yacc.c:1646  */
    { (yyval.expr_) = param((yyvsp[-3].param_), (yyvsp[-2].expr_), ident((yyvsp[-1].ustring_)), (yyvsp[0].exprlist_)); }
#line 2436 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 648 "gram.y" /* yacc.c:1646  */
    { (yyval.expr_) = param((yyvsp[-1].param_), (yyvsp[0].expr_), nil, nil); }
#line 2442 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 652 "gram.y" /* yacc.c:1646  */
    { (yyval.param_) = ExprKit::err_param; }
#line 2448 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 653 "gram.y" /* yacc.c:1646  */
    { (yyval.param_) = ExprKit::in_param; }
#line 2454 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 654 "gram.y" /* yacc.c:1646  */
    { (yyval.param_) = ExprKit::out_param; }
#line 2460 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 655 "gram.y" /* yacc.c:1646  */
    { (yyval.param_) = ExprKit::inout_param; }
#line 2466 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 659 "gram.y" /* yacc.c:1646  */
    { (yyval.exprlist_) = nil; }
#line 2472 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 660 "gram.y" /* yacc.c:1646  */
    { (yyval.exprlist_) = (yyvsp[-1].exprlist_); }
#line 2478 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 664 "gram.y" /* yacc.c:1646  */
    { (yyval.exprlist_) = nil; }
#line 2484 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 665 "gram.y" /* yacc.c:1646  */
    { (yyval.exprlist_) = (yyvsp[-1].exprlist_); }
#line 2490 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 669 "gram.y" /* yacc.c:1646  */
    { (yyval.exprlist_) = string_list(stringcon((yyvsp[0].string_))); }
#line 2496 "gram.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 670 "gram.y" /* yacc.c:1646  */
    { (yyval.exprlist_) = append((yyvsp[-2].exprlist_), stringcon((yyvsp[0].string_))); }
#line 2502 "gram.tab.c" /* yacc.c:1646  */
    break;


#line 2506 "gram.tab.c" /* yacc.c:1646  */
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
