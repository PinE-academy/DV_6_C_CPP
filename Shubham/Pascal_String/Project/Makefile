demo: p_strings.o main.o
	gcc p_strings.o main.o -o demo

p_strings.o: p_strings.c p_strings.h
	gcc -c p_strings.c 

main.o: main.c p_strings.h
	gcc -c main.c 

clean:
	rm -rf *.o demo 
	