#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include"SymTab.h"

extern struct SymTab *table;

void printSymTab(){
  struct SymEntry *entry = FirstEntry(table);
  
  printf("%20s\t%10s\n","Variable","Value");
  while(entry) {
    printf("%20s\t%10d\n",GetName(entry),(int)GetAttr(entry));
    entry = NextEntry(table,entry);
  }
}

void storeVar(char *name, int v){
  struct SymEntry *entry;
  
  EnterName(table, name, &entry);
  SetAttr(entry, (void*)v);
}

int getVal(char *name){
  struct SymEntry *entry = FindName(table,name);
  if (NULL == entry){
    WriteIndicator(GetCurrentColumn());
    WriteMessage("Initialize variable to zero.");
    storeVar(name, 0);
    return 0;
  }
  return (int)GetAttr(entry);
}

int doADD(int v1, int v2){
  return v1 + v2;
}

int doMUL(int v1, int v2){
  return v1 * v2;
}

int doNEG(int v1){
  return v1 * -1;
}
