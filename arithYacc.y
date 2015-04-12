%{
  
  #include "semantics.h"
  #include "IOMngr.h"
  #include <string.h>

  extern int yylex(); /* The next token function */
  extern char *yytext; /* The matched token text.*/
  extern int yyleng;
  extern int yyerror(char*);
  extern struct SymTab *table;
  extern struct SymEntry *entry;
  char *ptr;

  %}

%union {
  int integer;
  char * string;
}

%type <string> Id
%type <integer> Expr
%type <integer> Term
%type <integer> Factor

%token Ident
%token INT
%token ADD
%token MUL

%%

Prog        : StmtSeq            {printSymTab();};
StmtSeq     : Stmt StmtSeq       {};
StmtSeq     :                    {};
Stmt        : Id '=' Expr ';'    {storeVar($1, $3);};
Expr        : Expr ADD Term      {$$ = doADD($1, $3);};
Expr        : Term               {$$ = $1;};
Term        : Term MUL Factor    {$$ = doMUL($1, $3);};
Term        : Factor             {$$ = $1;};
Factor      : '-' Factor         {$$ = doNEG($2);};
Factor      : '(' Expr ')'       {$$ = $2;};
Factor      : Id                 {$$ = getVal($1);};
Factor      : INT                {$$ = (int)strtol(yytext, &ptr, 10);};
Id          : Ident              {$$ = strdup(yytext);};

%%

int yyerror(char *s) {
  WriteIndicator(GetCurrentColumn());
  WriteMessage("Illegal Character in YACC");
  return 1;
}
