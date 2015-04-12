#include <stdio.h>
#include "SymTab.h"
#include "IOMngr.h"

extern int yyparse();
struct SymTab *table;

int main(int argc, char *argv[]){
  table = CreateSymTab(17);
  
  if (!OpenFiles(argv[1],"listing")){
    printf("open failed\n");
    exit(0);
  }
  
  yyparse();
}
