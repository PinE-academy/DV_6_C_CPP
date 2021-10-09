#To run this file:Type "make" in current directory of this file in CLI.
#p_strings.h will be use to link main.c modules with p_strings.c
demo: p_strings.o main.o p_strings.h
	gcc p_strings.o main.o -o demo

p_strings.o: p_strings.c
	gcc -c p_strings.c p_strings.h

main.o: main.c p_strings.h
	gcc -c main.c

clean:
	rm -rf *.o
