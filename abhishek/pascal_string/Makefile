demo: p_string.o main.o p_strings.h
	gcc p_strings.o main.o -o demo
p_string.o: p_strings.c p_strings.h
	gcc -c p_strings.c 
main.o: main.c p_strings.h
	gcc -c main.c 
clean:
	rm -rf *.o demo
	
