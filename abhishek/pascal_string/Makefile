demo: p_string.o main.o string.h
	gcc p_string.o main.o -o demo
p_string.o: p_string.c 
	gcc -c p_string.c
main.o: main.c 
	gcc -c main.c 
string.h: main.c
	gcc -c main.c
clean:
	rm -rf *.o demo
	
