//Makefile
wcomp:main.o strict.o pattern.o fuzzy.o 
	gcc main.o strict.o pattern.o fuzzy.o -o wcomp

main.o: main.c strict.h pattern.h fuzzy.h 
	gcc main.c -c
strict.o:strict.c strict.h
	gcc strict.c -c
pattern.o: pattern.c pattern.h
	gcc pattern.c -c
fuzzy.o: fuzzy.c fuzzy.h
	gcc fuzzy.c -c
