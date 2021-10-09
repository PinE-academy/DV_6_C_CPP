demo : main.o p_strings.0
	gcc-11 main.o p_strings.0 -o demo

main.o : main.c p_strings.h
	gcc-11 -c main.c

p_strings.o : p_strings.c
	gcc-11 -c p_strings.c

clean :
	rm -rf *.o
