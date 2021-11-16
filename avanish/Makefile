demo: main.o glist.o giter.o
	gcc main.o glist.o giter.o -o demo
main.o: main.c
	gcc -c main.c
glist.o: glist.c glist.h
	gcc -c glist.c 
giter.o: giter.c giter.h
	gcc -c giter.c
