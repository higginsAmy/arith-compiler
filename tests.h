// Header file for tests.c
#include "SymTab.h"
#include "IOMngr.h"

// Runs unit tests
void unit_tests();

// Runs integration test
void integration_test();

// Runs SymTab tests
void symTab_tests();

// Runs IOMngr tests
void ioMngr_tests();

// Tests CreateSymTab and DestroySymTab
int test_CreateDestroySymTab();

// Tests EnterName
int test_EnterName();

// Tests FindName
int test_FindName();

// Tests SetAttr and GetAttr
int test_SetGetAttr();

// Tests GetName
int test_GetName();

// Tests FirstEntry
int test_FirstEntry();

//Tests NextEntry
int test_NextEntry();

// Helper Method to print values in a SymTab
void print_SymTab(struct SymTab *table);

// Tests OpenFiles and CloseFiles
int test_OpenCloseFile();

// Tests GetSourceChar
int test_GetSourceChar();

// Tests WriteIndicator
int test_WriteIndicator();

// Tests WriteMessage
int test_WriteMessage();

// Tests GetCurrentLine
int test_GetCurrentLine();

// Tests GetCurrentColumn
int test_GetCurrentColumn();
