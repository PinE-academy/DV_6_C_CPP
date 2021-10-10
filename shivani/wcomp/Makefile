//makefile
wcomp : main.o strict.o fuzzy.o pattern.o


gcc main.o strict.o fuzzy.o pattern.o -o output

main.o: main.c strict.h fuzzy.h pattern.h 
	gcc main.c -c
strict.o: strict.c strict.h
	gcc strict.c -c
fuzzy.o : fuzzy.c fuzzy.h
	gcc fuzzy.c -c
pattern.o: pattern.c pattern.h
	gcc pattern.c -c
