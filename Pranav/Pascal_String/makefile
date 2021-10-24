demo : main.o p_strings.o
	gcc main.o p_strings.o -o demo

main.o : main.c p_strings.h
	gcc -c main.c

p_strings.o : p_strings.c p_strings.h
	gcc -c p_strings.c

clean :
	rm -rf *.o demo
