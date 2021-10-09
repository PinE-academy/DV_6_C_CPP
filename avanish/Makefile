demo: main.o glist.o giter.o
	gcc main.o glist.o giter.o -o demo
main.o: main.c
	gcc -c main.c
glist.o: glist.c
	gcc -c glist.c
giter.o: giter.c
	gcc -c giter.c
# rm -rf means forcefully remove
rm - rf *.o demo
