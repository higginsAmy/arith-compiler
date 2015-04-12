# Amy Higgins
# SymTab.c Makefile
# CS 442
########################

CC= gcc
CFLAGS=-Wall -g

all: tests

tests: tests.c tests.h SymTab.c SymTab.h IOMngr.c IOMngr.h

	$(CC) -o tests tests.c SymTab.c IOMngr.c $(CFLAGS)

clean:
	$(RM) tests *.o
	$(RM) -rf *.dSYM
	$(RM) Makefile~
	$(RM) SymTab.h~
	$(RM) SymTab.exe.stackdump
	$(RM) tests.exe.stackdump
	$(RM) SymTab.c~
	$(RM) tests.c~
	$(RM) tests.h~
	$(RM) IOMngr.h~
	$(RM) IOMngr.c~
	$(RM) boolExpr.y~
	$(RM) a.exe.stackdump
	$(RM) arithExpr.y~
	$(RM) boolLex.l~
	$(RM) testArith.txt~
	$(RM) arithLex.l~
	$(RM) semantics.c~
	$(RM) semantics.h~
	$(RM) testLex.txt~
