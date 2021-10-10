demo: p_string.o main.o p_strings.h
	gcc p_string.o main.o -o demo
p_string.o: p_string.c 
	gcc -c p_string.c p_strings.h
main.o: main.c 
	gcc -c main.c 
p_strings.h: main.o
	gcc main.o -o demo
clean:
	rm -rf *.o demo
	
