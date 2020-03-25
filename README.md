# matf_Kompilacija_programskih_jezika

Neki reseni ispitni zadaci iz kursa Kompilacija programskih jezika na Matematickom fakultetu. U cilju pomoci, ostalim kolegama,radi lakseg pripremanja ispita iz ovog kursa.



Da biste mogli da kompajlirate, najpre morate instalirati Flex i Bison.

Komande za instalaciju na Ubuntu:
		
		$sudo apt-get update
		$sudo apt-get upgrade
		$sudo apt-get install flex bison

Radi lakse kompilacije, potrebno je napraviti Makefile(makefile).
Primer makefile-a:

		PROGRAM = nazivPrograma
		CC = g++
		CFLAGS  = -Wall -pedantic -ansi
		YFLAGS = -d -v
		LEX = flex
		YACC = bison

		$(PROGRAM) : lex.yy.o parser.o klasa1.o klasa2.o
			$(CC) $(CFLAGS) -o $@ $^
		lex.yy.o: lex.yy.c
			$(CC) $(CFLAGS) -c -o $@ $<
		lex.yy.c: lexer.l parser.tab.hpp
			$(LEX) $<
		parser.o: parser.tab.cpp
			$(CC) $(CFLAGS) -c -o $@ $<
		parser.tab.cpp parser.tab.hpp : parser.ypp
			$(YACC) $(YFLAGS) $<
		klasa1.o: klasa1.cpp klasa1.hpp
			$(CC) $(CFLAGS) -c -o $@ $<
		klasa2.o: klasa2.cpp klasa2.hpp
			$(CC) $(CFLAGS) -c -o $@ $<

		.PHONY: clean

		clean:
			-rm -f *~ *.o parser.tab.* *.output lex.* nazivPrograma

Kasnije je dovoljno u terminalu otkucati komandu:
		$make
