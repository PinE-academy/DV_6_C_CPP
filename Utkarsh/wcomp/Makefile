wcomp:main.o strict.o fuzzy.o pattern.o linklist.o
	gcc main.o strict.o fuzzy.o pattern.o linklist.o -o wcomp

main.o: main.c strict.h fuzzy.h pattern.h linklist.h
	gcc main.c -c
strict.o:strict.c strict.h linklist.h
	gcc strict.c -c
fuzzy.o: fuzzy.c fuzzy.h linklist.h
	gcc fuzzy.c -c
pattern.o: pattern.c pattern.h linklist.h
	gcc pattern.c -c
linklist.o : linklist.c linklist.h
	gcc linklist.c -c