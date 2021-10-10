demo: p_strings.o main.o p_strings.h
	gcc p_strings.o main.o -o demo

p_strings.o: p_string.c 
	gcc -c p_strings.c p_strings.h

main.o: main.c p_strings.h
	gcc -c main.c 

main.o: main.c p_strings.h
	gcc -c main.c

clean:
	rm -rf *.o 
	rm -rf *.exe