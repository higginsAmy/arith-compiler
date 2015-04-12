#include <stdio.h>
#include <string.h>
#include "tests.h"

int main(int argc, char **argv){
  unit_tests();
  integration_test();
  return 0;
}

void unit_tests(){
  printf("\nTesting SymTab...\n");
  symTab_tests();
  printf("\nTesting IOMngr...\n");
  ioMngr_tests();
}

void symTab_tests(){
  if (0 == test_CreateDestroySymTab()){
    printf("1........Passed!\n");
  }
  else{
    printf("test_CreateDestroySymTab Failed!\n");
  }
  if (0 == test_EnterName()){
    printf("2........Passed!\n");
  }
  else{
    printf("test_EnterName Failed!\n");
  }
  if (0 == test_FindName()){
    printf("3........Passed!\n");
  }
  else{
    printf("test_FindName Failed!\n");
  }
  if (0 == test_SetGetAttr()){
    printf("4........Passed!\n");
  }
  else{
    printf("test_SetGetAttr Failed!\n");
  }
  if (0 == test_GetName()){
    printf("5........Passed!\n");
  }
  else{
    printf("test_GetName Failed!\n");
  }
  if (0 == test_FirstEntry()){
    printf("6........Passed!\n");
  }
  else{
    printf("test_FirstEntry Failed!\n");
  }
  if (0 == test_NextEntry()){
    printf("7........Passed!\n");
  }
  else{
    printf("test_NextEntry Failed!\n");
  }  
}

void ioMngr_tests(){
  if (0 == test_OpenCloseFile()){
    printf("1........Passed!\n");
  }
  else {
    printf("test_OpenCloseFile Failed!\n");
  }
  if (0 == test_GetSourceChar()){
    printf("2........Passed!\n");
  }
  else {
    printf("test_GetSourceChar Failed!\n");
  }
  if (0 == test_WriteIndicator()){
    printf("3........Passed!\n");
  }
  else {
    printf("test_WriteIndicator Failed!\n");
  }
  if (0 == test_WriteMessage()){
      printf("4........Passed!\n");
  }
  else {
    printf("test_WriteMessage Failed!\n");
  }
  if (0 == test_GetCurrentLine()){
    printf("5........Passed!\n");
  }
  else {
    printf("test_GetCurrentLine Failed!\n");
  }
  if (0 == test_GetCurrentColumn()){
    printf("6........Passed!\n");
  }
  else {
    printf("test_GetCurrentColumn Failed!\n");
  }
}

void integration_test(){
  struct SymTab *table = NULL;
  const char *fname = "integtestfile.txt";
  const char *outname = "integout.txt";
  
  table = CreateSymTab(23);
  if (true == OpenFiles(fname, outname)){
    printf("integration test Passed!\n");
  }

  // cleanup
  DestroySymTab(table);
  CloseFiles();
}

int test_CreateDestroySymTab(){
  struct SymTab *table = NULL;
  struct SymTab *table2 = NULL;
  
  table = CreateSymTab(7);
  table2 = CreateSymTab(28);
  if (NULL == table){
    return -1;
  }
  if (NULL == table2){
    return -1;
  }
  DestroySymTab(table);
  DestroySymTab(table2);
  //if (NULL != table){
  //return -1;
  //}
  
  return 0;
}

int test_EnterName(){
  struct SymTab *table = NULL;
  struct SymEntry *entry = NULL;
  const char *name = "Amy";

  table = CreateSymTab(7);
  if (false == EnterName(table, name, &entry)){
    return -1;
  }
  if (0 != strcmp(name, GetName(entry))){
    return -1;
  }
  //print_SymTab(table);
  if (true == EnterName(table, name, &entry)){
    return -1;
  }
  if (false == EnterName(table, "James", &entry)){
    return -1;
  }
  if (false == EnterName(table, "Frank", &entry)){
    return -1;
  }
  if (false == EnterName(table, "Oliver", &entry)){
    return -1;
  }
  
  //print_SymTab(table);
  DestroySymTab(table);
  
  return 0;
}

int test_FindName(){
  struct SymTab *table = NULL;
  struct SymEntry *entry = NULL;
  const char *name = "Amy";

  table = CreateSymTab(3);
  if (false == EnterName(table, name, &entry)){
    return -1;
  }
  //printf("Item Successfully entered.\n");
  //print_SymTab(table);
  if (entry != FindName(table, name)){
      return -1;
  }
  //printf("FindName Successfully executed.\n");
  //print_SymTab(table);
  DestroySymTab(table);
  
  return 0;
}

int test_SetGetAttr(){
  struct SymTab *table = NULL;
  struct SymEntry *entry = NULL;
  const char *name = "Amy";
  char * attr;
  
  table = CreateSymTab(17);
  if (false == EnterName(table, name, &entry)){
    return -1;
  }
  //print_SymTab(table);
  SetAttr(entry, "programmer");
  attr = (char *)GetAttr(entry);
  if (0 != strcmp("programmer", attr)){
    return -1;
  }
  //printf("Attribute is %s\n", attr);
  //print_SymTab(table);
  DestroySymTab(table);

  return 0;
}

int test_GetName(){
  struct SymTab *table = NULL;
  struct SymEntry *entry = NULL;
  const char *name = "Amy";

  table = CreateSymTab(21);
  if (false == EnterName(table, name, &entry)){
    return -1;
  }
  if (0 != strcmp(name, GetName(entry))){
    return -1;
  }
  //print_SymTab(table);
  DestroySymTab(table);

  return 0;
}

int test_FirstEntry(){
  struct SymTab *table = NULL;
  struct SymEntry *entry = NULL;
  const char *name = "Amy";

  table = CreateSymTab(6);
  if (false == EnterName(table, name, &entry)){
    return -1;
  }
  if (entry != FirstEntry(table)){
    return -1;
  }
  //print_SymTab(table);
  DestroySymTab(table);

  return 0;
}

int test_NextEntry(){
  struct SymTab *table = NULL;
  struct SymEntry *entry = NULL;
  struct SymEntry *next_entry = NULL;
  const char *name = "Amy";

  table = CreateSymTab(6);
  if (false == EnterName(table, name, &entry)){
    return -1;
  }
  if (false == EnterName(table, "Joe", &next_entry)){
    return -1;
  }
  if (next_entry != NextEntry(table, entry)){
    return -1;
  }
  //print_SymTab(table);
  DestroySymTab(table);

  return 0;
}

void print_SymTab(struct SymTab *table){
  struct SymEntry *entry = NULL;
  int i;

  for (i = 0; i < table->Size; i++){
    printf("[%d] ", i+1);
    entry = table->Contents[i];
    while (NULL != entry){
      printf("%s -> ", entry->Name);
      entry = entry->Next;
    }
    printf("\n");
  }
}

int test_OpenCloseFile(){
  const char *fname = "testfile.txt";
  const char *outname = "out.txt";

  if (false == OpenFiles(fname, outname)){
    return -1;
  }
  CloseFiles();

  if (false == OpenFiles(fname, NULL)){
    return -1;
  }
  CloseFiles();
  
  return 0;
}

int test_GetSourceChar(){
  const char *fname = "testfile.txt";
  char *firstln = "This is a test file that will point out Rs.";
  char *secondln = "There should be 4 erRors.";
  char *thirdln = "Fin.";
  char curr;
  int i;
  
  if (false == OpenFiles(fname, NULL)){
    return -1;
  }
  curr = GetSourceChar();
  //printf("Starting character: %c\n", curr);
  while (EOF != curr){
    for (i = 0; i < strlen(firstln); i++){
      //printf("I is %d.\n", i);
      //printf("firstln[i] is %c.\n", firstln[i]);
      if (curr != firstln[i]){
	//printf("Curr is %c, char at %d is %c.\n", curr, i, firstln[i]);
	printf("First line characters don't match.\n");
	return -1;
      }
      curr = GetSourceChar();
      //printf("Curr is %c.\n", curr);
    }
    for (i = 0; i < strlen(secondln); i++){
      //printf("I is %d.\n", i);
      //printf("secondln[i] is %c.\n", secondln[i]);
      if (curr != secondln[i]){
        //printf("Curr is %c, char at %d is %c.\n", curr, i, secondln[i]);
	printf("Second line characters don't match.\n");
	return -1;
      }
      curr = GetSourceChar();
      //printf("Curr is %c.\n", curr);
    }
    for (i = 0; i < strlen(thirdln); i++){
      //printf("I is %d.\n", i);
      //printf("thirdln[i] is %c.\n", thirdln[i]);
      if (curr != thirdln[i]){
	//printf("Curr is %c, char at %d is %c.\n", curr, i, thirdln[i]);
	printf("Third line characters don't match.\n");
	return -1;
      }
      curr = GetSourceChar();
      //printf("Curr is %c.\n", curr);
    }
    //printf("Curr is not null.\n");
    curr = GetSourceChar();
  }
  CloseFiles();

  return 0;
}

int test_WriteIndicator(){
  const char *fname = "testfile.txt";
  const char *outname = "out.txt";
  char buffer[MAXLINE];
  FILE *fd = NULL;
  int i;
  
  if (false == OpenFiles(fname, outname)){
    return -1;
  }

  WriteIndicator(3);  
  CloseFiles();
  fd = fopen(outname, "r");
  for (i = 0; i < 2; i++){
    if (NULL == fgets(buffer, MAXLINE, fd)){
      return -1;
    }
  }
  if (buffer[3] != '^'){
    printf("Character does not match '^'.\n");
    return -1;
  }
  fclose(fd);
  
  return 0;
}

int test_WriteMessage(){
  const char *fname = "testfile.txt";
  const char *outname = "out.txt";
  const char *msg = "Error Message!";
  char buffer[MAXLINE];
  FILE *fd = NULL;
  int i;
  
  if (false == OpenFiles(fname, outname)){
    return -1;
  }

  WriteMessage(msg);
  CloseFiles();
  fd = fopen(outname, "r");
  if (NULL == fgets(buffer, MAXLINE, fd)){
    return -1;
  }
  for (i = 0; i < strlen(msg); i++){
    if (buffer[i] != msg[i]){
      printf("Message characters don't match.\n");
      return -1;
    }
  }
  fclose(fd);

  return 0;
}

int test_GetCurrentLine(){
  const char *fname = "testfile.txt";
  char *firstln = "This is a test file that will point out Rs.";
  char *secondln = "There should be 4 erRors.";
  char *thirdln = "Fin.";
  char curr;
  int i;

  if (false == OpenFiles(fname, NULL)){
    return -1;
  }
  curr = GetSourceChar();
  
  while (EOF != curr){
    for (i = 0; i < strlen(firstln); i++){
      if (1 != GetCurrentLine()){
	printf("Line is at %d, current line is %d.\n", 1, GetCurrentLine());
	return -1;
      }
      curr = GetSourceChar();
    }
    for (i = 0; i < strlen(secondln); i++){
      if (2 != GetCurrentLine()){
	return -1;
      }
      curr = GetSourceChar();
    }
    for (i = 0; i < strlen(thirdln); i++){
      if (3 != GetCurrentLine()){
	return -1;
      }
      curr = GetSourceChar();
    }
    //printf("Curr is not null.\n");
    curr = GetSourceChar();
  }
  CloseFiles();

  return 0;
}

int test_GetCurrentColumn(){
  const char *fname = "testfile.txt";
  char *firstln = "This is a test file that will point out Rs.";
  char *secondln = "There should be 4 erRors.";
  char *thirdln = "Fin.";
  char curr;
  int i;

  if (false == OpenFiles(fname, NULL)){
    return -1;
  }
  curr = GetSourceChar();

  while (EOF != curr){
    for (i = 0; i < strlen(firstln); i++){
      if (i != GetCurrentColumn()){
	return -1;
      }
      curr = GetSourceChar();
    }
    for (i = 0; i < strlen(secondln); i++){
      if (i != GetCurrentColumn()){
	return -1;
      }
      curr = GetSourceChar();
    }
    for (i = 0; i < strlen(thirdln); i++){
      if (i != GetCurrentColumn()){
	return -1;
      }
      curr = GetSourceChar();
    }
    //printf("Curr is not null.\n");
    curr = GetSourceChar();
  }
  CloseFiles();

  return 0;
}
